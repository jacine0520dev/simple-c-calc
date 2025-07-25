#include <string.h>
#include <stdbool.h>
#include "parsing.h"

bool invalidCharsCheck(char *opperation){
    bool isInvalid = false;
    char validChars[19] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')', '.', ',', ' '};

    for (size_t i = 0; i <= strlen(opperation); i++){
        for (size_t j = 0; j <= strlen(validChars); j++) {
            if (opperation[i] == validChars[j]){
                isInvalid = false;
                break;
            }
            else{
                isInvalid = true;
            }
        }
    }
    return isInvalid;
}
