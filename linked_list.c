#include <stdio.h>
#include <stdlib.h>

//definir el nodo
typedef struct Node {
    int number; //Lista de numeros
    struct Node * next; //estructura autoreferenciada
} NODE; // en vez de "struct Node" solo pones NODE

//crear funcion que crea un nuevo nodo
NODE * createNode( int number ){
    NODE * newNode;

    newNode = malloc( sizeof(NODE) );
    newNode->next = NULL; //el siguiente del nodo sera NULL
    newNode->number = number; //asignar el dato number al puntero newNode

    return newNode;
}

int main ( int argc, const char * argv[] ) {
    //creando la lista
    NODE * start = NULL, *current, *next; //crea puntero start con NULL para poner la lista vacia
    // current puntero auxiliar

    char goOn; //bandera de continuacion, goOn puede ser int tambien
    int listSize = 0, number; //listSize es el tamaño de la lista

    do {
        printf("La lista contiene %d nodos. Ingrese el siguiente número (0 para finalizar)\n", listSize);
        scanf("%d",&number);
        if( number ) { // Si el number es distinto de 0 continua
            if( !start ) { // Si start = NULL se crea el NODO (lista vacia)
                start = createNode( number );
                listSize++;
            } else {
                current = start;
                while(current->next){
                    current = current->next;
                }
                current->next = createNode(number);
                listSize++;
            }
            goOn =  1;
        } else {
            goOn = 0;
        }
    } while( goOn );

    current = start;
    printf( "La lisa contiene los numeros: \n" );
    while (current) {
        printf( "%d", current->number );
        printf( current->next ? ", " : "\n" );
        current = current->next;
    }
    current = start;
    while (current) {
        next = current-> next;
        printf( "%d", current->number );
        free( current );
        current = next;
    }

    return 0;
}
