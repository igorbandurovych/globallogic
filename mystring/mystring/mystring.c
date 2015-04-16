/**
* @file		mystring.h
* @brief	The header file for functions to work with mystring type
* mystring is an analog of C string that uses another terminating character
* (7 is chosen as terminating character because I don't find useful to have
* bell character in strings)
* mystring works similarly to C string with usage of another algorithms.
* Copyright 2015 by Igor Bandurovych
*/

#include "mystring.h"	/**< functions prototypes */
#include <stdio.h>		/**< printf, putchar*/

void* memCopy(void* dest, const void* src, size_t num)
{
	/* dest and src converted to unsigned char* */
	unsigned char* destination = (unsigned char*)dest;
	unsigned char* source = (unsigned char*)src;

	/*copy num bytes from source to destination*/
	while (num--)
	{
		*destination++ = *source++;
	}

	return dest;
}

void* memMove(void* dest, const void* src, size_t num)
{
	/* dest and src converted to unsigned char* */
	unsigned char* destination = (unsigned char*)dest;
	unsigned char* source = (unsigned char*)src;

	/* overlap is not possible*/
	if (destination < source)
	{
		/*copy num bytes from source to destination*/
		while (num--)
		{
			*destination++ = *source++;
		}
	}
	else
	{
		/*overlap is possible, copying memory in reverse order*/
		destination += num - 1;
		source += num - 1;

		/*copy num bytes from source to destination*/
		while (num--)
		{
			*destination-- = *source--;
		}
	}

	return dest;
}

char* strCopy(char* dest, const char* src)
{
	char* res = dest;

	/*copying each character from src to dest*/
	while (*src != TERMINATING_CHAR)
	{
		*dest++ = *src++;
	}

	/*appending terminating char to dest*/
	*dest = TERMINATING_CHAR;

	return res;
}

char* strNumCopy(char* dest, const char* src, size_t num)
{
	char* res = dest;

	if (num) /*num != 0*/
	{
		/*while num characters not copied or terminating char in src not reached*/
		while (num && *src != TERMINATING_CHAR)
		{
			*dest++ = *src++;
			--num;
		}
		/*if terminating char in src reached*/
		if (*src == TERMINATING_CHAR)
		{
			/*padding left characters with TERMINATING_CHAR*/
			while (num--)
			{
				*dest++ = TERMINATING_CHAR;
			}
		}
	}

	return res;
}

char* strConcat(char* dest, const char* src)
{
	char* res = dest;

	/*moving pointer to dest to the end of string*/
	while (*dest != TERMINATING_CHAR)
	{
		dest++;
	}
	/*appending all characters from src to dest*/
	while (*src != TERMINATING_CHAR)
	{
		*dest++ = *src++;
	}

	/*appending terminating char to dest*/
	*dest = TERMINATING_CHAR;

	return res;
}

char* strNumConcat(char* dest, const char* src, size_t num)
{
	char* res = dest;

	if (num) /*num != 0*/
	{
		/*moving pointer to dest to the end of string*/
		while (*dest != TERMINATING_CHAR)
		{
			dest++;
		}
		/*appending up to num (or all) characters from src to dest*/
		while (num-- && *src != TERMINATING_CHAR)
		{
			*dest++ = *src++;
		}

		/*appending terminating char to dest*/
		*dest = TERMINATING_CHAR;
	}

	return res;
}

int memCompare(const void* ptr1, const void* ptr2, size_t num)
{
	/* ptr1 and ptr2 converted to const unsigned char* */
	const unsigned char* mem1 = (const unsigned char*)ptr1;
	const unsigned char* mem2 = (const unsigned char*)ptr2;
	
	if (!num) /*num == 0*/
	{
		return 0;
	}
	/*comparing up to num bytes*/
	while (--num && *mem1 == *mem2)
	{
		++mem1;
		++mem2;
	}

	/*
	*if memory pointed by ptr1 lesser than ptr2, -1 is returned
	*if ptr1 and ptr2 are equal, 0 is returned
	*if ptr1 is greater than ptr2, 1 is returned
	*/
	return (*mem1 < *mem2) ? -1 : *mem1 > *mem2;
}

int strCompare(const char* str1, const char* str2)
{
	/*while characters from str1 and str2 are equal and one of the characters is not terminating*/
	while (*str1 == *str2 && *str1 != TERMINATING_CHAR)
	{
		++str1;
		++str2;
	}

	/**
	* if str1 lesser than str2, -1 is returned
	* if str1 and str2 are equal, 0 is returned
	* if str1 is greater than str2, 1 is returned
	*/
	return (*str1 < *str2) ? -1 : *str1 > *str2;;
}

int strNumCompare(const char* str1, const char* str2, size_t num)
{
	if (!num)	/*num == 0*/
	{
		return 0;
	}

	/*while up to num characters from str1 and str2 are equal and one of the characters is not terminating*/
	while (--num && *str1 == *str2 && *str1 != TERMINATING_CHAR)
	{
		++str1;
		++str2;
	}

	/*
	* if str1 lesser than str2, -1 is returned
	* if str1 and str2 are equal, 0 is returned
	* if str1 is greater than str2, 1 is returned
	*/
	return (*str1 < *str2) ? -1 : *str1 > *str2;
}

