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
	printMystr(str1);
	printf("\"\n");
	printf("str2 = \"");
	printMystr(str2);
	printf("\"\n\n");

	puts("Testing memcpy: ");
	printf("memCopy(str1 + 3, str1, 6) = \"");
	printMystr(memCopy(str1 + 3, str1, 6));
	printf("\"\n\n");

	puts("Testing strcpy: ");
	printf("strCopy(str1, str2) = \"");
	printMystr(strCopy(str1, str2));
	printf("\"\n");
	printf("strCopy(str1, \"Sample String\") = \"");
	printMystr(strCopy(str1, "Sample String\a"));
	printf("\"\n\n");

	puts("Testing memmove: ");
	printf("memMove(str1 + 3, str1, 6) = \"");
	printMystr(memMove(str1 + 3, str1, 6));
	printf("\"\n\n");

	puts("Testing strncpy: ");
	printf("strNumCopy(str1, str2, 0) = \"");
	printMystr(strNumCopy(str1, str2, 0));
	printf("\"\n");
	printf("strNumCopy(str2, str1, 20) = \"");
	printMystr(strNumCopy(str2, str1, 20));
	printf("\"\n\n");

	puts("Testing strcat: ");
	printf("strConcat(str1, str2) = \"");
	printMystr(strConcat(str1, str2));
	printf("\"\n");
	printf("strConcat(str1, \"\") = \"");
	printMystr(strConcat(str1, "\a"));
	printf("\"\n\n");

	puts("Testing strncat: ");
	printf("strNumConcat(str1, str2, 0) = \"");
	printMystr(strNumConcat(str1, str2, 0));
	printf("\"\n");
	printf("strNumConcat(str1, str2, 3) = \"");
	printMystr(strNumConcat(str1, str2, 3));
	printf("\"\n\n");

	puts("Testing memcmp: ");
	printf("memCompare(str1, str2, 0) = ");
	printf("%d", memCompare(str1, str2, 0));
	printf("\n");
	printf("memCompare(str1, str2, 40) = ");
	printf("%d", memCompare(str1, str2, 40));
	printf("\n");
	printf("memCompare(str2, str1, 40) = ");
	printf("%d", memCompare(str2, str1, 40));
	printf("\n\n");

	puts("Testing strcmp: ");
	printf("strCompare(str1, str2) = ");
	printf("%d", strCompare(str1, str2));
	printf("\n");
	printf("strCompare(str2, \"\") = ");
	printf("%d", strCompare(str2, "\a"));
	printf("\n\n");

	puts("Testing strncmp: ");
	printf("strNumCompare(str1, str2, 0) = ");
	printf("%d", strNumCompare(str1, str2, 0));
	printf("\n");
	printf("strNumCompare(str1, str2, 40) = ");
	printf("%d", strNumCompare(str1, str2, 40));
	printf("\n");
	printf("strNumCompare(str2, str1, 40) = ");
	printf("%d", strNumCompare(str2, str1, 40));
	printf("\n\n");

	puts("Testing memchr: ");
	printf("memFindChar(str1, 'z', 0) = \"");
	printMystr(memFindChar(str1, 'z', 0));
	printf("\"\n");
	printf("memFindChar(str1, 'r', 40) = \"");
	printMystr(memFindChar(str1, 'r', 40));
	printf("\"\n");
	printf("memFindChar(str2, 'z', 40) = \"");
	printMystr(memFindChar(str2, 'z', 40));
	printf("\"\n\n");

	puts("Testing strchr: ");
	printf("strFindChar(str1, 'z') = \"");
	printMystr(strFindChar(str1, 'z'));
	printf("\"\n");
	printf("strFindChar(str1, 'r') = \"");
	printMystr(strFindChar(str1, 'r'));
	printf("\"\n");
	printf("strFindChar(str2, '\\a') = \"");
	printMystr(strFindChar(str2, '\a'));
	printf("\"\n\n");

	puts("Testing strcspn: ");
	printf("strSpanUntilChar(str1, str2) = ");
	printf("%d", strSpanUntilChar(str1, str2));
	printf("\n");
	printf("strSpanUntilChar(str1, \"ghb\") = ");
	printf("%d", strSpanUntilChar(str1, "ghb\a"));
	printf("\n");
	printf("strSpanUntilChar(str1, \"\\a\") = ");
	printf("%d", strSpanUntilChar(str1, "\a"));
	printf("\n\n");

	puts("Testing strpbrk: ");
	printf("strGetSpanUntilChar(str1, str2) = \"");
	printMystr(strGetSpanUntilChar(str1, str2));
	printf("\"\n");
	printf("strGetSpanUntilChar(str1, \"ghb\") = \"");
	printMystr(strGetSpanUntilChar(str1, "ghb\a"));
	printf("\"\n");
	printf("strGetSpanUntilChar(str1, \"\\a\") = \"");
	printMystr(strGetSpanUntilChar(str1, "\a"));
	printf("\"\n\n");

	puts("Testing strrchr: ");
	printf("strLastChar(str1, 'n') = \"");
	printMystr(strLastChar(str1, 'n'));
	printf("\"\n");
	printf("strLastChar(str1, 'S') = \"");
	printMystr(strLastChar(str1, 'S'));
	printf("\"\n");
	printf("strLastChar(str1, '\\a\') = \"");
	printMystr(strLastChar(str1, '\a'));
	printf("\"\n\n");

	puts("Testing strspn: ");
	printf("strSpanWhileChar(str1, str2) = ");
	printf("%d", strSpanWhileChar(str1, str2));
	printf("\n");
	printf("strSpanWhileChar(str1, \"gShb\") = ");
	printf("%d", strSpanWhileChar(str1, "gShb\a"));
	printf("\n");
	printf("strSpanWhileChar(str1, \"\\a\") = ");
	printf("%d", strSpanWhileChar(str1, "\a"));
	printf("\n\n");

	puts("Testing strstr: ");
	printf("strSubstr(str1, str2) = \"");
	printMystr(strSubstr(str1, str2));
	printf("\"\n");
	printf("strSubstr(str1, \"ngSa\") = \"");
	printMystr(strSubstr(str1, "ngSa\a"));
	printf("\"\n");
	printf("strSubstr(str1, \"\\a\") = \"");
	printMystr(strSubstr(str1, "\a"));
	printf("\"\n\n");

	puts("Testing memset: ");
	printf("memSetValue(str2, '\\a', 0) = \"");
	printMystr(memSetValue(str2, '\a', 0));
	printf("\"\n");
	printf("memSetValue(str2, '\\a', 20) = \"");
	printMystr(memSetValue(str2, '\a', 20));
	printf("\"\n");
	printf("memSetValue(str1, 'c', 6) = \"");
	printMystr(memSetValue(str1, 'c', 6));
	printf("\"\n\n");

	puts("Testing strlen: ");
	printf("strLength(str1) = ");
	printf("%d", strLength(str1));
	printf("\n");
	printf("strLength(\"gShb\") = ");
	printf("%d", strLength("gShb\a"));
	printf("\n");
	printf("strLength(str2) = ");
	printf("%d", strLength(str2));
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

int main(void)
{
	testMystring();
	testString();
	system("pause");
	return 0;
}