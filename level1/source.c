#include <stdio.h>
#include <stdlib.h>

void run()
{
    fwrite("Good... Wait what?\n", 1, 19, stdout);
    system("/bin/sh"); 
}

int main()
{
    char buff[64]; // Buffer size calculation: 0x50(Allocat 80 bytes on stack) - 0x10(offset of the buffer) = 0x40(Size of the buffer)
    // Security problem
    gets(buff); 
    
    return 0;
}