/**
* @file		mystring.h
* @brief	The header file for functions to work with mystring type
* mystring is an analog of C string that uses another terminating character
* (7 is chosen as terminating character because I don't find useful to have
* bell character in strings).
* @author	Igor Bandurovych
* @year		2015
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#define TERMINATING_CHAR 7 /**< terminating character for mystring */

#include <stddef.h> /**< definition of size_t*/

/**
* @brief	This function copies the values of num bytes from the location pointed by src
*			directly to the memory block pointed by dest
* @param	[in,out]	dest Pointer to the memory block to which num bytes are copied
* @param	[in]		src Pointer to the memory block from which num bytes are copied
* @param	[in]		num Number of bytes to be copied
* @warning	NULL shall not be used as a parameter of this function
* @pre		To avoid overflows, the size of the arrays pointed by both the dest and src parameters,
*			shall be at least num bytes, and should not overlap
* @post		Values of the first num bytes are directly copied from src to dest 
* @return	dest is returned
* @see		For overlapping memory blocks, use my_memmove
*/
void* my_memcpy(void* dest, const void* src, size_t num);

/**
* @brief	This function copies the values of num bytes from the location pointed by src
*			to the memory block pointed by dest. Copying takes place as if an intermediate buffer were used,
*			allowing the dest and src to overlap
* @param	[in,out]	dest Pointer to the memory block to which num bytes are copied
* @param	[in]		src Pointer to the memory block from which num bytes are copied
* @param	[in]		num Number of bytes to be copied
* @warning	NULL shall not be used as a parameter of this function
* @pre		dest and src can overlap
* @post		Values of first num bytes are copied from src to dest as if an intermediate buffer were used
* @return	dest is returned
*/
void* my_memmove(void* dest, const void* src, size_t num);

/**
* @brief	This function copies the mystring pointed by src into the array pointed by dest,
*			including the terminating character (and stopping at that point)
* @param	[in,out]	dest The array to which src is copied
* @param	[in]		src The mystring to be copied
* @warning	NULL shall not be used as a parameter of this function
* @pre		The size of the array pointed by dest shall be long enough to contain the same mystring
*			as src (including the terminating character), and should not overlap in memory with src
* @post		mystring pointed by src is copied to dest
* @return	dest is returned
*/
char* my_strcpy(char* dest, const char* src);

/**
* @brief	This function copies the first num characters of src to dest
* @param	[in,out]	dest The pointer to which src is copied
* @param	[in]		src The mystring to be copied
* @param	[in]		num Number of characters to be copied
* @warning	NULL shall not be used as a parameter of this function
* @warning	No terminating character is implicitly appended at the end of dest if src is longer than num.
*			Thus, in this case, dest shall not be considered a mystring (reading it as such would overflow)
* @remark	If the end of the source mystring (which is signaled by a terminating character) is found before
*			num characters have been copied, dest is padded with terminating character until a total of
*			num characters have been written to it
* @pre		dest and src shall not overlap
* @post		The first num bytes of src are copied to dest
* @return	dest is returned
* @see		Use my_memmove for a safer alternative when overlapping
*/
char* my_strncpy(char* dest, const char* src, size_t num);

/**
* @brief	This function appends the first num characters of src to dest, plus a terminating character
* @param	[in,out]	dest The mystring to which src is appended
* @param	[in]		src The mystring to be appended
* @warning	NULL shall not be used as a parameter of this function
* @remark	If the length of the mystring in source is less than num, only the content up to the terminating character is copied
* @pre		dest and src shall not overlap
* @post		mystring pointed by src is appended to dest
* @return	dest is returned
*/
char* my_strcat(char* dest, const char* src);

/**
* @brief	This function appends a copy of the source string to the destination string
* @param	[in,out]	dest The mystring to which src is appended
* @param	[in]		src The mystring to be appended
* @param	[in]		num Number of characters to be appended
* @warning	NULL shall not be used as a parameter of this function
* @remark	If the length of the mystring in src is less than num, only the content up
*			to the terminating character is copied
* @pre		dest and src shall not overlap
* @post		Up to the first num characters of by src are appended to dest
* @return	dest is returned
*/
char* my_strncat(char* dest, const char* src, size_t num);

