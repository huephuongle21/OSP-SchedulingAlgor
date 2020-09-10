.default: all

all: main

clean:
	rm -f main *.o

main: main.o Utility.o Process.o FCFS.o SJF.o RR.o
	g++ -Wall -Werror --std=c++11 -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror --std=c++11 -O -g -c $^
