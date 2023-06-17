#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int p_pid;

    p_pid = getppid(); /*Parent process id*/
    
    printf("Parent Process ID: %d\n", p_pid);

    return 0;
}
