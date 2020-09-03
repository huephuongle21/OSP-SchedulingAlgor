#ifndef SJF_H
#define SJF_H

#include "Utility.h"
#include <limits.h>

class SJF {
    public:
    
    SJF();
    ~SJF();

    void perform(std::array<Process*, PROCESS_SIZE>& processes);
};

#endif // SJF_H