compiler_flags = -Wall -Wextra -Wpedantic -Werror
include_dirs = -Iinc
cpp_version = -std=c++17

RDS: main.o Person.o Radio.o Time_entry.o Utility.o Activity_log.o Manage.o
	g++ main.o Person.o Radio.o Time_entry.o Utility.o Activity_log.o Manage.o -o RDS.out $(cpp_version) $(include_dirs)

main.o: main.cpp
	g++ $(compiler_flags) main.cpp -c $(cpp_version) $(include_dirs)

Person.o: src/Person.cpp inc/Person.hpp
	g++ $(compiler_flags) src/Person.cpp -c $(cpp_version) $(include_dirs)

Radio.o: src/Radio.cpp inc/Radio.hpp
	g++ $(compiler_flags) src/Radio.cpp -c $(cpp_version) $(include_dirs)

Time_entry.o: src/Time_entry.cpp inc/Time_entry.hpp
	g++ $(compiler_flags) src/Time_entry.cpp -c $(cpp_version) $(include_dirs)


Utility.o: src/Utility.cpp inc/Utility.hpp
	g++ $(compiler_flags) src/Utility.cpp -c $(cpp_version) $(include_dirs)

Activity_log.o: src/Activity_log.cpp inc/Activity_log.hpp
	g++ $(compiler_flags) src/Activity_log.cpp -c $(cpp_version) $(include_dirs)

Manage.o: src/Manage.cpp inc/Manage.hpp
	g++ $(compiler_flags) src/Manage.cpp -c $(cpp_version) $(include_dirs)

clean:
	rm *.o*

run:
	./RDS.out
