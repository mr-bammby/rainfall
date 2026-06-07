#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *g_auth;
char *g_service;


int main()
{
    char buf[128]; // Bufer sized assumed from fgets argument

    while (1)
    {
        printf("%p, %p \n", g_auth, g_service);

        if (fgets(buf, 128, stdin) == NULL)
        {
            break;
        }
        // COMMAND: "auth "
        if (strncmp(buf, "auth ", 5) == 0)
        {
            g_auth = malloc(4); 
            *g_auth = 0;

            // Potentional problem but login checks g_auth + 32 so not the way
            if (strlen(buf + 5) <= 30)
            {
                strcpy(g_auth, buf + 5); 
            }
        }
        // COMMAND: "reset"
        else if (strncmp(buf, "reset", 5) == 0)
        {
            // Potentional problem not setting pointer to NULL after free
            free(g_auth); 
        }
        // COMMAND: "service"
        else if (strncmp(buf, "service", 6) == 0)
        {
            // Allocates new memory without freeing previous one
            g_service = strdup(buf + 7);
        }
        // COMMAND: "login"
        else if (strncmp(buf, "login", 5) == 0)
        {
            // Security problem
            // Checks offset 0x20 (32 bytes) into the struct this memory is not allocated so it can be malloced randomly
            if (*(int *)((char *)g_auth + 0x20) != 0)
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
