compiler_flags = -Wall -Wextra -Wpedantic -Werror
RDS: main.o Person.o
	g++ main.o Person.o -o RDS.out

main.o: main.cpp
	g++ $(compiler_flags) main.cpp -c

Person.o: Person.cpp Person.hpp
	g++ $(compiler_flags) Person.cpp -c

clean:
	rm *.o*

run:
	./RDS.out