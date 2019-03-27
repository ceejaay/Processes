// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

  /* char salutation[20]; */
  int number;
  int forking = fork();
  if (forking < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
    /* this is a child b/c rc == 0 */
  } else if (forking == 0) {
    int number = 99;
     /* char salutation = "Hello"; */
    printf(" %d from the child.", number);

  } else {
    int number = 11;
    waitpid(forking, NULL, 0);
    /* char salutation = "Goodbye"; */
    printf(" %d from the Parent.", number);



  }
    // Your code here

    return 0;
}
