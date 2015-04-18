#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

void testMystring(void)
{
	puts("Testing mystring: \n");

	char str1[40] = "Sample String\a";
	char str2[40] = "\a";
	printf("str1 = \"");
	print_mystr(str1);
	printf("\"\n");
	printf("str2 = \"");
	print_mystr(str2);
	printf("\"\n\n");

	puts("Testing memcpy: ");
	printf("my_memcpy(str1 + 3, str1, 6) = \"");
	print_mystr(my_memcpy(str1 + 3, str1, 6));
	printf("\"\n\n");

	puts("Testing strcpy: ");
	printf("my_strcpy(str1, str2) = \"");
	print_mystr(my_strcpy(str1, str2));
	printf("\"\n");
	printf("my_strcpy(str1, \"Sample String\") = \"");
	print_mystr(my_strcpy(str1, "Sample String\a"));
	printf("\"\n\n");

	puts("Testing memmove: ");
	printf("my_memmove(str1 + 3, str1, 6) = \"");
	print_mystr(my_memmove(str1 + 3, str1, 6));
	printf("\"\n\n");

	puts("Testing strncpy: ");
	printf("my_strncpy(str1, str2, 0) = \"");
	print_mystr(my_strncpy(str1, str2, 0));
	printf("\"\n");
	printf("my_strncpy(str2, str1, 20) = \"");
	print_mystr(my_strncpy(str2, str1, 20));
	printf("\"\n\n");

	puts("Testing strcat: ");
	printf("my_strcat(str1, str2) = \"");
	print_mystr(my_strcat(str1, str2));
	printf("\"\n");
	printf("my_strcat(str1, \"\") = \"");
	print_mystr(my_strcat(str1, "\a"));
	printf("\"\n\n");

	puts("Testing strncat: ");
	printf("my_strncat(str1, str2, 0) = \"");
	print_mystr(my_strncat(str1, str2, 0));
	printf("\"\n");
	printf("my_strncat(str1, str2, 3) = \"");
	print_mystr(my_strncat(str1, str2, 3));
	printf("\"\n\n");

	puts("Testing memcmp: ");
	printf("my_memcmp(str1, str2, 0) = ");
	printf("%d", my_memcmp(str1, str2, 0));
	printf("\n");
	printf("my_memcmp(str1, str2, 40) = ");
	printf("%d", my_memcmp(str1, str2, 40));
	printf("\n");
	printf("my_memcmp(str2, str1, 40) = ");
	printf("%d", my_memcmp(str2, str1, 40));
	printf("\n\n");

	puts("Testing strcmp: ");
	printf("my_strcmp(str1, str2) = ");
	printf("%d", my_strcmp(str1, str2));
	printf("\n");
	printf("my_strcmp(str2, \"\") = ");
	printf("%d", my_strcmp(str2, "\a"));
	printf("\n\n");

	puts("Testing strncmp: ");
	printf("my_strncmp(str1, str2, 0) = ");
	printf("%d", my_strncmp(str1, str2, 0));
	printf("\n");
	printf("my_strncmp(str1, str2, 40) = ");
	printf("%d", my_strncmp(str1, str2, 40));
	printf("\n");
	printf("my_strncmp(str2, str1, 40) = ");
	printf("%d", my_strncmp(str2, str1, 40));
	printf("\n\n");

	puts("Testing memchr: ");
	printf("my_memchr(str1, 'z', 0) = \"");
	print_mystr(my_memchr(str1, 'z', 0));
	printf("\"\n");
	printf("my_memchr(str1, 'r', 40) = \"");
	print_mystr(my_memchr(str1, 'r', 40));
	printf("\"\n");
	printf("my_memchr(str2, 'z', 40) = \"");
	print_mystr(my_memchr(str2, 'z', 40));
	printf("\"\n\n");

	puts("Testing strchr: ");
	printf("my_strchr(str1, 'z') = \"");
	print_mystr(my_strchr(str1, 'z'));
	printf("\"\n");
	printf("my_strchr(str1, 'r') = \"");
	print_mystr(my_strchr(str1, 'r'));
	printf("\"\n");
	printf("my_strchr(str2, '\\a') = \"");
	print_mystr(my_strchr(str2, '\a'));
	printf("\"\n\n");

	puts("Testing strcspn: ");
	printf("my_strcspn(str1, str2) = ");
	printf("%d", my_strcspn(str1, str2));
	printf("\n");
	printf("my_strcspn(str1, \"ghb\") = ");
	printf("%d", my_strcspn(str1, "ghb\a"));
	printf("\n");
	printf("my_strcspn(str1, \"\\a\") = ");
	printf("%d", my_strcspn(str1, "\a"));
	printf("\n\n");

	puts("Testing strpbrk: ");
	printf("my_strpbrk(str1, str2) = \"");
	print_mystr(my_strpbrk(str1, str2));
	printf("\"\n");
	printf("my_strpbrk(str1, \"ghb\") = \"");
	print_mystr(my_strpbrk(str1, "ghb\a"));
	printf("\"\n");
	printf("my_strpbrk(str1, \"\\a\") = \"");
	print_mystr(my_strpbrk(str1, "\a"));
	printf("\"\n\n");

	puts("Testing strrchr: ");
	printf("my_strrchr(str1, 'n') = \"");
	print_mystr(my_strrchr(str1, 'n'));
	printf("\"\n");
	printf("my_strrchr(str1, 'S') = \"");
	print_mystr(my_strrchr(str1, 'S'));
	printf("\"\n");
	printf("my_strrchr(str1, '\\a\') = \"");
	print_mystr(my_strrchr(str1, '\a'));
	printf("\"\n\n");

	puts("Testing strspn: ");
	printf("my_strspn(str1, str2) = ");
	printf("%d", my_strspn(str1, str2));
	printf("\n");
	printf("my_strspn(str1, \"gShb\") = ");
	printf("%d", my_strspn(str1, "gShb\a"));
	printf("\n");
	printf("my_strspn(str1, \"\\a\") = ");
	printf("%d", my_strspn(str1, "\a"));
	printf("\n\n");

	puts("Testing strstr: ");
	printf("my_strstr(str1, str2) = \"");
	print_mystr(my_strstr(str1, str2));
	printf("\"\n");
	printf("my_strstr(str1, \"ngSa\") = \"");
	print_mystr(my_strstr(str1, "ngSa\a"));
	printf("\"\n");
	printf("my_strstr(str1, \"\\a\") = \"");
	print_mystr(my_strstr(str1, "\a"));
	printf("\"\n\n");

	puts("Testing memset: ");
	printf("my_memset(str2, '\\a', 0) = \"");
	print_mystr(my_memset(str2, '\a', 0));
	printf("\"\n");
	printf("my_memset(str2, '\\a', 20) = \"");
	print_mystr(my_memset(str2, '\a', 20));
	printf("\"\n");
	printf("my_memset(str1, 'c', 6) = \"");
	print_mystr(my_memset(str1, 'c', 6));
	printf("\"\n\n");

	puts("Testing strlen: ");
	printf("my_strlen(str1) = ");
	printf("%d", my_strlen(str1));
	printf("\n");
	printf("my_strlen(\"gShb\") = ");
	printf("%d", my_strlen("gShb\a"));
	printf("\n");
	printf("my_strlen(str2) = ");
	printf("%d", my_strlen(str2));
	printf("\n\n");
}

