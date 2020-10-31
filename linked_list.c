#include <stdio.h>
#include <stdlib.h>

// Definir el nodo
typedef struct Node {
    int number; // Lista de numeros
    struct Node * next; // Estructura autoreferenciada
} NODE; // En vez de "struct Node" solo pones NODE

// Crear funcion que crea un nuevo nodo
NODE * createNode( int number ){
    NODE * newNode;

    newNode = malloc( sizeof(NODE) );
    newNode->next = NULL; // El siguiente del nodo sera NULL
    newNode->number = number; // Asignar el dato number al puntero newNode

    return newNode;
}

int main ( int argc, const char * argv[] ) {
    // Creando la lista
    NODE * start = NULL, *current, *next; // Crea puntero start con NULL para poner la lista vacia
    // Current puntero auxiliar

    char goOn; // Bandera de continuacion, goOn puede ser int tambien
    int listSize = 0, number; //listSize es el tamaño de la lista

    do {
        printf("La lista contiene %d nodos. Ingrese el siguiente número (0 para finalizar)\n", listSize);
        scanf("%d",&number);
        if( number ) { // Si el number es distinto de 0 continua
            if( !start ) { // Si start = NULL se crea el NODO (lista vacia)
                start = createNode( number ); // Crea el nodo start
                listSize++;
            } else { // Si lista no esta vacia,
                // Con el nodo que se acaba de crear, apuntarlo desde el final de la lista
                current = start; // Se crea current para no perder el inicio de la lista
                while(current->next){ // Mientras current tenga algo en su next
                    current = current->next; // Current sea igual al siguiente
                    // Avanza entre los nodos, termina cuando no tiene siguiente
                }
                // El siguiente sera el nodo que se creara
                current->next = createNode(number); //asi queda encadenado
                listSize++;
            }
            goOn =  1;
        } else {
            goOn = 0;
        }
    } while( goOn );  // Se detiene si goOn es 0

    current = start;  // Inicializa el nodo current con el inicio;
    printf( "La lisa contiene los numeros: \n" );
    while (current) { // Mientras current no sea null
        printf( "%d", current->number ); // Desreferencia current accede a number
        printf( current->next ? ", " : "\n" ); // Pregunta si existe numero siguiente
        // Si es verdadero pone una , y sigue con el siguiente valor sino pone \n
        current = current->next; // Para que la repitiva avance
    }

    // Liberar memoria
    current = start;
    while (current) {
        next = current-> next;
        printf( "%d", current->number );
        free( current ); // Libera el nodo actual
        current = next;
    }

    return 0;
}
