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
    
    char str[100 + 1];
    fgets(str, 100, tfile);
    printf("%s\n", str);

    if(strncmp(str, "circle", 6) == 0) {
        printf("have circle\n");
    } else {
        printf("^\nError at column 0: expected 'circle'\n");
    }

    fclose(tfile);
    printf("\nFile closed\n");
    printf("Exit program...\n");
    return 0;
}
