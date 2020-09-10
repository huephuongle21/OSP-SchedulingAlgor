#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "Utility.h"

class FCFS {
    public:

    FCFS();
    ~FCFS();

    void perform(Process** processes);

};

#endif // FCFS_H