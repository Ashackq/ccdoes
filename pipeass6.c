#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  int pipefd[2];
  char msg1[20] = "";
  char readmsg[20] = "";

  int returnstatus = pipe(pipefd);

  if (returnstatus == -1) {
    printf("Pipe cannot be created\n");
    return 1;
  }

  int pid = fork();

  if (pid < 0) {
    printf("Unsuccessful fork command\n");
    return 1;
  }

  if (pid == 0) {
    close(pipefd[1]);
    read(pipefd[0], readmsg, 20);
    printf("Child read: %s\n", readmsg);

    close(pipefd[0]);
  } else {
    close(pipefd[0]);
    printf("Parent writing\n");
    printf("Enter the message to write - \n");
    fgets(msg1, sizeof(msg1), stdin);
    write(pipefd[1], msg1, strlen(msg1) + 1);
    close(pipefd[1]);
  }

  return 0;
}
