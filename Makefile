FLAGS = -pedantic-errors -std=c++11

interface_1.o: interface_1.cpp all_interface.h
	g++ $(FLAGS) -c $<

interface_2.o: interface_2.cpp all_interface.h
	g++ $(FLAGS) -c $<

interface_3.o: interface_3.cpp all_interface.h
	g++ $(FLAGS) -c $<

interface_4.o: interface_4.cpp all_interface.h
	g++ $(FLAGS) -c $<

main.o: main.cpp main.h all_interface.h
	g++ $(FLAGS) -c $<

main: main.o interface_1.o interface_2.o interface_3.o interface_4.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -rf *.o main

.PHONY: clean