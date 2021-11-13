/**
 * @file Activity_log.hpp
 * @brief Stores entries & writes csv
 */
#ifndef ACTIVITY_LOG_HPP
#define ACTIVITY_LOG_HPP

#include <vector>
#include <string>
#include <cstdint>
#include "Time_entry.hpp"

namespace RDS {
class Activity_log {
   private:
    std::vector<Time_entry> entries;
   public:
    void add(Time_entry entry);
    void delete_last();
    void write_csv(std::string incident);
    int get_length()const;
};
}  // namespace RDS

#endif  // ACTIVITY_LOG_HPP
