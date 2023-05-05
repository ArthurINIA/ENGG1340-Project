FLAGS = -pedantic-errors -std=c++11

interface_1.o: interface_1.cpp all_interface.h UI.h
	g++ $(FLAGS) -c $<

interface_2.o: interface_2.cpp all_interface.h UI.h
	g++ $(FLAGS) -c $<

interface_3.o: interface_3.cpp all_interface.h UI.h
	g++ $(FLAGS) -c $<

interface_4.o: interface_4.cpp all_interface.h UI.h
	g++ $(FLAGS) -c $<

UI.o: UI.cpp UI.h
	g++ $(FLAGS) -c $<

db.o: db.cpp all_interface.h UI.h
	g++ $(FLAGS) -c $<

rand_event.o: rand_event.cpp all_interface.h
	g++ $(FLAGS) -c $<

main.o: main.cpp main.h all_interface.h UI.h
	g++ $(FLAGS) -c $<

main: main.o interface_1.o interface_2.o interface_3.o interface_4.o db.o UI.o rand_event.o
	g++ $(FLAGS) $^ -o $@

start: 
	make main
	./main

clean:
	rm -rf *.o main ui *.exe

.PHONY: clean