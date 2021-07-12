#ifndef STR38
#define STR38

extern void WideStringsWithNarrowStringFunctions_bad(wchar_t wide_str1[], wchar_t wide_str2[]);
extern void NarrowStringsWithWideStringFunctions_bad(char narrow_str1[], char narrow_str2[]);

extern void WideStringsWithNarrowStringFunctions(wchar_t wide_str1[], wchar_t wide_str2[]);
extern void NarrowStringsWithWideStringFunctions(char narrow_str1[], char narrow_str2[]);

extern int DynamicAllocationWithStrlen_bad(wchar_t wide_str1[]);
extern int DynamicAllocationWithStrlen(wchar_t wide_str1[]);
#endif
