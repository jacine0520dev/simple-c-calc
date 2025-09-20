#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "io.h"
#include "logic.h"

/*promptUser: prompts the user for an input with a custom prompt
param: prompt (string) question prompting the user for input
var: buffer (string) buffer for the input
var: strSize (int) size of the string in the buffer
var: input (char*)
return: (char *) returns the user input*/
char *promptUser(char prompt[]){
    //print the prompt
    printf("%s", prompt);

	//initializing the input buffer
    char buffer[2000] = {0};
    //getting user inpuet and writing it to a buffer
    if(fgets(buffer, sizeof(buffer), stdin) == NULL){
		printf("Error! NULL input received!");
        return NULL; //return NULL if fgets is null
    }
    
    //getting buffer size
    size_t strSize = strlen(buffer);
	//null terminting the buffer
    buffer[strSize - 1] = '\0';

	//allocating memory for input
    char *input = malloc(strSize + 1);
    //transefer string from buffer to input
    strcpy(input, buffer);

    //return the input
    return input;
}

//for testing!!!!!!!!
void tokArrPrinter(char **tokArr){
	for(size_t i = 0; tokArr[i][0] != '\n'; i++){
		printf("%s\n", tokArr[i]);
	}
}
