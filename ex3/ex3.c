// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

  /* int number; */
  int forking = fork();
  if (forking < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
    /* this is a child b/c rc == 0 */
  } else if (forking == 0) {
    /* int number = 99; */
    char *hello = "Hello";
    printf(" %s from the child. \n", hello);

  } else {
    /* int number = 11; */
    char *goodbye = "Goodbye";
    waitpid(forking, NULL, 0);
    printf(" %s from the Parent. \n", goodbye);
  }
    // Your code here
    return 0;
}
