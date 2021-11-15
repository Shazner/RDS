/**
 * @file main.cpp
 * @brief main file for the program
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

#include "Activity_log.hpp"
#include "Time_entry.hpp"
#include "Radio.hpp"
#include "Person.hpp"
#include "Utility.hpp"
#include "Manage.hpp"

const std::string WELCOME_MESSAGE =
    "\033[1;34m***********************************************\033[0m\n"
    "                 Welcome to the                \n"
    "           Radio Deployment System             \n"
    "\033[1;34m***********************************************\033[0m\n";

const std::string MAIN_OPTIONS_PROMPT =
    "Pick from the following options:\n"
    "(1) Log check-in/out, (2) Managment, (3) Export csv, (4) Quit\n";

enum MAIN_OPTIONS { INIT = 1, LOG_ENTRY = INIT, MANAGMENT, EXPORT_CSV, QUIT };

static void log_entry();
static void export_csv();
static void managment();

static RDS::Activity_log ac_log;
static std::vector<RDS::Radio> radios;
static std::vector<RDS::Person> people;
static std::string incident_name;

int main() {
    std::cout << WELCOME_MESSAGE;
    std::cout << MAIN_OPTIONS_PROMPT;

    radios.push_back(RDS::Radio("123A", "P25"));
    people.push_back(RDS::Person("John", "Doe", "N/A", "DNK"));
    MAIN_OPTIONS main_option =
        static_cast<MAIN_OPTIONS>(RDS::UTILITY::get_int());
    while (main_option != QUIT) {
        switch (main_option) {
            case LOG_ENTRY:
                log_entry();
                break;
            case MANAGMENT:
                managment();
                break;
            case EXPORT_CSV:
                export_csv();
                break;
            default:
                break;
        }
        std::cout << MAIN_OPTIONS_PROMPT;
        main_option = static_cast<MAIN_OPTIONS>(RDS::UTILITY::get_int());
    }
    return 0;
}

static void log_entry() {
    std::cout << "First let's select the radio" << std::endl;
    const auto [status_radio, radio] = RDS::UTILITY::select(radios);
    if (!status_radio) {
        std::cout << "Failed to find a valid radio." << std::endl;
        return;
    }
    std::cout << "Next who's radio is this?" << std::endl;
    auto [status_person, person] = RDS::UTILITY::select(people);
    if (!status_person) {
        std::cout << "Failed to find a valid person." << std::endl;
        return;
    }

    auto radio_obj = std::find(radios.begin(), radios.end(), radio);

    if (radio_obj->get_status() == RDS::RADIO_STATUS::CHECKED_OUT) {
        radio_obj->checkin();
        std::cout << "Radio " << radio_obj->get_id() << " has been checked in."
                  << std::endl;
    } else {
        radio_obj->checkout();
        std::cout << "Radio " << radio_obj->get_id()
                  << " has been checked out to " << person.get_first_name()
                  << std::endl;
    }
    ac_log.add(RDS::Time_entry(*radio_obj, person));
}

static void export_csv() {
    auto clear_cin = []() {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    };
    if (incident_name.empty()) {
        clear_cin();
        std::cout << "What is the incident name: ";
        getline(std::cin, incident_name);
    } else {
        clear_cin();
        std::cout << "Change the incident name? (1)yes or (0)no: ";
        const int change = RDS::UTILITY::get_int();
        if (change == 1) {
            std::cout << "What is the incident name: ";
            getline(std::cin, incident_name);
        }
    }
    try {
        ac_log.write_csv(incident_name);
        std::cout << "Wrote to the csv." << std::endl;
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}

static void managment() {
    enum OPTIONS { RADIOS = 1, PEOPLE, BACK = 0 };
    std::cout << "What would you like to manage?" << std::endl;
    std::cout << "(1) Radios, (2) People, (0/any number) Back" << std::endl;
    OPTIONS selction = static_cast<OPTIONS>(RDS::UTILITY::get_int());
    switch (selction) {
        case RADIOS:
            Manage(radios);
            break;
        case PEOPLE:
            Manage(people);
            break;
        case BACK:
            [[fallthrough]];
        default:
            return;
    }
}