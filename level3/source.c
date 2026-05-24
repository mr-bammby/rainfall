#include <stdio.h>
#include <stdlib.h>

int g_chk = 0;

void v(void)
{
    char buffer[512]; // Allocated on stack 520 bytes, buffer size set based on fgets arguments.

    // Secure read
    fgets(buffer, 512, stdin);

    // Security problem
    printf(buffer); 

    if (g_chk == 64)
    {
        fwrite("Wait what?!\n", 1, 12, stdout);
        system("/bin/sh"); 
    }
}

int main(void)
{
    v();
    return 0;
}
