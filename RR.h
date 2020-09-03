#ifndef RR_H
#define RR_H

#include "Utility.h"
#include <iostream>
#include <vector>

#define QUANTUM          2
#define CONTEXT_SWITCH   0.1

class RR {
    public:
    
    RR();
    ~RR();

    void perform(std::array<Process*, PROCESS_SIZE>& processes);
};

#endif // RR_H