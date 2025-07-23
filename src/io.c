#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/*promptUser function
 prompt user for an input
 parameter prompt (string) is just the question asking for the user input
 buffer (string) is just a buffer for my input
 strSize (int) is the size of the string in the buffer

 returns an input (string)*/
char *promptUser(char prompt[]){
    //print the prompt
    printf("%s\n", prompt);

    //getting user inpuet and writing it to a buffer
    char buffer[BUFFER_SIZE] = {0};
    if(fgets(buffer, sizeof(buffer), stdin) == NULL){
        return NULL;
    }
    
    //clearning the buffer and saving the string size
    int strSize = strcspn(buffer, "\n");
    buffer[strSize] = '\0';

    //trancefer my string from my buffer to a proper sized string
    char *input = malloc (strSize + 1);
    for (int i = 0; i < strSize; i++) {
        input[i] = buffer[i];
    }
    input[strSize] = '\0';

    //return the input
    return input;
}
