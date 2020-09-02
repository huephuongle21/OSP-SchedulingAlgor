#ifndef PROCESS_H
#define PROCESS_H 

#include <iostream>

class Process {
public:
   Process(int id, int arrival_time, int burst_time);
   Process();
   Process(const Process& other);
   ~Process();

   void setWaitingTime(double waitingTime);
   void setTurnaroundTime(double turnaroundTime);

   int burstTime();

   void print();

   double getWaitingTime();

   int getArrivalTime();

   int getId();

private:
    int id;
    int arrival_time;
    int burst_time;
    double waiting_time;
    double turnaround_time;
};

#endif // PROCESS_H