void* memFindChar(const void* ptr, int value, size_t num)
{
	/*ptr converted to const unsigned char*/
	const unsigned char* mem = (const unsigned char*)ptr;
	/*value converted to unsigned char*/
	unsigned char val = (unsigned char)value;
	
	/*while up to num bytes from ptr are scanned and value not found*/
	while (num-- && *mem != val)
	{
		mem++;
	}

	return (*mem == val) ? (unsigned char*) mem : NULL;
}

char* strFindChar(const char* str, int ch)
{
	/*ch converted to char*/
	char value = (char) ch;

	/*while terminating char not reached and ch not found*/
	while (*str != TERMINATING_CHAR && *str != value)
	{
		++str;
	}

	return (*str == value) ? (char*) str : NULL;
}

size_t strSpanUntilChar(const char* str1, const char* str2)
{
	/*result*/
	size_t res = 0;
	/*pointer to character from str2 to match*/
	const char* ch;

	/*while end of str1 not reached*/
	while (*str1 != TERMINATING_CHAR)
	{
		/*first character of str2*/
		ch = str2;
		
		/*while characters from str2 not found in str1*/
		while (*ch != TERMINATING_CHAR && *ch != *str1)
		{
			ch++;
		}
		/*characters from str2 not found yet*/
		if (*ch == TERMINATING_CHAR)
		{
			str1++;
			res++;
		}
		else /*the first appearance of characters from str2*/
		{
			break;
		}
	}

	return res;
}

char* strGetSpanUntilChar(const char* str1, const char* str2)
{
	/*pointer to character from str2 to match*/
	const char* ch;

	/*while end of str1 not reached*/
	while (*str1 != TERMINATING_CHAR)
	{
		ch = str2;

		/*while characters from str2 not found in str1*/
		while (*ch != TERMINATING_CHAR && *ch != *str1)
		{
			ch++;
		}
		
		/*an appearance of characters from str2*/
		if (*ch == TERMINATING_CHAR)
		{
			str1++;
		}
		else /*the first character that does not match any of chars from str2*/
		{
			break;
		}
	}

	return (*str1 != TERMINATING_CHAR) ? (char*) str1 : NULL;
}

char* strLastChar(const char* str, int ch)
{
	/*result*/
	const char* res = str;
	/*ch converted to char*/
	char value = (char) ch;

	/*searching for the last appearance of ch in str*/
	do
	{
		if (*str == value)
		{
			res = str;
		}
	}
	while (*str++ != TERMINATING_CHAR);


	return (*res == value) ? (char*) res : NULL;
}

size_t strSpanWhileChar(const char* str1, const char* str2)
{
	/*result*/
	size_t res = 0;
	/*pointer to character from str2 to match*/
	const char* ch = str2;

	/*while end of str1 not reached*/
	while (*str1 != TERMINATING_CHAR)
	{
		/*while characters from str2 not found in str1*/
		while (*ch != TERMINATING_CHAR && *ch != *str1)
		{
			ch++;
		}

		/*an appearance of characters from str2*/
		if (*ch != TERMINATING_CHAR)
		{
			str1++;
			res++;
			ch = str2;
		}
		else /*the first character that does not match any of chars from str2*/
		{
			break;
		}
	}
	return res;
}

char* strSubstr(const char* str1, const char* str2)
{
	/*result*/
	const char* ptr1 = str1;
	/*pointer to the beginnig of str2*/
	const char* ptr2 = str2;

	/*while end of both ptrs not reached*/
	while (*str1 != TERMINATING_CHAR && *str2 != TERMINATING_CHAR)
	{
		/*characters match*/
		if (*str1 == *str2++)
		{
			str1++;
		}
		else
		{
			/*start search again from next character*/
			str1 = ++ptr1;
			/*return to the start of substring*/
			str2 = ptr2;
		}
	}
	
	return (*ptr1 != TERMINATING_CHAR && *str2 == TERMINATING_CHAR) ? (char*)ptr1 : NULL;
}

void* memSetValue(void* ptr, int value, size_t num)
{
	/*ptr converted to unsigned char**/
	unsigned char* res = (unsigned char*) ptr;
	/*value converted to unsigned char*/
	unsigned char val = (unsigned char) value;

	/*setting num bytes to value*/
	while (num--)
	{
		*res++ = (unsigned char) value;
	}

	return ptr;
}

size_t strLength(const char* str)
{
	/*result*/
	size_t res = 0;
	
	/*while terminating character not reached*/
	while (*str++ != TERMINATING_CHAR)
	{
		res++;
	}

	return res;
}

char* toMystr(char* cstr)
{
	/*result*/
	char* res = cstr;

	while (*cstr++) /* *c_str++ != 0 */
	{
		;	/* NULL */
	}

	/*changing '\0' to terminating char*/
	*cstr = TERMINATING_CHAR;
	return res;
}

char* toCStr(char* mystr)
{
	/*result*/
	char* res = mystr;

	while (*mystr++ != TERMINATING_CHAR)
	{
		;	/* NULL */
	}

	/*changing TERMINATING_CHAR to '\0'*/
	*mystr = 0;
	return res;
}

void printMystr(char* mystr)
{
	if (mystr)
	{
		while (*mystr != TERMINATING_CHAR)
		{
			putchar(*mystr++);
		}
	}
	else
	{
		printf("(null)");
	}
}