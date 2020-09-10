#ifndef UTILITY_H
#define UTILITY_H

#include "Process.h"

#define PROCESS_SIZE       200
#define NUMBER_ATTRIBUTES  5

#define ID_INDEX           0
#define BT_INDEX           1
#define AT_INDEX           2
#define WT_INDEX           3
#define TAT_INDEX          4

#define C_RESET        "\033[0m"            /* Reset colour */
#define C_RED          "\033[31m"           /* Red */

void readFile(Process** processes);

void printProcesses(Process** processes);

void calculateTurnaroundTime(Process** processes);

double averageWaitingTime(Process** processes);

double averageTurnaroundTime(Process** processes);

#endif // UTILITY_H