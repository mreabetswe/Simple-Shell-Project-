#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	// Write C code here
	int p_id, p_pid;
        p_id = getpid(); /* Process id*/
        p_pid = getppid(); /*Parent process id*/
    
        printf("Process ID: %d\n", p_id);
        printf("Parent Process ID: %d\n", p_pid);

        return (0);
}
