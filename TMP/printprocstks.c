#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

static unsigned long	*esp;

void printprocstks(int priority){
    //printf("this is printprocstks!");
    kprintf("\nvoid printprocstks(int priority)\n");

    int i=0;
    for (i = 0; i < NPROC; i++)
    {
        struct pentry *proc = &proctab[i];
        
        if (proc->pprio > priority && proc->pstate != PRFREE){
            kprintf("Process [%s]\n", proc->pname);
            kprintf("\t pid: %d \n", i);
            kprintf("\t priority: %d \n", proc->pprio);
            kprintf("\t base: 0x%08x \n", proc->pbase);
            kprintf("\t limit: 0x%08x \n", proc->plimit);
            kprintf("\t len: %d \n", proc->pstklen);
            if (i == currpid) {
		        asm("movl %esp,esp");
                kprintf("\t pointer: 0x %08x \n", esp);
    	    } else {
            kprintf("\t pointer: 0x %08x \n", (unsigned long *)proc->pesp);
	        }
        }
    }

    return 0;
}