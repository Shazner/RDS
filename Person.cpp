/**
 * @file Person.cpp
 * @brief Implementations for the Person Class
 */

#include "Person.hpp"

namespace RDS {
std::string Person::get_first_name(void) const {
    return first_name;
}

std::string Person::get_last_name(void) const {
    return last_name;
}

std::string Person::get_agency(void) const {
    return agency;
}

std::string Person::get_position(void) const {
    return position;
}

bool Person::is_active(void) const {
    return active;
}

void Person::set_agency(std::string new_agency) {
    agency = new_agency;
}

void Person::set_position(std::string new_position) {
    position = new_position;
}

void Person::activate(void) {
    active = true;
}

void Person::deactivate(void) {
    active = false;
}
}  // namespace RDS