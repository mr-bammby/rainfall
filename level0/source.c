#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#define _GNU_SOURCE

#define HARDCODED_VALUE 423
#define ACCESS_DENIED "No !\n"
#define SHELL "/bin/sh"

void main (int argc, char **argv)
{
	char	*cmd_args[2];

	// Work as expected, password too easy to find
    if (HARDCODED_VALUE == atoi(argv[1]))
    {
      cmd_args[0] = strdup(SHELL);
		  cmd_args[1] = NULL;
      execv(SHELL, cmd_args);
    }
    else
    {
		  fwrite(ACCESS_DENIED, 1, 5, stdout);
    }
}
