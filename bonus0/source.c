#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Assuming 0x80486a0 is a prompt like "Enter name: "
// Assuming 0x80486a4 is a 2-byte separator like " " (space + null)

const char* input_str = "-\n";
const char* separator_str = " ";

void p(char* dest, const char* prompt)
{
    // Based on read arguments
    char read_buf[4096]; 
    
    puts(prompt);
    read(0, read_buf, 4096);
    
    char* newline = strchr(read_buf, '\n');
    *newline = '\0'; 
    
    strncpy(dest, read_buf, 20); 
}

void pp(char* dest) {
    // Based on arguments for strncpy in function p
    char buf2[20];
    // Based on arguments for strncpy in function p
    char buf1[20];  
    unsigned int len;
    
    p(buf1, input_str);
    p(buf2, input_str);
    
    strcpy(dest, buf1);
    
    len = strlen(dest);
    *(short*)(dest + len) = *(short*)separator_str; 
    
    strcat(dest, buf2);
}

int main()
{
    // Buffer size 64 bytes (allocated stack) - 22 bytes (Buffer offset)
    char buf[42]; 
    
    pp(buf);
    puts(buf);
    
    return 0;
}
