#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, const char * argv[]){
  int shared = 2;
  int pid = fork();
  if(pid) {
    shared = 1;
    printf("Luke I am your father. My PID is %d and your PID is %d. Shared = %d\n", getpid(), pid, shared);
    wait(NULL);
    printf("I'm your father again. Shared = %d\n", shared);
  } else {
    shared = 0;
    printf("I am Luke. My PID is %d. Shared = %d\n", getpid(), shared);
    sleep(2);
  }
  return 0;
}
