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
	unsigned long start = GetCtr1000();
	if (isTraced == 1)
	{
		UpdateSysCallInfo(GetCtr1000() - start, "getpid", currpid);
	}
	return (currpid);
}