/**
* @brief	This function compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2
* @param	[in]		ptr1 Pointer to the first block of memory to compare
* @param	[in]		ptr2 Pointer to the second block of memory to compare
* @param	[in]		num Number of bytes to be compared
* @post		Two blocks of memory pointed by ptr1 and ptr2 are compared
* @return	0 is returned if both blocks of memory are equal or a value different from 0 representing which is greater if they are not
*/
int my_memcmp(const void* ptr1, const void* ptr2, size_t num);

/**
* @brief	This function compares the mystring str1 to the mystring str2
* @param	[in]		str1 The first mystring to compare
* @param	[in]		str2 The second mystring to compare
* @param	[in]		num Number of bytes to be compared
* @post		Two mystrings pointed by str1 and str2 are compared
* @remark	This function starts comparing the first character of each string. If they are equal to each other,
*			it continues with the following pairs until the characters differ or until a terminating character is reached
* @remark	This function performs a binary comparison of the characters
* @return	0 is returned if both mystrings are equal or a value different from 0 representing which is greater if they are not
*/
int my_strcmp(const char* str1, const char* str2);

/**
* @brief	This function compares up to num characters of the mystring str1 to those of the mystring str2
* @param	[in]		str1 The first mystring to compare
* @param	[in]		str2 The second mystring to compare
* @param	[in]		num Number of characters to be compared
* @post		Up to num characters of two mystrings pointed by str1 and str2 are compared
* @remark	This function starts comparing the first character of each string. If they are equal to each other,
*			it continues with the following pairs until the characters differ or until a terminating character is reached,
*			or until num characters match in both strings, whichever happens first
* @remark	This function performs a binary comparison of the characters
* @return	0 is returned if num characters of both mystrings (or both mystrings) are equal or a value different from 0
*			representing which is greater if they are not
*/
int my_strncmp(const char* str1, const char* str2, size_t num);

/**
* @brief	This function searches within the first num bytes of the block of memory pointed by ptr
*			for the first occurrence of value
* @param	[in]		ptr Pointer to the block of memory where value is searched
* @param	[in]		value Value to be found
* @param	[in]		num Number of bytes to be checked
* @warning	NULL shall not be used as a parameter of this function
* @remark	value and each of the bytes checked on the the ptr array
*			are interpreted as unsigned char for the comparison
* @post		value found in the first num bytes of the block of memory pointed by ptr
* @return	A pointer to the first occurrence of value
*			(if value not found in the first num bytes of ptr, NULL is returned)
*/
void* my_memchr(const void* ptr, int value, size_t num);

/**
* @brief	This function searches within the first num bytes of the block of memory pointed by ptr
*			for the first occurrence of value
* @param	[in]		str The mystring where ch is searched
* @param	[in]		ch Character to match
* @warning	NULL shall not be used as a parameter of this function
* @remark	ch is interpreted as char for the comparison
* @remark	The terminating character is considered part of the mystring.
			Thus, it can also be located in order to retrieve a pointer to the end of a string
* @post		ch found in str
* @return	A pointer to the first occurrence of ch in the mystring str
*			(if ch is not found in str, NULL is returned)
*/
char* my_strchr(const char* str, int ch);

/**
* @brief	This function scans str1 for the first occurrence of any of the characters that are part of str2
* @param	[in]		str1 The mystring to be scanned
* @param	[in]		str2 The mystring containing characters to match
* @post		str1 is scanned for presence of any characters that are part of str2
* @remark	The search includes the terminating characters. Thus, the function will return the length of str1
*			if none of the characters of str2 are found in str1
* @return	The length of the initial part of str1 not containing any of the characters that are part of str2 is returned
*/
size_t my_strcspn(const char* str1, const char* str2);

