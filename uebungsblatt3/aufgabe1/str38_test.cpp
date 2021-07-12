#include <gtest/gtest.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
	#include "str38.h"
}

TEST(misc, WideStringsWithNarrowStringFunctions)
{
	wchar_t wide_str1[] = L"0123456789";
	wchar_t wide_str2[] = L"0000000000";
	
	WideStringsWithNarrowStringFunctions(wide_str1, wide_str2);
	
	
	for(long unsigned i = 0; i < wcslen(wide_str1); i++){
		ASSERT_EQ(wide_str1[i],wide_str2[i]);	
	}
	
}

TEST(misc, WideStringsWithNarrowStringFunctions_bad)
{
	wchar_t wide_str1[] = L"0123456789";
	wchar_t wide_str2[] = L"0000000000";
	
	WideStringsWithNarrowStringFunctions_bad(wide_str1, wide_str2);
	
	size_t len1 = wcslen(wide_str1);
	size_t len2 = wcslen(wide_str2);
	
	ASSERT_NE(len1,len2);	
}


TEST(misc, NarrowStringsWithWideStringFunctions)
{
	char narrow_str1[] = "0123456789";
	char narrow_str2[] = "0000000000";
	
	NarrowStringsWithWideStringFunctions(narrow_str1, narrow_str2);
	
	
	for(long unsigned i = 0; i < strlen(narrow_str1); i++){
		ASSERT_EQ(narrow_str1[i],narrow_str2[i]);	
	}
	
}
/*
TEST(misc, NarrowStringsWithWideStringFunctions_bad)
{
	char narrow_str3[] = "01234567890123456789";
	char narrow_str4[] = "0000000000";
	
	NarrowStringsWithWideStringFunctions_bad(narrow_str3, narrow_str4);
	
	
	for(long unsigned i = 0; i < strlen(narrow_str4); i++){
		ASSERT_EQ(narrow_str3[i],narrow_str4[i]);	
	}
	
}
*/
TEST(misc, DynamicAllocationWithStrlen_bad)
{
	wchar_t wide_str1[] = L"0123456789";
	
	int badlength = DynamicAllocationWithStrlen_bad(wide_str1);

	ASSERT_NE(wcslen(wide_str1),badlength); 
}

TEST(misc, DynamicAllocationWithStrlen)
{
	wchar_t wide_str1[] = L"0123456789";
	
	int goodlength = DynamicAllocationWithStrlen(wide_str1);

	ASSERT_EQ(wcslen(wide_str1),goodlength); 
}
