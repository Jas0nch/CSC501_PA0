#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

const char syscallname[NSYSCALLTOTRACE][20] = {"getpid"};

void syscallsummary_start()
{
	isTraced = 1;
	int i = 0;
	for (; i < NSYSCALLTOTRACE; i++)
	{
		strcpy(syscallInfoArray[i].name, syscallname[i]);
		syscallInfoArray[i].freq = 0;
		syscallInfoArray[i].averageTime = 0;
	}
}

void syscallsummary_stop()
{
	isTraced = 0;
}

void UpdateSysCallInfo(unsigned long time, char name[20])
{
	int i = 0;
	for (i = 0; i < NSYSCALLTOTRACE; i++)
	{
		if (name == syscallInfoArray[i].name)
		{
			syscallInfoArray[i].averageTime = syscallInfoArray[i].averageTime * syscallInfoArray[i].freq / (syscallInfoArray[i].freq + 1);
			syscallInfoArray[i].freq++;
			break;
		}
	}
}

void printsyscallsummary()
{
	kprintf("\n void printsyscallsummary()");
	int i = 0;
	for (i = 0; i < NPROC; i++)
	{
		kprintf("\n Process [pid:%d]", i);
		int j = 0;
		for (j = 0; j < NSYSCALLTOTRACE; j++)
		{
			if (syscallInfoArray[j].freq != 0)
			{
				kprintf("\n\t Syscall: %s, count: %d, average execution time: %ul (ms)", syscallInfoArray[j].name, syscallInfoArray[j].freq, syscallInfoArray[j].averageTime);
			}
		}
	}
}