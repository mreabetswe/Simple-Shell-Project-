#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int _list(pid_t pid)
{
        char *env[] = {NULL};
        char *args[] = {"ls", "-l", "/tmp", NULL};
        char *path = "/bin/ls";

        if (pid < 0)
        {
                perror("Error");
                return (1);
        }
        if (pid == 0)
        {
                printf("Child PID: %d\n", getpid());
                execve(path, args, env);
        }
        else
        {
                wait(NULL);
                printf("Child completes\n");
        }
        printf("PPID: %d\n", getpid());
        return (0);
}

int main(int argc, char *argv[])
{
        pid_t pid;
        int i = 0;

        while (i < 5)
        {
                pid = fork();
                _list(pid);
                i++;
        }
        return (0);
}
