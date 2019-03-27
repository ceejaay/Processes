// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

  /* printf("This pid: %d ", (int) getpid()); */
  int x = 100;
  int rc = fork();
  printf("rc => %d\n         ", rc);
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    x = 99;
    printf("Hello from the child. PID: %d\n", (int) getpid());
    printf("The CHILD value of x: %d\n", x);

  } else {
    printf("Hello from the parent. PID: %d\n", (int) getpid(), rc);
    x = 199;
    printf("The PARENT value of x: %d\n", x);

  }


    return 0;
}
