.default: all

all: main

clean:
	rm -f main *.o

main: main.o Utility.o Process.o FCFS.o SJF.o RR.o
	g++ -Wall -Werror -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -O -g -c $^