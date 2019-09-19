	#include <lab0.h>

        extern int etext, edata, end;
        void printsegaddress()
	{
		kprintf("void printsegaddress()\n\n");
		kprintf("Current: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext, etext, &edata, edata, &end, end);
		kprintf("Proceding: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext-0x1, *(&etext-0x1), &edata-0x1, *(&edata-0x1), &end-1, *(&end-1));
		kprintf("After: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n\n", &etext+0x1, *(&etext+0x1), &edata+0x1, *(&edata+0x1), &end+1, *(&end+1));
		return 0;
        }
