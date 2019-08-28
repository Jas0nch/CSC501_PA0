	#include <lab0.h>

        extern char etext, edata, end; /* The symbols must have some type,
                                          or "gcc -Wall" complains */
        void printsegaddress()
	{
           printf("First address past:\n");
           printf("    program text (etext)      %10p\n", &etext);
           printf("    initialized data (edata)  %10p\n", &edata);
           printf("    uninitialized data (end)  %10p\n", &end);
	   return;
        }
