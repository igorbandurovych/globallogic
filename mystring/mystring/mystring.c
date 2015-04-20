/**
* @file		mystring.h
* @brief	The header file for functions to work with mystring type
* mystring is an analog of C string that uses another terminating character
* (7 is chosen as terminating character because I don't find useful to have
* bell character in strings)
* mystring works similarly to C string with usage of another algorithms.
* @author	Igor Bandurovych
* @year		2015
*/

#include "mystring.h"	/**< functions prototypes */
#include <stdio.h>		/**< printf, putchar*/

void* my_memcpy(void* dest, const void* src, size_t num)
{
	if (!num || dest == src)	/* num == 0 */
	{
		return dest;	/*nothing to copy*/
	}

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

void* my_memmove(void* dest, const void* src, size_t num)
{
	if (!num || dest == src)	/* num == 0*/
	{
		return dest;	/*nothing to move*/
	}

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
		destination += num;
		source += num;

		/*copy num bytes from source to destination*/
		while (num--)
		{
			*--destination = *--source;
		}
	}

	return dest;
}

char* my_strcpy(char* dest, const char* src)
{
	if (dest == src)
	{
		return dest;	/*nothing to copy*/
	}

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

char* my_strncpy(char* dest, const char* src, size_t num)
{
	if (!num || dest == src)	/* num == 0*/
	{
		return dest;	/*nothing to copy*/
	}

	char* res = dest;

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

	return res;
}

char* my_strcat(char* dest, const char* src)
{
	char* res = dest;

	/*moving pointer to dest to the end of string*/
	while (*dest != TERMINATING_CHAR)
	{
		++dest;
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

char* my_strncat(char* dest, const char* src, size_t num)
{
	if (!num) /* num == 0 */
	{
		return dest;	/*nothing to concatenate*/
	}

	char* res = dest;

	/*moving pointer to dest to the end of string*/
	while (*dest != TERMINATING_CHAR)
	{
		++dest;
	}
	/*appending up to num (or all) characters from src to dest*/
	while (num-- && *src != TERMINATING_CHAR)
	{
		*dest++ = *src++;
	}

	/*appending terminating char to dest*/
	*dest = TERMINATING_CHAR;

	return res;
}

int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	if (!num || ptr1 == ptr2) /*num == 0*/
	{
		return 0;	/*nothing to compare*/
	}

	/* ptr1 and ptr2 converted to const unsigned char* */
	const unsigned char* mem1 = (const unsigned char*)ptr1;
	const unsigned char* mem2 = (const unsigned char*)ptr2;
	
	/*comparing up to num bytes*/
	while (--num && *mem1 == *mem2)
	{
		++mem1;
		++mem2;
	}

	return *mem1 - *mem2;
}

int my_strcmp(const char* str1, const char* str2)
{
	if (str1 == str2)
	{
		return 0;	/*string is equal to itself*/
	}

	/*while characters from str1 and str2 are equal and one of the characters is not terminating*/
	while (*str1 == *str2 && *str1 != TERMINATING_CHAR)
	{
		++str1;
		++str2;
	}

	return *str1 - *str2;
}

int my_strncmp(const char* str1, const char* str2, size_t num)
{
	if (!num || str1 == str2)	/*num == 0*/
	{
		return 0;	/*nothing to compare*/
	}

	/*while up to num characters from str1 and str2 are equal and one of the characters is not terminating*/
	while (--num && *str1 == *str2 && *str1 != TERMINATING_CHAR)
	{
		++str1;
		++str2;
	}

	return *str1 - *str2;
}

void* my_memchr(const void* ptr, int value, size_t num)
{
	if (!num)	/* num == 0*/
	{
		return NULL;	/*no chars in empty block*/
	}

	/*ptr converted to const unsigned char*/
	const unsigned char* mem = (const unsigned char*)ptr;
	/*value converted to unsigned char*/
	unsigned char val = (unsigned char)value;
	
	/*while up to num bytes from ptr are scanned and value not found*/
	while (num-- && *mem != val)
	{
		++mem;
	}

	return (*mem == val) ? (unsigned char*) mem : NULL;
}

char* my_strchr(const char* str, int ch)
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

size_t my_strcspn(const char* str1, const char* str2)
{
	/*result*/
	const char* res = str1;
	/*pointer to character from str2 to match*/
	const char* ch;

	/*while end of str1 not reached*/
	while (*res != TERMINATING_CHAR)
	{
		/*first character of str2*/
		ch = str2;
		
		/*while characters from str2 not found in str1*/
		while (*ch != TERMINATING_CHAR && *ch != *res)
		{
			++ch;
		}
		/*characters from str2 not found yet*/
		if (*ch == TERMINATING_CHAR)
		{
			++res;
		}
		else /*the first appearance of characters from str2*/
		{
			break;
		}
	}

	return res - str1;
}

char* my_strpbrk(const char* str1, const char* str2)
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
			++ch;
		}
		
		/*an appearance of characters from str2*/
		if (*ch == TERMINATING_CHAR)
		{
			++str1;
		}
		else /*the first character that does not match any of chars from str2*/
		{
			break;
		}
	}

	return (*str1 != TERMINATING_CHAR) ? (char*) str1 : NULL;
}

char* my_strrchr(const char* str, int ch)
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

size_t my_strspn(const char* str1, const char* str2)
{
	/*result*/
	const char* res = str1;
	/*pointer to character from str2 to match*/
	const char* ch = str2;

	/*while end of str1 not reached*/
	while (*res != TERMINATING_CHAR)
	{
		/*while characters from str2 not found in str1*/
		while (*ch != TERMINATING_CHAR && *ch != *res)
		{
			++ch;
		}

		/*an appearance of characters from str2*/
		if (*ch != TERMINATING_CHAR)
		{
			++res;
			ch = str2;
		}
		else /*the first character that does not match any of chars from str2*/
		{
			break;
		}
	}
	return res - str1;
}

char* my_strstr(const char* str1, const char* str2)
{
	if (str1 == str2)
	{
		return str1;	/*a string is a substring of itself*/
	}

	/*result*/
	const char* ptr1 = str1;
	/*pointer to the begining of str2*/
	const char* ptr2 = str2;

	/*while end of both ptrs not reached*/
	while (*str1 != TERMINATING_CHAR && *str2 != TERMINATING_CHAR)
	{
		/*characters match*/
		if (*str1 == *str2++)
		{
			++str1;
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

void* my_memset(void* ptr, int value, size_t num)
{
	if (!num)	/* num == 0*/
	{
		return ptr;	/*nothing to set*/
	}
	
	/*ptr converted to unsigned char**/
	unsigned char* res = (unsigned char*) ptr;
	/*value converted to unsigned char*/
	unsigned char val = (unsigned char) value;

	/*setting num bytes to value*/
	while (num--)
	{
		*res++ = val;
	}

	return ptr;
}

size_t my_strlen(const char* str)
{
	const char* res = str;

	/*while terminating character not reached*/
	while (*res != TERMINATING_CHAR)
	{
		++res;
	}

	return res - str;
}

char* to_mystr(char* cstr)
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

char* to_cstr(char* mystr)
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

void print_mystr(const char* mystr)
{
	if (mystr)
	{
		char* end = (char*) mystr;
		while (*end != TERMINATING_CHAR)
		{
			++end;
		}
		/*terminating char in C-string*/
		*end = '\0';
		printf(mystr);
		/*returning to previous value*/
		*end = TERMINATING_CHAR;
	}
	else
	{
		printf("(null)");
	}
}