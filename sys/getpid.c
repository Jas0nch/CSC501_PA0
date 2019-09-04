/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	kprintf("\n start getpid");
	if (isTraced == 1)
	{
		unsigned long start = GetCtr1000();
		sleep(1);
		kprintf("\n current pid: %d", currpid);
		UpdateSysCallInfo(GetCtr1000() - start, "getpid", currpid);
	}
	return (currpid);
}
