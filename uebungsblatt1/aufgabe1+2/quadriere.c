#include "math_lib.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	for(int i = 1; i < argc; i++){
		
		printf("%.3f**2 == %.3f\n", atof(argv[i]), quadriere(atof(argv[i])));
	
	}
	
	return 0;
}



