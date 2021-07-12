#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	
	unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[3]);
	
	char *operator = argv[2];
	
	if(strcmp(operator,"or") == 0){
		printf("%d \n", a || b);
	}
	
	if(strcmp(operator,"and") == 0){
		printf("%d \n", a && b);
	}
	
	if(strcmp(operator,"xor") == 0){
		printf("%d \n", a != b);
	}
	
	return 0;
}
