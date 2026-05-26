#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#define _GNU_SOURCE

#define HARDCODED_VALUE 423

void main (int argc, char **argv)
{
	char	*cmd_args[2];

	// Work as expected, password too easy to find
    if (atoi(argv[1]) != HARDCODED_VALUE)
    {
		fwrite("No!\n", 1, 4, stdout);
    }
    else
    {
        cmd_args[0] = strdup("/bin/sh");
		cmd_args[1] = NULL;

		execv("/bin/sh", cmd_args);
    }
}
