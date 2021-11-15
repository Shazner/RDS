/**
 * @file Utility.hpp
 * @brief Contains a set of Utility functions
 */
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>

#include "Radio.hpp"
#include "Person.hpp"

namespace RDS {
namespace UTILITY {
/**
 * @brief retruns the vector which contains all items where the predicate
 * was true Somewhat based on the std::find_if function.
 * @param data vector
 * @param p predicate to be evaluated.
 * @returns vector of InputIt
 */
template <typename T, class UnaryPredicate>
std::vector<T> find_if(const std::vector<T>& items, UnaryPredicate p) {
    std::vector<T> output;
    for (const auto& item : items) {
        if (p(item)) {
            output.push_back(item);
        }
    }
    return output;
}
[[nodiscard]] int get_int();
/// if all is true then both active and deactivated radios can be selected.
[[nodiscard]] std::pair<bool, Radio> select(const std::vector<Radio>& radios,
                                            bool all = true);
[[nodiscard]] std::pair<bool, Person> select(const std::vector<Person>& people,
                                             bool all = true);

}  // namespace UTILITY
}  // namespace RDS

#endif  // UTILITY_HPP