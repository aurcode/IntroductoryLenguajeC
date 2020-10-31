#include <stdio.h>
#include <string.h>

int main (int argc, const char * argv[]){

    if (strlen(argv[1])==strlen(argv[2])) {
        printf("Son del mismo tamaño");
        return 1;
    }

    if( strlen( argv[1] ) > strlen( argv[2] ) ) {
        printf("%s es el texto con más caracteres\n", argv[1]);
    } else {
            printf("%s es el texto con más caracteres\n", argv[2]);
    }
    return 0;
}