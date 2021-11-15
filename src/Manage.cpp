/**
 * @file Manage.cpp
 * @brief Implementations for the Manage UX
 */

#include "Manage.hpp"

namespace RDS {
template <typename T> void
Manage_UX(std::vector<T>& items) {

}
	
void Manage(std::vector<RDS::Radio>& radios){
    Manage_UX(radios);
}
void Manage(std::vector<RDS::Person>& people){
	Manage_UX(radios);
}
}  // namespace RDS