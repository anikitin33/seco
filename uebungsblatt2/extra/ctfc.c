#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "geheimnisc.h"
// definiert als enum { geheimnisc='*' };

const size_t ilen = 5;
const size_t clen = ilen*sizeof(int);

const uint32_t code = 0xcafebabe;

uint32_t check_password(const char *p){
	uint32_t *ip = (uint32_t *) p;
	uint32_t ccode = 0;
	for (size_t i=0; i<ilen; i++){
		ccode += ip[i];
	}
	return ccode;
}

int main(int argc, const char* argv[]) {
	if (argc != 2) {
        printf("Bitte geben Sie einen Code als Argument ein\n");
		return 0;
	}
    size_t alen = strlen(argv[1]);
	if (alen != clen) {
		printf("Code muss genau %zd (nicht %zd) Bytes sein\n", clen, alen);
		return 0;
	}
	if (code == check_password(argv[1])) {
        printf("Geheimnis: %c\n", geheimnisc);
        return 0;
    } else {
        printf("Nein...\n");
        return -1;
    }
}