void testString(void)
{
	puts("Testing C-string: \n");

	char str1[40] = "Sample String";
	char str2[40] = "";
	printf("str1 = \"%s\"\n", str1);
	printf("str2 = \"%s\"\n", str2);

	puts("\nTesting memcpy: ");
	printf("memcpy(str1 + 3, str1, 6) = \"%s\"\n\n", memcpy(str1 + 3, str1, 6));

	puts("Testing strcpy: ");
	printf("strcpy(str1, str2) = \"%s\"\n", strcpy(str1, str2));
	printf("strcpy(str1, \"Sample String\") = \"%s\"\n\n", strcpy(str1, "Sample String"));

	puts("Testing memmove: ");
	printf("memmove(str1 + 3, str1, 6) = \"%s\"\n\n", memmove(str1 + 3, str1, 6));

	puts("Testing strncpy: ");
	printf("strncpy(str1, str2, 0) = \"%s\"\n", strncpy(str1, str2, 0));
	printf("strncpy(str2, str1, 20) = \"%s\"\n\n", strncpy(str2, str1, 20));

	puts("Testing strcat: ");
	printf("strcat(str1, str2) = \"%s\"\n", strcat(str1, str2));
	printf("strcat(str1, \"\") = \"%s\"\n\n", strcat(str1, ""));

	puts("Testing strncat: ");
	printf("strncat(str1, str2, 0) = \"%s\"\n", strncat(str1, str2, 0));
	printf("strncat(str1, str2, 3) = \"%s\"\n\n", strncat(str1, str2, 3));

	puts("Testing memcmp: ");
	printf("memcmp(str1, str2, 0) = %d", memcmp(str1, str2, 0));
	printf("\n");
	printf("memcmp(str1, str2, 40) = %d", memcmp(str1, str2, 40));
	printf("\n");
	printf("memcmp(str2, str1, 40) = %d", memcmp(str2, str1, 40));
	printf("\n\n");

	puts("Testing strcmp: ");
	printf("strcmp(str1, str2) = %d", strcmp(str1, str2));
	printf("\n");
	printf("strcmp(str2, \"\") = %d", strcmp(str2, ""));
	printf("\n\n");

	puts("Testing strncmp: ");
	printf("strncmp(str1, str2, 0) = %d", strncmp(str1, str2, 0));
	printf("\n");
	printf("strncmp(str1, str2, 40) = %d", strncmp(str1, str2, 40));
	printf("\n");
	printf("strncmp(str2, str1, 40) = %d", strncmp(str2, str1, 40));
	printf("\n\n");

	puts("Testing memchr: ");
	printf("memchr(str1, 'z', 0) = \"%s\"\n", memchr(str1, 'z', 0));
	printf("memchr(str1, 'r', 40) = \"%s\"\n", memchr(str1, 'r', 40));
	printf("memchr(str2, 'z', 40) = \"%s\"\n\n", memchr(str2, 'z', 40));

	puts("Testing strchr: ");
	printf("strchr(str1, 'z') = \"%s\"\n", strchr(str1, 'z'));
	printf("strchr(str1, 'r') = \"%s\"\n", strchr(str1, 'r'));
	printf("strchr(str2, '\\0') = \"%s\"\n\n", strchr(str2, '\0'));

	puts("Testing strcspn: ");
	printf("strcspn(str1, str2) = %d", strcspn(str1, str2));
	printf("\n");
	printf("strcspn(str1, \"ghb\") = %d", strcspn(str1, "ghb"));
	printf("\n");
	printf("strcspn(str1, \"\\0\") = %d", strcspn(str1, ""));
	printf("\n\n");

	puts("Testing strpbrk: ");
	printf("strpbrk(str1, str2) = \"%s\"\n", strpbrk(str1, str2));
	printf("strpbrk(str1, \"ghb\") = \"%s\"\n", strpbrk(str1, "ghb"));
	printf("strpbrk(str1, \"\\0\") = \"%s\"\n\n", strpbrk(str1, ""));

	puts("Testing strrchr: ");
	printf("strrchr(str1, 'n') = \"%s\"\n", strrchr(str1, 'n'));
	printf("strrchr(str1, 'S') = \"%s\"\n", strrchr(str1, 'S'));
	printf("strrchr(str1, '\\0\') = \"%s\"\n\n", strrchr(str1, '\0'));

	puts("Testing strspn: ");
	printf("strspn(str1, str2) = %d", strspn(str1, str2));
	printf("\n");
	printf("strspn(str1, \"gShb\") = %d", strspn(str1, "gShb"));
	printf("\n");
	printf("strspn(str1, \"\\0\") = %d", strspn(str1, ""));
	printf("\n\n");

	puts("Testing strstr: ");
	printf("strstr(str1, str2) = \"%s\"\n", strstr(str1, str2));
	printf("strstr(str1, \"ngSa\") = \"%s\"\n", strstr(str1, "ngSa"));
	printf("strstr(str1, \"\\0\") = \"%s\"\n\n", strstr(str1, ""));

	puts("Testing memset: ");
	printf("memset(str2, '\\0', 0) = \"%s\"\n", memset(str2, '\0', 0));
	printf("memset(str2, '\\0', 20) = \"%s\"\n", memset(str2, '\0', 20));
	printf("memset(str1, 'c', 6) = \"%s\"\n\n", memset(str1, 'c', 6));

	puts("Testing strlen: ");
	printf("strlen(str1) = %d", strlen(str1));
	printf("\n");
	printf("strlen(\"gShb\") = %d", strlen("gShb"));
	printf("\n");
	printf("strlen(str2) = %d", strlen(str2));
	printf("\n\n");
}

#include <time.h>

int main(void)
{
	testMystring();
	testString();
	char str1[40] = "nnnnnns\a";
	char str2[40] = "nnnnnns";
	
	
	clock_t start = clock();

	for (size_t i = 0; i < 100000000; ++i)
	{
		my_strstr(str1, str1);
	}

	printf("%d\n", clock() - start);


	start = clock();

	for (size_t i = 0; i < 100000000; ++i)
	{
		strstr(str2, str2);
	}

	printf("%d\n", clock() - start);

	system("pause");
	return 0;
}