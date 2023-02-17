#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE* tfile;

    tfile = fopen(argv[1], "r");

    if (tfile == NULL) {
        printf("Can`t open file\n");
        return 1;
    } else {
        printf("File opened succesfully\n\n");
    }
    
    char *str[100];
    fgets(*str, 99, tfile);
    printf("%s\n", *str);

    fclose(tfile);
    printf("File closed\n");
    printf("Exit program...\n");
    return 0;
}
