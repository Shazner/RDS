/**
 * @file Time_entry.cpp
 * @brief Implementations for the Time_entry
 */

#include "Time_entry.hpp"

namespace RDS {
Time_entry::Time_entry(Radio radio, Person person)
    : Radio(radio), Person(person) {
    if (get_status() == RADIO_STATUS::CHECKED_OUT) {
        activity = ACTIVITY::CHECK_OUT;
    } else {
        activity = ACTIVITY::CHECK_IN;
    }
    entry_time = time(NULL);
}
}  // namespace RDS