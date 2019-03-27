// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

  FILE *fp;
  /* fp = fopen("text.txt", "r"); */

  int the_process = fork();
  if ( the_process < 0 ) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (the_process == 0) {
    fp = fopen("text.txt", "r");
    char buf[128];
    fgets(buf, 128, fp);
    printf("Buffer: %s\n", buf);

    /* fprintf("hello line 21", fp); */
    printf("hello, child here (pid: %d) \n", (int) getpid());

  } else {
    /* this makes the parent process wait for the */ 
    waitpid(the_process, NULL, 0);
    fp = fopen("text.txt", "r");
    /* printf("the wait call => %d\n", wait_call); */
    printf("hello, parent here (pid: %d) of the child  process: %d\n", (int) getpid(), the_process);
  }

  /* FILE *fp; */
  /* fp = fopen("text.txt", "r"); */
  /* printf("the file? => %c", fp); */
  /* int text = fopen("text.txt"); */
    // Your code here 
    //

  /* fclose(fp); */

    return 0;
}
