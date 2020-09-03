#include "SJF.h"
#include "RR.h"
#include "FCFS.h"

int main(void) {

    FCFS* fcfs = new FCFS();
    SJF* sjf = new SJF();
    RR* rr = new RR();

    std::array<Process*, PROCESS_SIZE> processes_fcfs = {};
    std::array<Process*, PROCESS_SIZE> processes_sjf = {};
    std::array<Process*, PROCESS_SIZE> processes_rr = {};

    readFile(processes_fcfs);
    readFile(processes_sjf);
    readFile(processes_rr);

    fcfs->perform(processes_fcfs);
    sjf->perform(processes_sjf);
    rr->perform(processes_rr);

    std::cout << "FIRST COME FIRST SERVE:\n";
    printProcesses(processes_fcfs);
    std::cout << std::endl;

    std::cout << "SHORTEST JOB FIRST:\n";
    printProcesses(processes_sjf);
    std::cout << std::endl;

    std::cout << "ROUND ROBIN:\n";
    printProcesses(processes_rr);
    std::cout << std::endl;


}