/**
 * @file Person.hpp
 * @brief Person abstraction
 */
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <ostream>

namespace RDS {
class Person {
   private:
    std::string first_name;
    std::string last_name;
    std::string agency;
    std::string position;
    bool active;

   public:
    Person(std::string first_name, std::string last_name, std::string agency,
           std::string position, bool active = true)
        : first_name(first_name),
          last_name(last_name),
          agency(agency),
          position(position),
          active(active) {}
    std::string get_first_name(void) const;
    std::string get_last_name(void) const;
    std::string get_agency(void) const;
    std::string get_position(void) const;
    bool is_active(void) const;
    void set_agency(std::string new_agency);
    void set_position(std::string new_position);
    void activate(void);
    void deactivate(void);
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
};
}  // namespace RDS
#endif  // PERSON_HPP