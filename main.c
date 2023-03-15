#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int i, j, s;

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

    if(strncmp(str, "circle(", 7) == 0) { // circle
        printf("have 'circle'\n");

        for(i = 7; i < strlen(str); i++) { //founding number 1
            if(str[i] == 32) {
                    continue;
                }
            if(isdigit(str[i])) {
                for(j = i + 1; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 32) {
                        goto number_found_1;
                    }
                    if(str[j] == 46) {
                        break;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit, dot or space\n", s);
                    goto exit_with_error;
                }
                if(str[j] == 0) {
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                        printf("^\nError at column %d: expected digit, dot or space\n", s);
                    goto exit_with_error;
                }
            } else {
                for(s = 0; s < i; s++) {
                    printf(" ");
                }
                printf("^\nError at column %d: expected number or space\n", s);
                goto exit_with_error;
            }
            for(j++; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 32) {
                        goto number_found_1;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit or space\n", s);
                    goto exit_with_error;
            }
            if(str[j] == 0) {
                for(s = 0; s < j; s++) {
                    printf(" ");
                }
                    printf("^\nError at column %d: expected digit or space\n", s);
                goto exit_with_error;
            }
            number_found_1:
            printf("have first number\n");
            break;
        }
        if(str[i] == 0) {
            for(s = 0; s < i; s++) {
                printf(" ");
            }
                printf("^\nError at column %d: expected number\n", s);
            goto exit_with_error;
        }
        
        for(i = j + 1; i < strlen(str); i++) { //founding number 2
            if(str[i] == 32) {
                    continue;
                }
            if(isdigit(str[i])) {
                for(j = i + 1; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 44) {
                        goto number_found_2;
                    }
                    if(str[j] == 32) {
                        goto number_found_2;
                    }
                    if(str[j] == 46) {
                        break;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit, dot, space or comma\n", s);
                    goto exit_with_error;
                }
                if(str[j] == 0) {
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                        printf("^\nError at column %d: expected digit, dot, comma or space\n", s);
                    goto exit_with_error;
                }
            } else {
                for(s = 0; s < i; s++) {
                    printf(" ");
                }
                printf("^\nError at column %d: expected number or space\n", s);
                goto exit_with_error;
            }
            for(j++; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 44) {
                        goto number_found_2;
                    }
                    if(str[j] == 32) {
                        goto number_found_2;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit, space or comma\n", s);
                    goto exit_with_error;
                }
            if(str[j] == 0) {
                for(s = 0; s < j; s++) {
                    printf(" ");
                }
                    printf("^\nError at column %d: expected digit, comma or space\n", s);
                goto exit_with_error;
            }
            number_found_2:
            printf("have second number\n");
            break;
        }
        if(str[i] == 0) {
            for(s = 0; s < i; s++) {
                printf(" ");
            }
                printf("^\nError at column %d: expected number\n", s);
            goto exit_with_error;
        }
        for(; j < strlen(str); j++) {
            if(str[j] == 44) {
                goto comma_found;
            }
            if(str[j] == 32) {
                continue;
            }
            for(s = 0; s < j; s++) {
                printf(" ");
            }
            printf("^\nError at column %d: expected space or comma\n", s);
            goto exit_with_error;
            comma_found:
            printf("have comma\n");
            break;
        }
        if(str[j] == 0) {
            for(s = 0; s < j; s++) {
                printf(" ");
            }
                printf("^\nError at column %d: expected comma\n", s);
            goto exit_with_error;
        }
        for(i = j + 1; i < strlen(str); i++) { //founding number 3
            if(str[i] == 32) {
                    continue;
                }
            if(isdigit(str[i])) {
                for(j = i + 1; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 32) {
                        goto number_found_3;
                    }
                    if(str[j] == 46) {
                        break;
                    }
                    if(str[j] == 41) { // )
                        goto number_found_3;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit, dot, space or bracket\n", s);
                    goto exit_with_error;
                }
                if(str[j] == 0) {
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                        printf("^\nError at column %d: expected digit, dot, bracket or space\n", s);
                    goto exit_with_error;
                }
            } else {
                for(s = 0; s < i; s++) {
                    printf(" ");
                }
                printf("^\nError at column %d: expected number or space\n", s);
                goto exit_with_error;
            }
            for(j++; j < strlen(str); j++) {
                    if(isdigit(str[j])) {
                        continue;
                    }
                    if(str[j] == 32) {
                        goto number_found_3;
                    }
                    if(str[j] == 41) { // )
                        goto number_found_3;
                    }
                    for(s = 0; s < j; s++) {
                        printf(" ");
                    }
                    printf("^\nError at column %d: expected digit, space or bracket\n", s);
                    goto exit_with_error;
                }
            if(str[j] == 0) {
                for(s = 0; s < j; s++) {
                    printf(" ");
                }
                    printf("^\nError at column %d: expected digit, bracket or space\n", s);
                goto exit_with_error;
            }
            number_found_3:
            printf("have third number\n");
            break;
        }
        if(str[i] == 0) {
            for(s = 0; s < i; s++) {
                printf(" ");
            }
                printf("^\nError at column %d: expected number\n", s);
            goto exit_with_error;
        }
        for(; j < strlen(str); j++) {
            if(str[j] == 32) { // " "
                continue;
            }
            if(str[j] == 41) { // )
                goto bracket_found;
            }
            for(s = 0; s < j; s++) {
                printf(" ");
            }
            printf("^\nError at column %d: expected space or bracket\n", s);
            goto exit_with_error;
            bracket_found:
            printf("have bracket");
            goto right_circle;
        }
        if(str[j] == 0) {
            for(s = 0; s < j; s++) {
                printf(" ");
            }
                printf("^\nError at column %d: expected bracket\n", s);
            goto exit_with_error;
        }

    } else {
        if(strncmp(str, "circle", 6) == 0) {
            printf("      ^\nError at column 7: expected '('\n");
            goto exit_with_error;
        } else {
            printf("^\nError at column 0: expected 'circle'\n");
            goto exit_with_error;
        }
    }
    right_circle:

    printf("\n%d\n", ' ');

    fclose(tfile);
    printf("\nFile closed\n");
    printf("Exit program...\n");
    return 0;
    exit_with_error:
    fclose(tfile);
    printf("\nFile closed\n");
    printf("Exit program with error\n");
    return 1;
}
