#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/geometrylib.h>
#include <libgeometry/parser.h>

typedef struct string_info {
    char str[100 + 1];
    float radius;
    float x;
    float y;
    int figures;
} string;

int main(int argc, char* argv[])
{
    char* err_msg; // error message
    int err_smb;   // symbol of error
    int found, s, n, i, j;

    char str[100 + 1];
    float radius;
    float x;
    float y;
    float a;
    float b;
    float c;

    string* strings;

    char* c_radius;
    char* c_x;
    char* c_y;

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
        printf("Enter quantity of figures: ");

        scanf("%d", &n);

        while (getchar() != '\n')
            ;

        strings = malloc(n * sizeof(string));

        for (i = 0; i < n; i++) {
            strings[i].figures = 0;
            printf("Enter string #%d: \n\n", i + 1);
            fgets(strings[i].str, 100, stdin);

            c_radius = malloc(100 * sizeof(char));
            c_x = malloc(100 * sizeof(char));
            c_y = malloc(100 * sizeof(char));

            found = find_circle(
                    strings[i].str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

            if (found == 0) {
                radius = atof(c_radius);
                x = atof(c_x);
                y = atof(c_y);
                strings[i].x = x;
                strings[i].y = y;
                strings[i].radius = radius;

                if (argc == 2) {
                    fclose(tfile);
                    printf("File closed\n");
                }
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

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (strings[i].x < strings[j].x) {
                    a = strings[j].x - strings[i].x;
                } else {
                    a = strings[i].x - strings[j].x;
                }
                if (strings[i].y < strings[j].y) {
                    b = strings[j].y - strings[i].y;
                } else {
                    b = strings[i].y - strings[j].y;
                }
                c = sqrt((a * a) + (b * b));

                if (c < strings[i].radius + strings[j].radius) {
                    strings[i].figures += 1;
                    strings[j].figures += 1;
                }

                a = 0;
                b = 0;
                c = 0;
            }

            printf("\n%s\n", strings[i].str);
            printf("  perimeter: = %.4f\n", count_perimeter(strings[i].radius));
            printf("  area: = %.4f\n", count_area(strings[i].radius));
            printf("  intersections: %d\n", strings[i].figures);
        }
    }
    printf("Exit program...\n");
    return 0;
}

