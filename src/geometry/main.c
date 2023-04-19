#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/geometrylib.h>
#include <libgeometry/parser.h>

int main(int argc, char* argv[])
{
    char* err_msg; // error message
    int err_smb;   // symbol of error
    int found, s;

    char str[100 + 1];
    float radius;

    char* c_radius;
    c_radius = malloc(100 * sizeof(char));

    FILE* tfile;
    if (argc == 2) {
        tfile = fopen(argv[1], "r");
        if (tfile == NULL) {
            printf("Can`t open file\n");
            return 1;
        } else {
            printf("File opened succesfully\n\n");
            fgets(str, 100, tfile);
            printf("%s", str);
        }
    }
    if (argc == 1) {
        printf("Enter text: \n\n");
        scanf("%100[^\n]", str);
    }

    found = find_circle(str, &err_msg, &err_smb, &c_radius);

    if (found == 0) {
        radius = atof(c_radius);
        printf("  perimeter: = %.4f\n", count_perimeter(radius));
        printf("  area: = %.4f\n", count_area(radius));
        if (argc == 2) {
            fclose(tfile);
            printf("File closed\n");
        }
        printf("Exit program...\n");
        return 0;
    } else {
        for (s = 0; s < err_smb; s++)
            printf(" ");
        printf("^\n");
        printf("Error at column %d: %s", err_smb + 1, err_msg);
        if (argc == 2) {
            fclose(tfile);
            printf("File closed\n");
        }
        printf("Exit program with error...\n");
        return 1;
    }
}
