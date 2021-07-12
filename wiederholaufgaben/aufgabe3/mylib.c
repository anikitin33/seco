#include <ctype.h>
#include <string.h>

char * my_index(char *s, int c){
	for(int i = 0; i <= strlen(s); i++){
		if(*s == c){
			return s;
		}
		s++;
	}
	return NULL;
}

int my_strcasecmp(const char *s1, const char *s2){
	
	for(int a = 0; a <= strlen(s2); a++){
		if(tolower(s1[a]) < tolower(s2[a])){
			return -4;
		}else if(tolower(s1[a]) > tolower(s2[a])){
			return 1;
		}
	}
	
	return 0;
}
