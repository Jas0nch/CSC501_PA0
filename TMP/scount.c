/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	unsigned long start = GetCtr1000();
	
extern	struct	sentry	semaph[];
if (isTraced == 1)
	{
		UpdateSysCallInfo(GetCtr1000() - start, "scount", getpid());
	}

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	return(semaph[sem].semcnt);
}
