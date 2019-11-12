// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

  FILE *fp;
  /* printf(" file pointer %d\n", fp); */

  int the_process = fork();
  if ( the_process < 0 ) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (the_process == 0) {
    /* fp = fopen("text.txt", "r"); */
    /* char buf[128]; */
    /* fgets(buf, 128, fp); */
    /* printf("Buffer: %s\n", buf); */

    /* fprintf("hello line 21", fp); */
    fp = fopen("text.txt", "r");

    printf("hello, child here (pid: %d) \n", (int) getpid());
    fprintf(fp, "%s", "thing");
    /* fprintf("File info %d \n", *fp); */
    fclose(fp);

  } else {
    /* this makes the parent process wait for the */ 
    waitpid(the_process, NULL, 0);
    /* fp = fopen("text.txt", "r"); */
    /* printf("the wait call => %d\n", wait_call); */
    fp = fopen("text.txt", "r");
    fprintf(fp, "%s", "thing");
    /* fprintf("File info\n", *fp); */
    /* fprintf(fp, "%s %s %s %d"); */
    printf("hello, parent here (pid: %d) of the child  process: %d\n", (int) getpid(), the_process); }
    fclose(fp);

  /* FILE *fp; */
  /* fp = fopen("text.txt", "r"); */
  /* printf("the file? => %c", fp); */
  /* int text = fopen("text.txt"); */
    // Your code here 
    //


    return 0;
}
