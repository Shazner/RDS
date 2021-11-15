/**
 * @file Manage.hpp
 * @brief Management ux abstraction
 */
#ifndef MANAGE_HPP
#define MANAGE_HPP

#include <vector>
#include "Radio.hpp"
#include "Person.hpp"

namespace RDS {
void Manage(std::vector<RDS::Radio>& radios);
void Manage(std::vector<RDS::Person>& people);
}  // namespace RDS
#endif  // TIME_ENTRY_HPP