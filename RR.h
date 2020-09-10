#ifndef RR_H
#define RR_H

#include "Utility.h"
#include <iostream>

#define QUANTUM          2
#define CONTEXT_SWITCH   0.1

class RR {
    public:
    
    RR();
    ~RR();

    void perform(Process** processes);
};

#endif // RR_H