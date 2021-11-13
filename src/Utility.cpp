/**
 * @file Utility.cpp
 * @brief Implementations for Utility Functions
 */

#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <functional>

#include "Utility.hpp"
#include "Radio.hpp"
#include "Person.hpp"

/// Static Functions
static int get_int();
static void print_item_one_line(const RDS::Radio& radio);
static RDS::Radio get_default(const RDS::Radio&);
static RDS::Person get_default(const RDS::Person&);

/// Prompts
const std::string RADIO_OPTIONS_PROMPT =
    "How would you like to choose a radio: \n"
    "1) Radio ID\n"
    "2) Radio Type\n"
    "Selection: ";

/// Constants
static const RDS::Radio DEFAULT_RADIO("", "");
static const RDS::Person DEFAULT_PERSON("", "", "", "", "");

/// Template Functions
template <typename T>
T select_from_matches(std::vector<T> matches) {
    using namespace std;
    const std::string SELCTION_PROMPT =
        "Were any of these it? Enter the number or 0 for more options \n"
        "Selection: ";

    cout << "There were multiple options so lets pick" << endl;
    int total_printed = 0;
    int i = 1;
    for (const auto& match : matches) {
        cout << i << ") ";
        print_item_one_line(match);
        total_printed++;
        if (i == 5) {
            cout << SELCTION_PROMPT;
            const auto selection = get_int();
            if (selection > 0 && selection <= 5) {
                return matches[total_printed - i + selection - 1];
            }
            i = 1;
        } else {
            i++;
        }
    }
    if (i != 1) {
        cout << "That was the last of them." << endl
             << "Were any of these it? Enter the number or 0 try your search "
                "again\n"
             << "Selection: ";
        const auto selection = get_int();
        if (selection > 0 && selection <= i - 1) {
            return matches[total_printed - i + selection];
        }
    }
    return get_default(matches[0]);
}

namespace RDS {
namespace UTILITY {
[[nodiscard]] std::pair<bool, Radio> select(const std::vector<Radio>& radios) {
    using namespace std;
    /// Memory Constants
    enum OPTIONS { ID = 1, TYPE, INVALID };
    const auto option_invalid = [](OPTIONS option) {
        return ((option < 0) || (option >= INVALID));
    };

    OPTIONS option = INVALID;
    while (option_invalid(option)) {
        cout << RADIO_OPTIONS_PROMPT;
        option = static_cast<OPTIONS>(get_int());
        if (option_invalid(option)) {
            cout << endl << "!! INVALID try again !!" << endl;
        }
    }

    bool exit = false;
    while (exit != true) {
        std::function<bool(RDS::Radio)> matcher;
        switch (option) {
            case ID: {
                std::string search_id;
                cout << "Enter the ID: ";
                cin >> search_id;
                matcher = [search_id](RDS::Radio radio) {
                    std::string id = radio.get_id();
                    if (id.find(search_id) != std::string::npos)
                        return true;
                    else
                        return false;
                };
                break;
            }
            case TYPE: {
                std::string search_type;
                cout << "Enter the Type: ";
                cin >> search_type;
                matcher = [search_type](RDS::Radio radio) {
                    std::string id = radio.get_type();
                    if (id.find(search_type) != std::string::npos)
                        return true;
                    else
                        return false;
                };
                break;
            }
            case INVALID: {
                matcher = []([[maybe_unused]] RDS::Radio radio) {
                    return false;
                };
                break;
            }
        }
        const std::vector<Radio> matches = find_if(radios, matcher);
        if (auto number_of_matches = matches.size(); number_of_matches == 0) {
            cout << endl
                 << "No match found." << endl
                 << "Enter 1 to try again or 0 to go back" << endl
                 << "Selection: ";
            if (get_int() != 1) {
                return make_pair(false, DEFAULT_RADIO);
            }
        } else if (number_of_matches == 1) {
            return make_pair(true, matches[0]);
        } else {
            const RDS::Radio radio_selected = select_from_matches(matches);
            if (!(radio_selected == DEFAULT_RADIO)) {
                return make_pair(true, radio_selected);
            } else {
                cout << endl
                     << "No match found." << endl
                     << "Enter 1 to try again or 0 to go back" << endl
                     << "Selection: ";
                if (get_int() != 1) {
                    return make_pair(false, DEFAULT_RADIO);
                }
            }
        }
    }
    return make_pair(false, DEFAULT_RADIO);
}

[[nodiscard]] std::pair<bool, Person> select(
    const std::vector<Person>& people) {
    return std::make_pair(false, get_default(people[0]));
}
}  // namespace UTILITY
}  // namespace RDS

static int get_int() {
    using namespace std;
    int input = 0;
    cin >> input;
    while (!cin) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "ERROR" << endl << "Try again: ";
        cin >> input;
    }
    return input;
}

static void print_item_one_line(const RDS::Radio& radio) {
    using namespace std;
    cout << "ID: " << radio.get_id() << ", Type: " << radio.get_type() << endl;
}

static RDS::Radio get_default(const RDS::Radio&) {
    return DEFAULT_RADIO;
}

static RDS::Person get_default(const RDS::Person&) {
    return DEFAULT_PERSON;
}