#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* err_msg; // error message
int err_smb;   // symbol of error
char c_radius[100] = "";

int find_circle(char* str);
float count_perimeter(float rad);
float count_area(float rad);

int main(int argc, char* argv[])
{
    int found, s;
    char str[100 + 1];
    float radius;

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

    found = find_circle(str);

    radius = atof(c_radius);
    printf("  perimeter: = %.4f\n", count_perimeter(radius));
    printf("  area: = %.4f\n", count_area(radius));

    if (found == 0) {
        printf("\nRight entry\n");
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

float count_perimeter(float rad)
{
    return (2 * M_PI * rad);
}

float count_area(float rad)
{
    return (M_PI * rad * rad);
}

int find_circle(char* str)
{
    unsigned int i, j;
    char buffer[2];

    if (strncmp(str, "circle(", 7) == 0) { // circle

        for (i = 7; i < strlen(str); i++) { // founding number 1
            if (str[i] == 32) {             // " "
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        break;
                    }
                    err_msg = "expected digit, dot or space\n";
                    err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    err_msg = "1expected digit, dot or space\n";
                    err_smb = j;
                    return 1;
                }
            } else {
                err_msg = "expected number or space\n";
                err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    err_msg = "expected digit or space\n";
                    err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                err_msg = "expected digit or space\n";
                err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            err_msg = "expected number\n";
            err_smb = i;
            return 1;
        }

        for (i = j + 1; i < strlen(str); i++) { // founding number 2
            if (str[i] == 32) {                 // " "
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        break;
                    }
                    err_msg = "expected digit, dot, space or comma\n";
                    err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    err_msg = "expected digit, dot, space or comma\n";
                    err_smb = j;
                    return 1;
                }
            } else {
                err_msg = "expected number or space\n";
                err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    err_msg = "expected digit, space or comma\n";
                    err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                err_msg = "expected digit, space or comma\n";
                err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            err_msg = "expected number\n";
            err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 44) { // ","
                break;
            }
            if (str[j] == 32) { // " "
                continue;
            }
            err_msg = "expected space or comma\n";
            err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            err_msg = "expected comma\n";
            err_smb = j;
            return 1;
        }
        for (i = j + 1; i < strlen(str); i++) { // founding number 3
            if (str[i] == 32) {                 // " "
                continue;
            }
            buffer[0] = str[i];
            strcat(c_radius, buffer);
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffer[0] = str[j];
                        strcat(c_radius, buffer);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        buffer[0] = str[j];
                        strcat(c_radius, buffer);
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    err_msg = "expected digit, dot, space or bracket\n";
                    err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    err_msg = "expected digit, dot, bracket or space\n";
                    err_smb = j;
                    return 1;
                }
            } else {
                err_msg = "expected number or space\n";
                err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffer[0] = str[j];
                        strcat(c_radius, buffer);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    err_msg = "expected digit, space or bracket\n";
                    err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                err_msg = "expected digit, bracket or space\n";
                err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            err_msg = "expected number\n";
            err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 32) { // " "
                continue;
            }
            if (str[j] == 41) { // ")"
                break;
            }
            err_msg = "expected space or bracket\n";
            err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            err_msg = "expected bracket\n";
            err_smb = j;
            return 1;
        }

    } else {
        if (strncmp(str, "circle", 6) == 0) {
            err_msg = "expected '('\n";
            err_smb = 6;
            return 1;
        } else {
            err_msg = "expected 'circle'\n";
            err_smb = 0;
            return 1;
        }
    }
    return 0;
}
