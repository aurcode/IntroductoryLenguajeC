#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definiendo limtes a variables
typedef char NAME[100];
typedef char EMAIL[100];

// Definiendo estructura de un contacto
typedef struct {
    NAME name;
    EMAIL email;
} CONTACT;

int main(int argc, const char * argv[]){
    // Inicializando variables
    CONTACT * list = NULL; // La lista para guardar
    char buffer[100]; // La entrada del usuario
    int goOn, listSize = 0; // Contadores para el loop

    do{
        // Obteniendo nombre
        printf("Intrese el nombre del nuevo contacto (0 para terminar):\n");
        scanf("%99s", buffer);

            // Si es 0, termina
            if(strcmp("0", buffer) != 0) {

                // Verifica si ya hay contactos en la lista
                if(!list){
                    // Guarda espacio en memoria para el primer contacto
                    list = malloc(sizeof( CONTACT ));
                } else {
                    // Si ya hay un contacto, guarda espacio en memoria para otros contactos
                    list = realloc( list, sizeof(CONTACT) * (listSize+1) );
                }

                //Copiamos los datos recibidos en la lista
                strcpy( list[listSize].name, buffer );

                // Obteniendo email
                printf("Ingrese el email de esta persona de %s:\n", buffer);
                scanf("%99s", buffer);

                //Copiamos los datos recibidos en la lista
                strcpy(list[listSize].email, buffer);

                // Seguir con el loop
                goOn = 1;
                listSize++;
        } else {
            goOn = 0;
        }
    } while( goOn );

    // Imprmir la lista contactos que creamos

    printf("\n Esta es tu lista de contactos:\n");
    printf("Nombre\t\tEmail\n");
    for(int i = 0; i<listSize; i++){
        printf("%s\t\t\%s\n", list[i].name, list[i].email);
    }

    // Liberamos la memoria
    free(list);

    return 0;
}

