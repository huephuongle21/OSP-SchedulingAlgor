#include "SJF.h"
#include "RR.h"
#include "FCFS.h"

int main(void) {

    FCFS* fcfs = new FCFS();
    SJF* sjf = new SJF();
    RR* rr = new RR();

    Process** processes_fcfs = new Process*[PROCESS_SIZE];
    Process** processes_sjf = new Process*[PROCESS_SIZE];
    Process** processes_rr = new Process*[PROCESS_SIZE];

    readFile(processes_fcfs);
    readFile(processes_sjf);
    readFile(processes_rr);

    fcfs->perform(processes_fcfs);
    sjf->perform(processes_sjf);
    rr->perform(processes_rr);

    std::cout << std::endl;
    std::cout << C_RED << "FIRST COME FIRST SERVE:\n" << C_RESET;
    printProcesses(processes_fcfs);

    std::cout << std::endl;

    std::cout << C_RED << "SHORTEST JOB FIRST:\n" << C_RESET;
    printProcesses(processes_sjf);

    std::cout << std::endl;

    std::cout << C_RED << "ROUND ROBIN:\n" << C_RESET;
    printProcesses(processes_rr);
    
}