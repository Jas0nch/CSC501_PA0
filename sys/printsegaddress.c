	#include <lab0.h>

        extern char etext, edata;
	extern unsigned short end;
        void printsegaddress()
	{
		kprintf("void printsegaddress()\n\n");
		kprintf("Current: etext[%8x]=%8x, edata[%8x]=%8x, end[%8x]=%8x\n", &etext, etext, &edata, edata, &end, end);
		kprintf("Proceding: etext[%8x]=%8x, edata[%8x]=%8x, end[%8x]=%8x\n", &etext-0x4, *(&etext-0x4), &edata-0x4, *(&edata-0x4), &end-2, *(&end-2));
		kprintf("After: etext[%8x]=%8x, edata[%8x]=%8x, end[%8x]=%8x\n\n", &etext+0x4, *(&etext+0x4), &edata+0x4, *(&edata+0x4), &end+2, *(&end+2));
		return 0;
        }
