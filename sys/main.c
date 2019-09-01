/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	syscallsummary_start();
	kprintf("\n\nHello World,  Xinu lives\n\n%x\n\n", zfunction(0xaabbccdd));
	printsegaddress();
	printtos();
	printprocstks(-1);

	getpid();
	syscallsummary_stop();
	printsyscallsummary();

	return 0;
}
