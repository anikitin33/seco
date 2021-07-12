#include <stdlib.h>
#include <stdio.h>
#include "str38.h"
#include <wchar.h>

int main(){
	
	printf("WideStringsWithNarrowStringFunctions\n---\n");
	
	wchar_t wide_str1[] = L"0123456789";
	wchar_t wide_str2[] = L"0000000000";

	printf("Before: %ls - %ls\n", wide_str1, wide_str2);
	
	WideStringsWithNarrowStringFunctions(wide_str1, wide_str2);
	
	printf("After: %ls - %ls\n\n", wide_str1, wide_str2);
	
	
	//----------------------------------------------------------
	
	printf("NarrowStringsWithWideStringFunctions\n---\n");
	
	char narrow_str1[] = "0123456789";
	char narrow_str2[] = "0000000000";
	
	printf("Before: %s - %s\n", narrow_str1, narrow_str2);
	
	NarrowStringsWithWideStringFunctions(narrow_str1, narrow_str2);
	
	printf("After: %s - %s\n\n", narrow_str1, narrow_str2);
	
	//----------------------------------------------------------
	
	DynamicAllocationWithStrlen_bad(wide_str1);
	//----------------------------------------------------------
	DynamicAllocationWithStrlen(wide_str1);
	
	//----------------------------------------------------------
	printf("WideStringsWithNarrowStringFunctions_bad\n---\n");
	
	wchar_t wide_str3[] = L"0000000000";
	
	printf("Before: %ls - %ls\n", wide_str1, wide_str3);
	
	WideStringsWithNarrowStringFunctions_bad(wide_str1, wide_str3);
	
	printf("After: %ls - %ls\n\n", wide_str1, wide_str3);
	//----------------------------------------------------------
	printf("NarrowStringsWithWideStringFunctions_bad\n---\n");
	
	char narrow_str3[] = "01234567890123456789";
	char narrow_str4[] = "0000000000";
	
	printf("Before: %s - %s\n", narrow_str3, narrow_str4);
	
	NarrowStringsWithWideStringFunctions_bad(narrow_str3, narrow_str4);
	
	printf("After: %s - %s\n\n", narrow_str3, narrow_str4);
	return 0;
}
