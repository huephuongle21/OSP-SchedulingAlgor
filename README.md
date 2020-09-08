# OSP-SchedulingAlgor

## Table of contents
* [Structure](#structure)
* [Language](#language)
* [Setup](#setup)

## Structure
This project includes some classes:
* Utility: a class to store helper methods including read processes from file, 
print process, calculate turnaround time, average turnaround and waiting time
* Process: represent a process which contains the attributes: process_id, 
burst_time, arrival_time, waiting_time, turnaround_time
* FCFS, SJF, RR: 3 scheduling algorithm
* main: contains method to read processes from processes.txt, run all 3 algorithms and display to the console
* processes.txt: a file containing all input processes
   
	
## Language
C++ is used so instead of c file, this project contains .h file and .cpp file
* .h file: declaration of the class
* .cpp file: definition of the class
	
## Setup
To run this project using Makefile from terminal:

```
$ make
$ ./main
```
