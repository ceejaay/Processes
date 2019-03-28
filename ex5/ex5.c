// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{

  char buffer[MSGSIZE];
  int p[2];
  printf("******This is the process %d*****\n", getpid());
  int forking = fork();
  if (forking < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (forking == 0) {
    printf("Child => %d\n", getpid());
  } else {
    printf("Parent => %d Child => %d\n", getpid(), forking);
    /* int new_fork = fork(); */
    waitpid(forking, NULL, 0);
  }

  /* if(new_fork < 0) { */
  /*     fprintf(stderr, "fork failed\n"); */
  /*     exit(1); */
  /* } else if (new_fork == 0) { */
  /*   printf("new fork => %d\n", getpid()); */
  /* } else { */
  /*   printf("Parent => %d Child => %d grand child=> %d\n", getpid(), forking, new_fork); */
  /* } */
    return 0;
}
