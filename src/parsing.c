#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"

char **parseOpp(char *opp){
    char **oppArr = NULL;
    char nums[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    char opps[4] = {'+', '-', '*', '/'};
    size_t bufSize = 100;
    size_t bufCount = 0;
    size_t parseCount = 0;
    size_t oppSize = strlen(opp);

    //loop through the opperation
    for(size_t i = 0; i <= oppSize; i++){
        char *buf = malloc(bufSize * sizeof(char));

        //check for nums
        for(size_t j = 0; j <= strlen(nums); j++){
            if(opp[i] == nums[j]){
                buf[bufCount] = opp[i];
                bufCount++;
                break;
            }
            //if the first char of an operation is not a number return null and print an error message
            else if(i == 0 && opp[i] != nums[j] && j >= strlen(nums)){
                printf("ERROR! An opperation needs to start with a \"number\"!");
                return NULL;
            }
        }
        //check for opps
        for(size_t j = 0; j <= strlen(opps); j++){
            //if there is an opperator end the first parse and add a parse for the opperator
            if(opp[i] == opps[j]){
                oppArr = realloc(oppArr, parseCount * sizeof(char*));
                oppArr[parseCount] = malloc(strlen(buf));
                for(size_t k = 0; k <= strlen(oppArr[parseCount]); k++){
                    oppArr[parseCount][k] = buf[k];
                }
                parseCount++;
                oppArr = realloc(oppArr, parseCount * sizeof(char*));
                oppArr[parseCount] = malloc(sizeof(opps[j]));
                oppArr[parseCount][0] = opps[j];
                parseCount++;
                break;
            }
        }
    }

    return oppArr;
}
