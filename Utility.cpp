#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Utility.h"

void readFile(std::array<Process*, PROCESS_SIZE>& processes) {

    int toSet[3] = {};
    int index = 0;
    std::string line;
    std::ifstream inFile;
    inFile.open("processes.txt");
    if(inFile.fail()) {
        std::cout << "File does not exist!" << std::endl;
    } else {
        while(!inFile.eof() && std::getline(inFile, line)) {
            std::istringstream input(line);
            int value;
            int number = 0;
            while (input >> value) {
                toSet[number] = value;
                number++;
            }
            processes[index] = new Process(toSet[ID_INDEX], 
                toSet[BT_INDEX], toSet[AT_INDEX]);
            number = 0;
            index++;
        }

        inFile.close();
    }
}

void printProcesses(std::array<Process*, PROCESS_SIZE>& processes) {
    std::cout << "\n  ID\t   BT \t    AT\t     WT\t      TAT\n\n";
    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->print();
        std::cout << std::endl;
    }
}

void calculateTurnaroundTime(std::array<Process*, PROCESS_SIZE>& processes) {
    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->setTurnaroundTime(processes[i]->getWaitingTime() 
            + processes[i]->burstTime());
    }
}