/**
* @brief	This function scans str1 for the first occurrence of any of the characters that are part of str2
* @param	[in]		str1 The mystring to be scanned
* @param	[in]		str2 The mystring containing characters to match
* @post		str1 is scanned for presence of any characters that are part of str2
* @remark	The search does not include the terminating characters of either strings, but ends there
* @return	A pointer to the first occurrence in str1 of any of the characters that are part of str2 is returned
*			(if there are no matches NULL is returned)
*/
char* my_strpbrk(const char* str1, const char* str2);

/**
* @brief	This function scans str1 for the last occurrence of ch
* @param	[in]		str mystring where ch is searched
* @param	[in]		ch Character to match
* @warning	NULL shall not be used as a parameter of this function
* @remark	ch is interpreted as char for the comparison
* @remark	The terminating character is considered part of the mystring.
*			Thus, it can also be located in order to retrieve a pointer to the end of a string
* @post		ch found in str
* @return	A pointer to the last occurrence of ch in the mystring str
*			(if ch is not found in str, NULL is returned)
*/
char* my_strrchr(const char* str, int ch);

/**
* @brief	This function searches for the initial portion of str1 which consists only of characters that are part of str2
* @param	[in]		str1 The mystring to be scanned
* @param	[in]		str2 The mystring containing characters to match
* @post		str1 is scanned for presence of any characters that are part of str2
* @remark	The search does not include the terminating characters of either strings, but ends there
* @return	The length of the initial part of str1 containing only characters that are in str2 is returned
*/
size_t my_strspn(const char* str1, const char* str2);

/**
* @brief	This function scans str1 for the first occurrence of str2
* @param	[in]		str1 The mystring to be scanned
* @param	[in]		str2 Substring to match
* @post		str1 is scanned for presence of str2
* @remark	The matching process does not include the terminating characters, but it stops there
* @return	A pointer to the first occurrence of str2 in str1, or NULL if str2 is not part of str1
*/
char* my_strstr(const char* str1, const char* str2);

/**
* @brief	This function sets the first num bytes of the block of memory pointed by ptr to the specified value
* @param	[in,out]	ptr Pointer to the block of memory to fill 
* @param	[in]		value Value to be set
* @param	[in]		num Number of bytes to be set to value
* @warning	NULL shall not be used as a parameter of this function
* @remark	value is passed as an int, but the function fills the block of memory
*			using the unsigned char conversion of this value
* @post		The first num bytes of the block of memory pointed by ptr are set to value
* @return	ptr is returned
*/
void* my_memset(void* ptr, int value, size_t num);

/**
* @brief	This function returns the length of the mystring str
* @param	[in]		str The mystring to find the length
* @warning	NULL shall not be used as a parameter of this function
* @remark	The length of a mystring is determined by the terminating character:
*			A mystring is as long as the number of characters between the beginning of the string and
*			the terminating character (without including the terminating character itself)
* @post		The length of the mystring str is found
* @return	The length of str is returned
*/
size_t my_strlen(const char* str);

/**
* @brief	This function converts a C-string to a mystring
* @param	[in,out]	cstr The C-string to convert
* @warning	NULL shall not be used as a parameter of this function
* @remark	This function changes null-character to terminating character of mystring
* @post		cstr is converted to mystring
* @return	cstr is returned
*/
char* to_mystr(char* cstr);

/**
* @brief	This function converts a mystring to a C-string
* @param	[in,out]	mystr The mystring to convert
* @warning	NULL shall not be used as a parameter of this function
* @remark	This function changes terminating character of mystring to null-character
* @post		mystr is converted to a C-string
* @return	mystr is returned
*/
char* to_cstr(char* mystr);

/**
* @brief	This function prints a mystring to the console
* @param	[in,out]	mystr The mystring to print
* @remark	if NULL is used as parameter, "(null)" will be printed
* @post		mystr is printed to the console
* @return	void
*/
void print_mystr(const char* mystr);

#endif /*MYSTRING_H*/