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

time_t Time_entry::get_time() const {
    return entry_time;
}

ACTIVITY Time_entry::get_activity() const {
    return activity;
}

std::ostream& operator<<(std::ostream& out, const ACTIVITY activity) {
    switch (activity) {
        case ACTIVITY::CHECK_IN:
            out << "Check in";
            break;
        case ACTIVITY::CHECK_OUT:
            out << "Check out";
            break;
    }
    return out;
}

}  // namespace RDS