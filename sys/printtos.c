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
	kprintf("Before[%8x]: %8x\n", ebp+1, *(ebp+1));
	kprintf("After[%8x]: %8x\n", ebp, *fp);

	int i=0;
	for(i=0; i<4; i++){
		kprintf("\telement[%8x]: %8x\n", ebp-i, *(ebp-i));
	}

	return 0;
}
