/**
 * @file Time_entry.hpp
 * @brief Time entry abstraction
 */
#ifndef TIME_ENTRY_HPP
#define TIME_ENTRY_HPP

#include <ctime>

#include "Radio.hpp"
#include "Person.hpp"

namespace RDS {
enum class ACTIVITY { CHECK_IN, CHECK_OUT };
class Time_entry : public Radio, Person {
   private:
    time_t entry_time;
    ACTIVITY activity;

   public:
    Time_entry(Radio radio, Person person);
};
}  // namespace RDS
#endif  // TIME_ENTRY_HPP