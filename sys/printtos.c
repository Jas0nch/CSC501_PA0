#include <stdio.h>
#include <lab0.h>


static unsigned long	*esp;
static unsigned long	*ebp;

void printtos(){
	printf("this is printtos!");
	unsigned long	*sp, *fp;

	asm("movl %esp,esp");
	asm("movl %ebp,ebp");

	sp = esp;
	fp = ebp;

	kprintf("void printtos()\n");
	kprintf("Before[%8x]: %8x\n", ebp, *fp);
	kprintf("After[%8x]: %8x\n", ebp+1, *(ebp+1));


	return 0;
}
