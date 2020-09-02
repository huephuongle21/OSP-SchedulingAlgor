#include "Utility.h"
#include <limits.h>

void perform(std::array<Process*, PROCESS_SIZE>& processes);

int main(void) {
    std::array<Process*, PROCESS_SIZE> processes = {};
    
    readFile(processes);

    perform(processes);

    calculateTurnaroundTime(processes);

    printProcesses(processes);
}

void perform(std::array<Process*, PROCESS_SIZE>& processes) {
    Process* readyQueue[PROCESS_SIZE] = {};
    for(int i = 0; i != PROCESS_SIZE; i++) {
        readyQueue[i] = nullptr;
    }
    int btRemain[PROCESS_SIZE] = {};
    int wTime[PROCESS_SIZE] = {};
    int index = 0;
    int timer = 0;
    int currProc = 0;
    int complete = 0;
    for(int i = 0; i != PROCESS_SIZE; i++) {
        btRemain[i] = -1;
    }
    bool done = false;
    while(!done) {
        done = true;
        if(processes[index]->getArrivalTime() == timer) {
            Process* toAdd = new Process(*processes[index]);
            readyQueue[index] = toAdd;
            btRemain[index] = processes[index]->burstTime();
            if(index == 0) {
                wTime[index] = 0;
            } 
            index++;
        }
        if(index == 0) {
            timer += 1;
            done = false;
        } else {
            bool finished = false;
            while(btRemain[currProc] != 0 && !finished) {
                int switchProc = -1;
                timer++;
                btRemain[currProc]--;
                for(int i = 0; i != PROCESS_SIZE; i++) {
                    if(readyQueue[i] != nullptr && btRemain[i] != 0 
                            && i != currProc) {
                        wTime[i] += 1;
                    }
                }
                if(processes[index]->getArrivalTime() == timer) {
                    Process* toAdd = new Process(*processes[index]);
                    readyQueue[index] = toAdd;
                    btRemain[index] = processes[index]->burstTime();
                    if(btRemain[index] < btRemain[currProc]) {
                        switchProc = index;
                    }
                    index++;
                }
                if(switchProc != -1) {
                    currProc = switchProc;
                    finished = true;
                }                
            }
            if(complete != PROCESS_SIZE) {
                done = false;
            }
        }
        if(!done && btRemain[currProc] == 0) {
            int shortestProc = INT_MAX;
            for(int i = 0; i != PROCESS_SIZE; i++) {
                if(readyQueue[i] != nullptr && btRemain[i] < shortestProc 
                        && btRemain[i] != 0) {
                    currProc = i;
                }
            }
            complete++;
        }
    }
    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->setWaitingTime(wTime[i]);
    }
}