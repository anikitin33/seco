#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "str38.h"
  
//end earlier than anticipated
void WideStringsWithNarrowStringFunctions_bad(wchar_t wide_str1[], wchar_t wide_str2[]) {
	
	strncpy(wide_str2, wide_str1, 10);
	
}

//insufficient memory to store the result of the copy and the copy will result in a buffer overflow
void NarrowStringsWithWideStringFunctions_bad(char narrow_str1[], char narrow_str2[]) {
	
	wcsncpy(narrow_str2, narrow_str1, 10);
	
}

void WideStringsWithNarrowStringFunctions(wchar_t wide_str1[], wchar_t wide_str2[]) {
	
	/* wcsncpy() for wide character  strings*/
	wcsncpy(wide_str2, wide_str1, 10);
	
}

void NarrowStringsWithWideStringFunctions(char narrow_str1[], char narrow_str2[]) {
	
	/* strncpy() for narrow character strings*/
	strncpy(narrow_str2, narrow_str1, 10);
	
}

int DynamicAllocationWithStrlen(wchar_t wide_str1[]) {
	
	wchar_t *wide_str2 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t));
	
	if (wide_str2 == NULL) {
		return 0;
	}
	size_t len1 = wcslen(wide_str1); //Right way
	size_t len2 = strlen(wide_str1); //Wrong way
	printf("Right size=%2zd Wrong size=%2zd New string size=%2zd\n\n",len1,len2,sizeof(wide_str2));
	free(wide_str2);
	wide_str2 = NULL;
	return len1;
}

int DynamicAllocationWithStrlen_bad(wchar_t wide_str1[]) {
	
	wchar_t *wide_str2 = (wchar_t*)malloc(strlen(wide_str1) + 1);
	
	if (wide_str2 == NULL) {
		return 0;
	}
	
	/* ... */
	size_t len1 = wcslen(wide_str1); //Right way
	size_t len2 = strlen(wide_str1); //Wrong way
	printf("Length with wcslen size=%2zd Length with strlen size=%2zd\n\n", len1,len2);
	free(wide_str2);
	wide_str2 = NULL;
	return len2;
}
