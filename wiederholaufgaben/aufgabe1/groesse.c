#include <stdio.h>

	int main(int argc, const char * argv[]) {
		
	size_t size;

	size = sizeof(char);
	printf("char: %lu\n", size);
	
	size = sizeof(short);
	printf("char: %lu\n", size);
	
	size = sizeof(int);
	printf("char: %lu\n", size);
	
	size = sizeof(unsigned int);
	printf("char: %lu\n", size);
	
	size = sizeof(int *);
	printf("char: %lu\n", size);
	
	size = sizeof(char *);
	printf("char: %lu\n", size);
	
	size = sizeof(long);
	printf("char: %lu\n", size);
	
	size = sizeof(long long);
	printf("char: %lu\n", size);
		
    return 0;
}
