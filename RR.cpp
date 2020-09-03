#include "RR.h"

RR::RR() {

}

RR::~RR() {

}

void RR::perform(std::array<Process*, PROCESS_SIZE>& processes) {
    Process* readyQueue[PROCESS_SIZE] = {};
    for(int i = 0; i != PROCESS_SIZE; i++) {
        readyQueue[i] = nullptr;
    }
    double btRemain[PROCESS_SIZE] = {};
    double wTime[PROCESS_SIZE] = {};
    int index = 0;
    int timer = 0;
    int count = 0;
    int activeProc = 0;
    int complete = 0;
    for(int i = 0; i != PROCESS_SIZE; i++) {
        btRemain[i] = -1;
    }

    bool done = false;
    while(!done) {
        done = true;
        if(index < PROCESS_SIZE && processes[index]->getArrivalTime() == timer) {
            Process* toAdd = new Process(*processes[index]);
            readyQueue[index] = toAdd;
            btRemain[index] = processes[index]->burstTime();
            index++;
            activeProc++;
        }
        for(int i = 0; i != PROCESS_SIZE; i++) {
            if(readyQueue[i] != nullptr) {
                if(btRemain[i] > 0) {
                    // Apply context switch to load saved process
                    if(activeProc != 1 && readyQueue[i]->burstTime() != btRemain[i]) {
                        btRemain[i] += CONTEXT_SWITCH;
                    }
                    if(complete != PROCESS_SIZE) {
                        done = false;
                    }
                    if(btRemain[i] > QUANTUM) {
                        while(count < QUANTUM) {
                            timer++;
                            count++;
                            btRemain[i]--;
                            for(int k = 0; k != PROCESS_SIZE; k++) {
                                if(readyQueue[k] != nullptr && btRemain[k] != 0
                                        && k != i) {
                                    wTime[k] += 1;
                                }
                            }
                            if(index < PROCESS_SIZE && processes[index]->getArrivalTime() == timer) {

                                Process* toAdd = new Process(*processes[index]);
                                readyQueue[index] = toAdd;
                                btRemain[index] = processes[index]->burstTime();
                                index++;
                                activeProc++;
                            }
                        }
                        count = 0;

                        // Apply context switch to save process's state 
                        // if there are more than one process in ready queue
                        if(index != 1 && btRemain[i] != 0) {
                            btRemain[i] += CONTEXT_SWITCH;
                        } else if (btRemain[i] == 0) {
                            activeProc--;
                            complete++;
                        }
                    } else {
                        while(count < btRemain[i]) {
                            timer++;
                            count++;
                            for(int k = 0; k != PROCESS_SIZE; k++) {
                                if(readyQueue[k] != nullptr && btRemain[k] != 0
                                        && k != i) {
                                    wTime[k] += 1;
                                }
                            }
                            if(index < PROCESS_SIZE && processes[index]->getArrivalTime() == timer) {
                                Process* toAdd = new Process(*processes[index]);
                                readyQueue[index] = toAdd;
                                btRemain[index] = processes[index]->burstTime();
                                index++;
                                activeProc++;
                            }
                        }
                        count = 0;
                        btRemain[i] = 0;
                        activeProc--;
                        complete++;
                    }
                }
            }
        }
        if(index == 0) {
            timer += 1;
            done = false;
        }
    }
    for(int i = 0; i != PROCESS_SIZE; i++) {
        processes[i]->setWaitingTime(wTime[i]);
    }

    calculateTurnaroundTime(processes);
}
