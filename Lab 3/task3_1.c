#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if(pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if(pid == 0) {
        printf("This is child 1 which is about to execute command...\n");
        execl("/bin/date", "date", NULL);
    } else {
        printf("Parent waiting...\n");
        printf("PID of this child is %d\n", pid);
        wait(NULL);
        printf("Exiting...\n");
    }
    return 0;
}