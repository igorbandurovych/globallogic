/**
* @file		myheap.c
* @brief	The implementation file for functions declared in myheap.h
* 
* @author	Igor Bandurovych
* @year		2015
*/

#include "myheap.h"

#include <string.h>	/*<* memset*/

struct
{
	unsigned char* info;		/*pointer to start of info segment*/
	unsigned char* data;		/*pointer to start of data segment*/
	unsigned char* free_mem;	/*pointer to the first block of free memory*/
	size_t size;				/*max memory that can be used*/
} manager;

void heap_init(const size_t size)
{
	if (size)	/*size != 0*/
	{
		heap_destroy();	/*removing previously allocated memory*/
		div_t info_size = div(size, 4U);
		manager.info = malloc(info_size.quot + (info_size.rem ? 1 : 0));
		memset(manager.info, 0, info_size.quot + (info_size.rem ? 1 : 0));	/*setting whole info segment to 0*/
		manager.data = malloc(size);
		manager.size = (manager.info && manager.data) ? size : 0;
		if (!manager.size)	/*init failed*/
		{
			if (manager.data)
			{
				free(manager.data);
			}
			if (manager.info)
			{
				free(manager.info);
			}
		}
		manager.free_mem = manager.data;
	}
}

size_t heap_size(void)
{
	return manager.size;
}

void* my_malloc(const size_t size)
{
	if (manager.free_mem == manager.data + manager.size || size > manager.size || !size)
	{
		return NULL;	/*if no free memory left, requested size bigger than size of data segment or size == 0*/
	}
	unsigned char* result = manager.free_mem;
	size_t bytes_found = 0;
	size_t offset = manager.free_mem - manager.data;
	while (bytes_found != size)
	{
		/*if (2 * offset)-th bit of info segment is 0 (offset-th byte in data segment is free) */
		if (!(*(manager.info + offset / 4) & 1 << 2 * (offset % 4)) && offset < manager.size)
		{
			++bytes_found;
			++offset;
		}
		else
		{
			bytes_found = 0;
			/*while (2 * offset)-th bit of info segment is 1 (offset-th byte in data segment is busy)
			  and it is possible to allocate memory in myheap*/
			while (((*(manager.info + offset / 4) & 1 << 2 * (offset % 4))) && offset < manager.size)
			{
				++offset;
			}
			if (offset == manager.size)
			{
				return NULL;	/*allocation is impossible, no space for requested amount of memory*/
			}
			result = manager.data + offset;
		}
	}

	size_t counter = offset - 1;
	

	/*setting all allocated bytes in info segment as busy*/
	while (bytes_found--)
	{
		*(manager.info + counter / 4) |= 3 << 2 * (counter % 4);	/*3 is binary 11*/
		--counter;
	}
	
	/*point the end of memory block (10)*/
	*(manager.info + (offset - 1) / 4) &= ~(1 << (2 * ((offset - 1) % 4) + 1));

	/*find pointer to the first block of free memory (if memory allocated at free_mem)*/
	if (result == manager.free_mem)
	{
		while ((*(manager.info + offset / 4) & 1 << 2 * (offset % 4)) && offset < manager.size)
		{
			++offset;
		}
		manager.free_mem = manager.data + offset;
	}
	return result;
}

void my_free(void* data)
{
	/*data doesn't belong to heap*/
	if ((unsigned char*)data < manager.data || (unsigned char*)data > manager.data + manager.size)
	{
		return;
	}
	const size_t start_offset = (unsigned char*)data - manager.data;
	size_t offset = start_offset;
	/*setting all allocated bytes in info segment as free*/
	do
	{
		*(manager.info + offset / 4) &= ~(1 << 2 * (offset % 4));
	} 
	while ((*(manager.info + offset / 4) & 1 << (2 * (offset % 4) + 1)) && ++offset != manager.size);

	while (offset != start_offset)
	{
		*(manager.info + offset / 4) &= ~(1 << (2 * (offset % 4)));
		--offset;
	}

	/*change pointer to the first block of free memory (if flags removed before free_mem)*/
	if ((unsigned char*) data < manager.free_mem)
	{
		manager.free_mem = (unsigned char*) data;
	}
}

void* heap_start(void)
{
	return manager.data;
}

void* info_start(void)
{
	return manager.info;
}


void heap_destroy(void)
{
	if (manager.size)	/*manager.size != 0*/
	{
		free(manager.info);
		free(manager.data);
	}
}