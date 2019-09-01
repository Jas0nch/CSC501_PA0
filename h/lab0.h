extern long zfunction (long param);
void printsegaddress();
void printtos();
void printprocstks(int priority);
void printsyscallsummary();

#define NSYSCALLTOTRACE  1 // number of system call to trace
extern int isTraced;
extern struct SyscallInfo
{
        char name[20]; // assume the longest length of system call name is smaller than 20
        int freq;
        unsigned long averageTime;
};

extern struct SyscallInfo syscallInfoArray[NSYSCALLTOTRACE]; 
void UpdateSysCallInfo(unsigned long time, char name[20]);