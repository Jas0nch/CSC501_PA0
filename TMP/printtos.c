#include <stdio.h>
#include <lab0.h>

// reference: https://www.cnblogs.com/taek/archive/2012/02/05/2338877.html 
//To-do write my idea down after the five function completed

static unsigned long	*ebp;

void printtos(){
	//kprintf("this is printtos!");
	unsigned long	*fp;

	asm("movl %ebp,ebp");

	fp = ebp;

	kprintf("void printtos()\n");
	kprintf("Before[0x%08x]: 0x%08x\n", ebp+1, *(ebp+1));
	kprintf("After [0x%08x]: 0x%08x\n", ebp, *fp);

	int i=0;
	for(i=0; i<4; i++){
		kprintf("\telement[0x%08x]: 0x%08x\n", ebp-i-1, *(ebp-i-1));
	}

	return 0;
}
