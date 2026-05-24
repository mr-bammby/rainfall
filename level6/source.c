#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Win function
void n()
{
    system("/bin/cat /home/user/level7/.pass");
}

void m()
{
    puts("Nope\n"); 
}

int main(int argc, char **argv)
{
    char *buf = malloc(64); //Size determinated form malloc paramter
    void (**fun_p)() = malloc(4); //Size determinated form malloc paramter

    *fun_p = m;

    // Security problem
    strcpy(buf, argv[1]);
    (*fun_p)();

    return 0;
}