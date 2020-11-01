#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[100];
  unsigned int age;
};

int main (int argc, const char * argv[]){
  FILE * out;
  char buffer[100];

  if( argc < 2 ) {
    printf("Indique el nombre del archivo de salida:\n");
    return -1;
  }
  if( !(out = fopen( argv[1], "w")) ) {
    printf("No puedo escribir en el archivo %s\n", argv[1]);
    return -2;
  }

  struct person p;

  do {
    printf("Ingrese el nombre de la persona: \n");
    scanf("%99s", p.name ); 
    printf("Ingrese edad de la persona: \n");
    scanf("%d", &(p.age) );
    fwrite( &p, sizeof( struct person ), 1, out);
    printf("Grabara otra persona? (s/n)");
    scanf("%1s", buffer);

  } while( buffer[0] != 'n' );

  fclose(out);
  return 0;
}
