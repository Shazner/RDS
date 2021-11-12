compiler_flags = -Wall -Wextra -Wpedantic -Werror
include_dirs = -Iinc
cpp_version = -std=c++17

RDS: main.o Person.o Radio.o
	g++ main.o Person.o Radio.o -o RDS.out $(cpp_version) $(include_dirs)

main.o: main.cpp
	g++ $(compiler_flags) main.cpp -c $(cpp_version) $(include_dirs)

Person.o: src/Person.cpp inc/Person.hpp
	g++ $(compiler_flags) src/Person.cpp -c $(cpp_version) $(include_dirs)

Radio.o: src/Radio.cpp inc/Radio.hpp
	g++ $(compiler_flags) src/Radio.cpp -c $(cpp_version) $(include_dirs)

clean:
	rm *.o*

run:
	./RDS.out