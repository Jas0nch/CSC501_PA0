	#include <lab0.h>

        extern int etext, edata, end;
        void printsegaddress()
	{
		kprintf("void printsegaddress()\n\n");
		kprintf("Current: etext[0x%8x]=0x%8x, edata[0x%8x]=0x%8x, end[0x%8x]=0x%8x\n", &etext, etext, &edata, edata, &end, end);
		kprintf("Proceding: etext[0x%8x]=0x%8x, edata[0x%8x]=0x%8x, end[0x%8x]=0x%8x\n", &etext-0x1, *(&etext-0x1), &edata-0x1, *(&edata-0x1), &end-1, *(&end-1));
		kprintf("After: etext[0x%8x]=0x%8x, edata[0x%8x]=0x%8x, end[0x%8x]=0x%8x\n\n", &etext+0x1, *(&etext+0x1), &edata+0x1, *(&edata+0x1), &end+1, *(&end+1));
		return 0;
        }
