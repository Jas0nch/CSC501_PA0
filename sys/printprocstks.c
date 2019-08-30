#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

static unsigned long	*esp;

void printprocstks(int priority){
    //printf("this is printprocstks!");
    kprintf("void printprocstks(int priority)\n");

    int i=0;
    for (i = 0; i < NPROC; i++)
    {
        struct pentry *proc = &proctab[i];
        
        if (proc->pprio > priority && proc->pstate != PRFREE){
            kprintf("Process [%s]\n", proc->pname);
            kprintf("\t pid: %d", i);
            kprintf("\t priority: %d", proc->pprio);
            kprintf("\t base: 0x%08x", proc->pbase);
            kprintf("\t limit: 0x%08x", proc->plimit);
            kprintf("\t len: %d", proc->pstklen);
            if (i == currpid) {
		        asm("movl %esp,esp");
                kprintf("\t pointer: 0x %08x", esp);
    	    } else {
            kprintf("\t pointer: 0x %08x", (unsigned long *)proc->pesp);
	        }
        }
    }

    return 0;
}