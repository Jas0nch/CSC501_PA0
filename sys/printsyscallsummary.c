#include <stdio.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

const char syscallname[NSYSCALLTOTRACE][20] = {"getpid"};

struct SyscallInfo syscallInfoArray[NPROC][NSYSCALLTOTRACE];
int isTraced = 0;

void syscallsummary_start()
{
	isTraced = 1;
	int i = 0;
	for (int j = 0; j < NPROC; j++)
	{
		for (; i < NSYSCALLTOTRACE; i++)
		{
			strcpy(syscallInfoArray[j][i].name, syscallname[i]);
			syscallInfoArray[j][i].freq = 0;
			syscallInfoArray[j][i].averageTime = 0;
		}
	}
}

void syscallsummary_stop()
{
	isTraced = 0;
}

void UpdateSysCallInfo(unsigned long time, char name[20], int pid)
{
	int i = 0;
	for (i = 0; i < NSYSCALLTOTRACE; i++)
	{
		if (strcmp(name, syscallInfoArray[pid][i].name) == 0)
		{
			syscallInfoArray[pid][i].averageTime = (time + syscallInfoArray[pid][i].averageTime * syscallInfoArray[pid][i].freq) / (syscallInfoArray[pid][i].freq + 1);
			syscallInfoArray[pid][i].freq++;
			break;
		}
	}
}

void printsyscallsummary()
{
	kprintf("\nvoid printsyscallsummary()");
	int i = 0;
	for (i = 0; i < NPROC; i++)
	{
		if (proctab[i].pstate != PRFREE)
		{
			kprintf("\nProcess [pid:%d]", i);
			int j = 0;
			for (j = 0; j < NSYSCALLTOTRACE; j++)
			{
				if (syscallInfoArray[i][j].freq != 0)
				{
					kprintf("\n\tSyscall: %s, count: %d, average execution time: %ul (ms)", syscallInfoArray[i][j].name, syscallInfoArray[i][j].freq, syscallInfoArray[i][j].averageTime);
				}
			}
		}
	}
}
