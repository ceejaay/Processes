// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("args: %s\n", argv[1]);
  printf("******This is the process %d*****\n", getpid());
  int forking = fork();
  if (forking < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
    /* this is a child b/c rc == 0 */
  } else if (forking == 0) {
    printf("Child => %d\n", getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("ex4.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);


    /* int number = 99; */
    /* char *hello = "Hello"; */
    /* printf(" %s from the child. \n", hello); */

  } else {
    printf("Parent => %d Child => %d\n", getpid(), forking);
    /* int number = 11; */
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("nano.save");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    /* char *goodbye = "Goodbye"; */
    waitpid(forking, NULL, 0);
    /* printf(" %s from the Parent. \n", goodbye); */
  }




    // Your code here    

    return 0;
}
