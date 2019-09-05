/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
	unsigned long start = GetCtr1000();
	if (isTraced == 1)
	{
		UpdateSysCallInfo(GetCtr1000() - start, "gettime", getpid());
	}
    
    /* long	now; */

	/* FIXME -- no getutim */

    return OK;
}
