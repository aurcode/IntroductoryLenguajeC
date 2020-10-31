#include <stdio.h>
#include <stdlib.h>

int main(){
    char * p = NULL;

    for(int i=0; i<50; i++){
        printf("%d - Alojando 50 chars\n", i);
        if(p){
            free(p);
        }
        p = malloc(sizeof(char)*50);
    }
    printf("Terminado\n");
    free(p);
}
