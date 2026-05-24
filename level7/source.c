#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char g_buf[68]; 

struct struct_s
{
    int num;
    char str;
};

void m()
{
    int t = time(NULL);
    
    printf("%s - %d\n", g_buf, t); 
}

int main(int argc, char **argv)
{
    struct struct_s *struct_p1 = malloc(8);
    struct_p1->num = 1;
    struct_p1->str = malloc(8);

    struct struct_s *struct_p2 = malloc(8);
    struct_p2->num = 2;
    struct_p2->str = malloc(8);

    // Security problem
    strcpy(struct_p1->str, argv[1]);
    strcpy(struct_p2->str, argv[2]);

    FILE *fp = fopen("/home/user/level8/.pass", "r");
    fgets(g_buf, 68, fp);
    puts("~~");

    return 0;
}