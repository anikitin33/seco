
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void doit(void){

	char buf[16];
	gets(buf);
	
	int c1 = buf[16] < 0 ? buf[16] + 256 : buf[16];
	int c2 = buf[17] < 0 ? buf[17] + 256 : buf[17];
	int c3 = buf[18] < 0 ? buf[18] + 256 : buf[18];
	int c4 = buf[19] < 0 ? buf[19] + 256 : buf[19];
	
	int c5 = buf[20] < 0 ? buf[20] + 256 : buf[20];
	int c6 = buf[21] < 0 ? buf[21] + 256 : buf[21];
	int c7 = buf[22] < 0 ? buf[22] + 256 : buf[22];
	int c8 = buf[23] < 0 ? buf[23] + 256 : buf[23];
	
	printf("Stack Canary: 0x%02x%02x%02x%02x %02x%02x%02x%02x\n", c8, c7, c6, c5, c4, c3, c2, c1);
}

int main(void){
	
	doit();
	return 1;
}
