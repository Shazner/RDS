compiler_flags = -Wall -Wextra -Wpedantic -Werror
cpp_version = -std=c++17

RDS: main.o Person.o
	g++ main.o Person.o -o RDS.out $(cpp_version)

main.o: main.cpp
	g++ $(compiler_flags) main.cpp -c $(cpp_version)

Person.o: Person.cpp Person.hpp
	g++ $(compiler_flags) Person.cpp -c $(cpp_version)

clean:
	rm *.o*

run:
	./RDS.out