#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *auth;
char *service;


int main()
{
    char buf[128]; // Bufer sized assumed from fgets argument

    while (1)
    {
        printf("%p, %p \n", auth, service);

        if (fgets(buf, 128, stdin) == NULL)
        {
            break;
        }
        // COMMAND: "auth "
        if (strncmp(buf, "auth ", 5) == 0)
        {
            auth = malloc(4); 
            *auth = 0;

            // Potentional problem but login checks auth + 32 so not the way
            if (strlen(buf + 5) <= 30)
            {
                strcpy(auth, buf + 5); 
            }
        }
        // COMMAND: "reset"
        else if (strncmp(buf, "reset", 5) == 0)
        {
            // Potentional problem not setting pointer to NULL after free
            free(auth); 
        }
        // COMMAND: "service"
        else if (strncmp(buf, "service", 6) == 0)
        {
            // Allocates new memory without freeing previous one
            service = strdup(buf + 7);
        }
        // COMMAND: "login"
        else if (strncmp(buf, "login", 5) == 0)
        {
            // Security problem
            // Checks offset 0x20 (32 bytes) into the struct this memory is not allocated so it can be malloced randomly
            if (*(int *)((char *)auth + 0x20) != 0)
            {
                system("/bin/sh"); 
            } else
            {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }
    return 0;
}
