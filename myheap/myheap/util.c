/**
* @file		util.c
* @brief	The implementation file for functions declared in util.h
* @author	Igor Bandurovych
* @year		2015
*/

#include "util.h"
#include <stdio.h>	/*<* printf*/

void my_map(void)
{
	size_t data_size = heap_size();
	char* data = (char*)heap_start();
	char* info = (char*)info_start();
	size_t counter = 0;
	size_t block;
	char is_busy;
	printf("relative\treal address\tstate\tsize\n");
	while (counter != data_size)
	{
		is_busy = *(info + counter / 4) >> 2 * (counter % 4) & 1;
		printf("0x%x\t\t0x%x\t%s", counter, data + counter,
			(is_busy) ? "busy\t" : "free\t");
		++counter;
		block = 1;
		while ( (*(info + counter / 4) >> 2 * (counter % 4) & 1) == is_busy && counter < data_size)
		{
			++counter;
			++block;
		}
		printf("%d\n", block);
	}
	printf("\n");
}