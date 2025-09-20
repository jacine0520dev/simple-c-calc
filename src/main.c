#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"
#include "logic.h"

int main(void){
    char *input = promptUser("Write an operation... ");

    if (input != NULL && isValidOpe(input)){
        printf("Your operation: %s\n", input);
		
		char **tokArr = opeToTok(input);

		if(tokArr == NULL){
            printf("Error! opeToTok failed and returned NULL!\n");
            free(input);
            return 1;
        }

        tokArrPrinter(tokArr);
		
	    for(size_t i = 0; tokArr[i][0] != '\n'; i++){
            free(tokArr[i]);
        }
        free(tokArr);
        free(input);
    }

    return 0;
}
