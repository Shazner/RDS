#include <iostream>
#include <vector>

#include "Radio.hpp"
#include "Person.hpp"
#include "Time_entry.hpp"
#include "Utility.hpp"
#include "Activity_log.hpp"

int main() {
    std::vector<RDS::Radio> radios;
    for (int i = 0; i < 9; i++) {
        RDS::Radio radio('a' + std::to_string(i), "DMR");
        if (i % 2 == 0) {
            radio.deactivate();
        }
        radios.push_back(radio);
    }
    std::vector<RDS::Person> people;
    people.push_back(RDS::Person("Thomas", "Fike", "MCDEM", "AUXC"));
    people.push_back(RDS::Person("Michael", "Drapkin", "MCDEM", "COML"));
    people.push_back(RDS::Person("Katherine", "Rocha", "CO", "AUXC"));
    people.push_back(RDS::Person("Dennis", "Bietry", "DEMA", "COML"));
    people.push_back(RDS::Person("Dennis", "Campbell", "MCECG", "RADO"));
    people.push_back(RDS::Person("Bob", "Fike", "MCECG", "HAM"));
    const auto ret_val = RDS::UTILITY::select(people);
    std::cout << ret_val.second;
    RDS::Activity_log a;
}