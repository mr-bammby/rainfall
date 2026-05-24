#include <stdio.h>
#include <stdlib.h>

int g_chk = 0;

void p(char *str)
{
    // Security problem
    printf(str); 
}

void n(void)
{

    char buffer[512]; // Allocated on stack 520 bytes, buffer size set based on fgets arguments.

    // Secure read
    fgets(buffer, 512, stdin);
    
    p(buffer);
    if (g_chk == 0x01025544)
    {
        system("/bin/sh");
    }
}

int main(void)
{
    n();
    return 0;
}
