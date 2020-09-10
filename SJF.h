#ifndef SJF_H
#define SJF_H

#include "Utility.h"
#include <limits.h>

class SJF {
    public:
    
    SJF();
    ~SJF();

    void perform(Process** processes);
};

#endif // SJF_H