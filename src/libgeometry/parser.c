#include "parser.h"

#include <ctype.h>
#include <string.h>

int find_circle(
        char* str,
        char** err_msg,
        int* err_smb,
        char** c_radius,
        char** x,
        char** y)
{
    unsigned int i, j;
    char buffer[2];
    char bufferx[2];
    char buffery[2];

    if (strncmp(str, "circle(", 7) == 0) { // circle

        for (i = 7; i < strlen(str); i++) { // founding number 1
            if (str[i] == 32) {             // " "
                continue;
            }
            bufferx[0] = str[i];
            strcat(*x, bufferx);
            if (str[i] == 45) { // "-"
                bufferx[0] = str[i];
                strcat(*x, bufferx);
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        bufferx[0] = str[j];
                        strcat(*x, bufferx);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        bufferx[0] = str[j];
                        strcat(*x, bufferx);
                        break;
                    }
                    *err_msg = "expected digit, dot or space\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "1expected digit, dot or space\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        bufferx[0] = str[j];
                        strcat(*x, bufferx);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    *err_msg = "expected digit or space\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit or space\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }

        for (i = j + 1; i < strlen(str); i++) { // founding number 2
            if (str[i] == 32) {                 // " "
                continue;
            }
            buffery[0] = str[i];
            strcat(*y, buffery);
            if (str[i] == 45) { // "-"
                buffery[0] = str[i];
                strcat(*y, buffery);
                continue;
            }
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffery[0] = str[j];
                        strcat(*y, buffery);
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        buffery[0] = str[j];
                        strcat(*y, buffery);
                        break;
                    }
                    *err_msg = "expected digit, dot, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "expected digit, dot, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffery[0] = str[j];
                        strcat(*y, buffery);
                        continue;
                    }
                    if (str[j] == 44) { // ","
                        break;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    *err_msg = "expected digit, space or comma\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit, space or comma\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 44) { // ","
                break;
            }
            if (str[j] == 32) { // " "
                continue;
            }
            *err_msg = "expected space or comma\n";
            *err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            *err_msg = "expected comma\n";
            *err_smb = j;
            return 1;
        }
        for (i = j + 1; i < strlen(str); i++) { // founding number 3
            if (str[i] == 32) {                 // " "
                continue;
            }
            buffer[0] = str[i];
            strcat(*c_radius, buffer);
            if (isdigit(str[i])) {
                for (j = i + 1; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffer[0] = str[j];
                        strcat(*c_radius, buffer);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 46) { // "."
                        buffer[0] = str[j];
                        strcat(*c_radius, buffer);
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    *err_msg = "expected digit, dot, space or bracket\n";
                    *err_smb = j;
                    return 1;
                }
                if (str[j] == 0) {
                    *err_msg = "expected digit, dot, bracket or space\n";
                    *err_smb = j;
                    return 1;
                }
            } else {
                *err_msg = "expected number or space\n";
                *err_smb = i;
                return 1;
            }
            if (str[j] == 46) {
                for (j++; j < strlen(str); j++) {
                    if (isdigit(str[j])) {
                        buffer[0] = str[j];
                        strcat(*c_radius, buffer);
                        continue;
                    }
                    if (str[j] == 32) { // " "
                        break;
                    }
                    if (str[j] == 41) { // ")"
                        break;
                    }
                    *err_msg = "expected digit, space or bracket\n";
                    *err_smb = j;
                    return 1;
                }
            }
            if (str[j] == 0) {
                *err_msg = "expected digit, bracket or space\n";
                *err_smb = j;
                return 1;
            }
            break;
        }
        if (str[i] == 0) {
            *err_msg = "expected number\n";
            *err_smb = i;
            return 1;
        }
        for (; j < strlen(str); j++) {
            if (str[j] == 32) { // " "
                continue;
            }
            if (str[j] == 41) { // ")"
                break;
            }
            *err_msg = "expected space or bracket\n";
            *err_smb = j;
            return 1;
        }
        if (str[j] == 0) {
            *err_msg = "expected bracket\n";
            *err_smb = j;
            return 1;
        }

    } else {
        if (strncmp(str, "circle", 6) == 0) {
            *err_msg = "expected '('\n";
            *err_smb = 6;
            return 1;
        } else {
            *err_msg = "expected 'circle'\n";
            *err_smb = 0;
            return 1;
        }
    }
    return 0;
}
