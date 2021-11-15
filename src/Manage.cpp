/**
 * @file Manage.cpp
 * @brief Implementations for the Manage UX
 */

#include <iostream>
#include <algorithm>
#include <climits>

#include "Manage.hpp"
#include "Utility.hpp"

static void clear_cin();

namespace RDS {
enum MANAGE_MODE { ADD = 1, DELETE, EDIT, ACTIVATE, DEACTIVATE, RETURN };
enum STATUS { INACTIVE = 0, ACTIVE = 1 };
template <typename T>
void Manage_UX(std::vector<T>& items) {
    std::cout << "Select an action (ADD=1, DELETE=2, EDIT=3, ACTIVATE=4, "
                 "DEACTIVATE=5 RETURN=6): ";
    const MANAGE_MODE mode = static_cast<MANAGE_MODE>(UTILITY::get_int());
    switch (mode) {
        case ADD: {
            add(items);
            return;
        }
        case DELETE: {
            remove(items);
            return;
        }
        case EDIT: {
            edit(items);
            return;
        }
        case ACTIVATE: {
            activation(items, ACTIVE);
            return;
        }
        case DEACTIVATE: {
            activation(items, INACTIVE);
            return;
        }
        case RETURN: {
            return;
        }
        default: {
            std::cout << "ERROR: INVALID INPUT" << std::endl;
            return;
        }
    }
}

template <typename T>
void activation(std::vector<T>& items, bool status) {
    const auto [found, item] = UTILITY::select(items);
    if (found == false) {
        std::cout << "Search Failed, Returning to Menu" << std::endl;
        return;
    }
    auto index = std::find(items.begin(), items.end(), item);
    switch (status) {
        case INACTIVE: {
            index->deactivate();
            break;
        }
        case ACTIVE: {
            index->activate();
            break;
        }
    }
    return;
}

template <typename T>
void remove(std::vector<T>& items) {
    const auto [found, item] = UTILITY::select(items);
    if (found == 0) {
        std::cout << "Search Failed, Returning to Menu" << std::endl;
        return;
    }
    auto index = std::find(items.begin(), items.end(), item);
    std::cout << "Removing: " << item << std::endl;
    items.erase(index);
}

void add(std::vector<Radio>& radios) {
    std::string radio_id;
    std::string radio_type;

    std::cout << "Adding a radio..." << std::endl;
    std::cout << "Radio ID: ";
    clear_cin();
    std::getline(std::cin, radio_id);
    std::cout << "Radio Type: ";
    std::getline(std::cin, radio_type);

    radios.push_back(Radio(radio_id, radio_type));
}

void add(std::vector<Person>& people) {
    std::string first_name;
    std::string last_name;
    std::string agency;
    std::string position;

    std::cout << "Adding a person..." << std::endl;
    std::cout << "First Name: ";
    clear_cin();
    std::getline(std::cin, first_name);
    std::cout << "Last Name: ";
    std::getline(std::cin, last_name);
    std::cout << "Agency: ";
    std::getline(std::cin, agency);
    std::cout << "Position: ";
    std::getline(std::cin, position);

    people.push_back(Person(first_name, last_name, agency, position));
}

void edit(std::vector<Radio>& radios) {
    enum EDIT_MODE { ADD = 1, CLEAR, EDIT };
    const auto [found, radio] = UTILITY::select(radios);
    if (found == false) {
        std::cout << "Search Failed, Returning to Menu" << std::endl;
        return;
    }
    auto index = std::find(radios.begin(), radios.end(), radio);

    std::cout << "You are editing: " << std::endl << radio;

    std::cout
        << "Append a new note = 1, Clear the notes = 2, or Edit the notes = 3"
        << std::endl;
    const EDIT_MODE mode = static_cast<EDIT_MODE>(UTILITY::get_int());

    switch (mode) {
        case ADD: {
            std::cout << "Type your note now then a newline to finish the note."
                      << std::endl;
            std::string note;
            clear_cin();
            std::getline(std::cin, note);
            index->add_note(note);
            break;
        }
        case CLEAR: {
            index->clear_notes();
            break;
        }
        case EDIT: {
            index->edit_notes();
            break;
        }
        default: {
            std::cout << "ERROR: INVALID INPUT" << std::endl;
            break;
        }
    }
    return;
}

void edit(std::vector<Person>& people) {
    enum EDIT_MODE { AGENCY = 1, POSITION };
    const auto [found, person] = UTILITY::select(people);
    if (found == false) {
        std::cout << "Search Failed, Returning to Menu" << std::endl;
        return;
    }
    auto index = std::find(people.begin(), people.end(), person);

    std::cout << "You are editing: " << std::endl << person;

    std::cout << "Set the agency = 1, Set the position = 2" << std::endl;
    const EDIT_MODE mode = static_cast<EDIT_MODE>(UTILITY::get_int());

    switch (mode) {
        case AGENCY: {
            std::cout << "Enter the agency: ";
            std::string agency;
            std::cin >> agency;
            index->set_agency(agency);
            break;
        }
        case POSITION: {
            std::cout << "Enter the position: ";
            std::string position;
            clear_cin();
            std::getline(std::cin, position);
            index->set_position(position);
            break;
        }
        default: {
            std::cout << "ERROR: INVALID INPUT" << std::endl;
            break;
        }
    }
    return;
}

void Manage(std::vector<Radio>& radios) {
    Manage_UX(radios);
}
void Manage(std::vector<Person>& people) {
    Manage_UX(people);
}
}  // namespace RDS

static void clear_cin() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}