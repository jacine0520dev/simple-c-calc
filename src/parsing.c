#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"

char **parseOpe(char *ope){
    char nums[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    char opes[4] = {'+', '-', '*', '/'};
    char **opeArr = NULL;
    size_t opeSize = strlen(ope);
    size_t tokkenCount = 0;
    size_t bufSize = 100;
    size_t bufCount = 0;

    //loop through the operation
    for(size_t i = 0; i <= opeSize; i++){
        //create a buffer
        char *buf = malloc(bufSize * sizeof(char));

        //check for number characters
        for(size_t j = 0; j <= strlen(nums); j++){
            //if there are fill the buffer
            if(ope[i] == nums[j]){
                buf[bufCount] = ope[i];
                bufCount++;
                break;
            }
            //if the first character of an operation is not a number return null and print an error message
            else if(i == 0 && ope[i] != nums[j] && j >= strlen(nums)){
                printf("ERROR! An opeeration needs to start with a \"number\"!");
                return NULL;
            }
        }
        //check for operstors
        for(size_t j = 0; j <= strlen(opes); j++){
            //if there is an operator end the number tokken and add a tokken for the opeerator
            if(ope[i] == opes[j]){
                opeArr = realloc(opeArr, tokkenCount * sizeof(char*));
                opeArr[tokkenCount] = malloc(strlen(buf));
                for(size_t k = 0; k <= strlen(opeArr[tokkenCount]); k++){
                    opeArr[tokkenCount][k] = buf[k];
                }
                tokkenCount++;
                opeArr = realloc(opeArr, tokkenCount * sizeof(char*));
                opeArr[tokkenCount] = malloc(sizeof(opes[j]));
                opeArr[tokkenCount][0] = opes[j];
                tokkenCount++;
                break;
            }
        }
    }

    return opeArr;
}
