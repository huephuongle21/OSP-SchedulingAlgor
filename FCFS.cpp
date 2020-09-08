#include "FCFS.h"

FCFS::FCFS() {

}

FCFS::~FCFS() {
    
}

void FCFS::perform(std::array<Process*, PROCESS_SIZE>& processes) {
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
        if(currProc < index) {
            while(btRemain[currProc] != 0) {
                timer++;
                btRemain[currProc]--;
                for(int i = 0; i != PROCESS_SIZE; i++) {
                    if(readyQueue[i] != nullptr && btRemain[i] > 0 
                            && i != currProc) {
                        wTime[i] += 1;
                    }
                }
                if(index < PROCESS_SIZE && processes[index]->getArrivalTime() == timer) {
                    Process* toAdd = new Process(*processes[index]);
                    readyQueue[index] = toAdd;
                    btRemain[index] = processes[index]->burstTime();
                    index++;
                }
            }
            complete++;
            currProc++;
            if(complete != PROCESS_SIZE) {
                done = false;
            }
        } else {
            timer++;
        }
    }

    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->setWaitingTime(wTime[i]);
    }
    
    calculateTurnaroundTime(processes);
}
