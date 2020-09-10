#include "SJF.h"

SJF::SJF() {

}

SJF::~SJF() {
    
}

void SJF::perform(Process** processes) {
    Process* readyQueue[PROCESS_SIZE] = {};
    for(int i = 0; i != PROCESS_SIZE; i++) {
        readyQueue[i] = nullptr;
    }
    int btRemain[PROCESS_SIZE] = {};
    int wTime[PROCESS_SIZE] = {};
    int index = 0;
    int currProc = 0;
    int complete = 0;
    for(int i = 0; i != PROCESS_SIZE; i++) {
        btRemain[i] = -1;
    }

    // Add the first new process to ready queue
    Process* toAdd = new Process(*processes[index]);
    readyQueue[index] = toAdd;
    btRemain[index] = processes[index]->burstTime();
    wTime[index] = 0;
    index++;

    int timer = toAdd->getArrivalTime();

    bool done = false;
    while(!done) {
        done = true;
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
            if(index < PROCESS_SIZE && processes[index]->getArrivalTime() == timer) {
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
        if(!done && btRemain[currProc] == 0) {
            int shortestProc = INT_MAX;
            for(int i = 0; i != PROCESS_SIZE; i++) {
                if(readyQueue[i] != nullptr && btRemain[i] < shortestProc 
                        && btRemain[i] != 0) {
                    shortestProc = btRemain[i];
                    currProc = i;
                }
            }
            complete++;
        }
    }
    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->setWaitingTime(wTime[i]);
    }

    calculateTurnaroundTime(processes);
}