#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void p()
{
    char buff[64]; // Buffer size calculation: 0x68(Allocat 102 bytes on stack) - 0x4c(offset of the buffer) - 0xc (Return address slot) = 0x40(Size of the buffer)
    unsigned int addr;

    fflush(stdout);
    // Security problem
    gets(buff);

    addr = (unsigned int)__builtin_return_address(0); // 0 for the current function

    // Return address check
    if ((addr & 0xb0000000) == 0xb0000000)
    {
        printf("(%p)\n", (void *)addr); 
        _exit(1);
    }

    puts(buff);
    strdup(buff);
}

int main()
{
    p();
    return 0;
}