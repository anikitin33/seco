#include <stdio.h>
#include <string.h>

const char* password="letmein";

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Bitte geben Sie ein Passwort als Argument ein\n");
        return 0;
    }
    if (strcmp(argv[1], password) == 0) {
        printf("Geheimnis: U\n");
    } else {
        printf("Nein...\n");
    }
    return 0;
}
