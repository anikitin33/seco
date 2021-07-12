#include "math_lib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	double eps = 1e-7;
	
	for(int i = 1; i < argc; i++){
		
		printf("sqrt(%.3f) == %.3f\n", atof(argv[i]), heron(atof(argv[i]), eps));
	
	}
	
	return 0;
}



