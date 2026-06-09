#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char buffer[40];                // ungefähr ab esp+0x14
    int value;

    value = atoi(argv[1]);

    if (value > 9)
        return 1;

    memcpy(buffer, argv[2], value * 4);

    if (value == 0x574F4C46) {      // "FLOW"
        execl("/bin/sh", "sh", NULL);
    }

    return 0;
}
