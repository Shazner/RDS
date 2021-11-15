/**
 * @file Activity_log.cpp
 * @brief Implementations for the Activity Log Class
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Activity_log.hpp"

namespace RDS {
Activity_log::~Activity_log() {
    std::cout << "Activity Log Destroyed" << std::endl;
}

void Activity_log::add(Time_entry entry) {
    entries.push_back(entry);
}

void Activity_log::delete_last() {
    entries.pop_back();
}

void Activity_log::write_csv(std::string incident) {
    // Generating the current date
    // Adapted from https://en.cppreference.com/w/c/chrono/mktime
    auto current_time = time(NULL);
    struct tm tm = *std::gmtime(&current_time);
    char format[] = "%j_%H%M";
    char buffer[20];
    std::strftime(buffer, sizeof(buffer) - 1, format, &tm);
    buffer[19] = '\0';
    std::string csvName = std::string(buffer) + "_" + incident + ".csv";

    std::ofstream csv(csvName);
    if (!inFile.good()) {
        throw ios_base::failure("Failed to open the input file");
    }

    const char separator = ',';

    csv << "Time" << separator << "Activity" << separator;
    csv << "First Name" << separator << "Last Name" << separator;
    csv << "Agency" << separator << "Position" << separator;
    csv << "Radio ID" << separator << "Radio Type" << separator;
    csv << "Radio Notes"
        << "\r\n";

    for (const auto& entry : entries) {
        auto entry_time = entry.get_time();
        csv << std::asctime(std::gmtime(&entry_time));
        csv.seekp(-1, std::ios_base::cur);
        csv << separator << entry.get_activity() << separator;
        csv << entry.get_first_name() << separator << entry.get_last_name()
            << separator;
        csv << entry.get_agency() << separator << entry.get_position()
            << separator;
        csv << entry.get_id() << separator << entry.get_type() << separator
            << entry.get_notes() << "\r\n";
    }
    csv.close();
}

int Activity_log::get_length() const {
    return size(entries);
}

}  // namespace RDS
