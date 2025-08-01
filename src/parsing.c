#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parsing.h"

char *parseOpp(char *opp){
    char *oppArr = malloc(100);
    char nums[12] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',',};
    char opps[4] = {'+', '-', '*', '/'};
    char *buf = {0};
    size_t count = 0;

    for(size_t i = 0; i <= strlen(opp); i++){
        for(size_t j = 0; i <= strlen(nums); j++){
            if(opp[i] == nums[j]){
                buf[i] = opp[i];
                break;
            }
            else if(opp[i] != nums[j] && i == 0 && j == strlen(nums)){
                printf("An operation needs to start with a number (negative nums are not done)!");
            }
            else if(opp[i] != nums[j] && j == strlen(nums)) {
                for(size_t j = 0; j <= strlen(buf); j++){
                    if(count == sizeof(oppArr)){
                        printf("The opperation is too big!");
                    }
                    if(sizeof(buf) == sizeof(oppArr)){
                        printf("You have a number that is too big");
                    }
                    oppArr[count] = malloc(100);
                    oppArr[count] = buf[j];
                    count++;
                }
            }
        }    
    }
    return oppArr;
}
