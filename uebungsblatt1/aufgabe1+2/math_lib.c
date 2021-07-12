#include "math_lib.h"
#include <stdlib.h>
#include <stdio.h>

double quadriere (double value){
	return value * value;
}

extern double heron (double value, double eps){
	
	int i = 0;
	
	double x_alt, x_neu;
	
	x_alt = (1 + value) / 2;
	
	while (i < 50){
		i ++;
		x_neu = (x_alt + (value / x_alt)) / 2;
		
		if (x_alt == x_neu + eps || x_alt == x_neu - eps){
			break;
		}else{
		x_alt = x_neu;
		}
	}
	
	return x_neu;

}
