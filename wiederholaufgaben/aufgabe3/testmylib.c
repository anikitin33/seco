#include <stdio.h>
#include <string.h>
#include "mylib.h"

int main(int argc, char *argv[]) {
	
	if(strcmp(argv[1], "index") == 0){
		
		char *haystack = argv[2];
		char needle = *argv[3];
		
		char *found_pointer = index(haystack, needle);
		char *result_pointer = my_index(haystack, needle);
		
		if(result_pointer == NULL && found_pointer == NULL){
		
		}else if(*result_pointer != *found_pointer){
			printf("%c\n", *result_pointer);
			printf("%c\n", *found_pointer);
		}
		
	}else if(strcmp(argv[1], "strcasecmp") == 0){
	
		char *s1 = argv[2];
		char *s2 = argv[3];
		
		int which1 = my_strcasecmp(s1,s2);
		int which2 = strcasecmp(s1,s2);
		
		if(which1 != which2){
			printf("%d\n", which1);
			printf("%d\n", which2);
		}
	}
	
	return 0;

}

