/**
 * @file Utlity.hpp
 * @brief Contains a set of Utility functions
 */
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <functional>

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
std::vector<T> find_if(const std::vector<T> items, UnaryPredicate p) {
    std::vector<T> output;
    for (const auto item : items) {
        if (p(item)) {
            output.push_back(item);
        }
    }
    return output;
}

}  // namespace UTILITY
}  // namespace RDS

#endif  // UTILITY_HPP