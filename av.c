#include <stdio.h>

int main(int ac, char **av) 
{
    // Write C code here
    
    printf("You have entered %d arguments:\n", ac);
    for (int i = 1; av[i] != NULL; i++)
    {
      printf("%s\n", av[i]);  
    }

    return 0;
}
