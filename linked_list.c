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
    NODE * start = NULL, *current, *next, *aux; // Crea puntero start con NULL para poner la lista vacia
    // Current puntero auxiliar

    char goOn; // Bandera de continuacion, goOn puede ser int tambien
    int listSize = 0, number, index, currentIndex; //listSize es el tamaño de la lista

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

    printf("\n\n\nLe gustaria eliminar algún nodo? (Escriba 1 para si, escriba 0 para no)\n");
    scanf("%d",&goOn);

    if( goOn ) {
        printf("\n\nEscriba el index del nodo a eliminar: \n");
        scanf("%d", &index);
        //printf("\n\n Se eliminara este index %d \n", index);
        current = start;
        currentIndex = 0;

        while (current) {
            next = current->next;
            //printf("Nodo actual %d\n", current->number );
            //printf("Index actual %d\n", current);
            if(currentIndex==index) {
                printf("El numero del nodo a eliminar es %d\n", current->number);
                //printf("%d\n", current->next);
                if(!index) {
                    printf("Es el primero");
                } else {
                    aux = current->next;
                    free( current ); // Libera el nodo actual
                    current = start;
                    index = 0;
                    while(current) {
                        //printf("current->number, %d", current->number);
                        current = current->next;
                        if(currentIndex-2==index) {
                            current->next = aux;
                            current=0;
                        }
                        index++;
                    }
                }
            } else {
                currentIndex++;
                current = next;
                //printf("next %d\n", next);
                if(!next) {
                    printf("El index %d es inexistente.", index);
                }
            }
        }
    }


    current = start;  // Inicializa el nodo current con el inicio;
    printf( "\n\nNueva lista de numeros: \n" );
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
        free( current ); // Libera el nodo actual
        current = next;
    }

    return 0;
}
