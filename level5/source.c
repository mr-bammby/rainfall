#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Hidden win function
void o()
{
    system("/bin/sh"); 
    _exit(1);
}

void n()
{
    char buffer[512]; // Allocated on stack 520 bytes, buffer size set based on fgets arguments.
    fgets(buffer, 512, stdin);
    
    // Security problem
    printf(buffer);
    
    // Program newer reaches return
    exit(1); 
}

int main()
{
    n();
    return 0;
}