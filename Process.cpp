#include "Process.h"
#include <iomanip>

Process::Process(int id, int burst_time, int arrival_time) {
    this->id = id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->waiting_time = 0;
    this->turnaround_time = 0;
}

Process::Process() {

}

Process::~Process() {

}

Process::Process(const Process& other) {
   this->id = other.id;
   this->arrival_time = other.arrival_time;
   this->burst_time = other.burst_time;
   this->waiting_time = other.waiting_time;
   this->turnaround_time = other.turnaround_time;
}

void Process::setWaitingTime(double waitingTime) {
    this->waiting_time = waitingTime;
}

void Process::setTurnaroundTime(double turnaroundTime) {
    this->turnaround_time = turnaroundTime;
}

int Process::burstTime() {
    return this->burst_time;
}

double Process::getWaitingTime() {
    return this->waiting_time;
}

void Process::print() {
    std::cout << "  " << std::left << std::setw(7) << id << "  |";
    std::cout << "  " << std::left << std::setw(7) << burst_time << "  |";
    std::cout << "  " << std::left << std::setw(7) << arrival_time << "  |";
    std::cout << "  " << std::left << std::setw(7) << waiting_time << "  |";
    std::cout << "  " << std::left << std::setw(7) << turnaround_time << "  |";
}

int Process::getArrivalTime() {
    return this->arrival_time;
}

int Process::getId() {
    return this->id;
}
