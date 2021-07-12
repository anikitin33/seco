
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

	char s1[] = "012345678";
	char s2[] = "0123456789";
	char *dest;
	int i;
	
	strncpy(s1, s2, sizeof(s1) - 1);
	
	dest = (char*) malloc(strlen(s1));
	
	printf("%ld - %ld\n", strlen(s1), sizeof(s1));
	
	for(i = 0; i < strlen(s1) - 1; ++i){
		
		dest[i] = s1[i];
		
	}
	
	dest[i] = '\0';
	printf("dest = %s\n", dest);
	
	free(dest);
}
