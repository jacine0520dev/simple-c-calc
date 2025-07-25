#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "parsing.h"
//#include "math.h"

int main(int argc, char* argv[]) {
    char *input = promptUser("Write an operation... ");

    if (input != NULL && invalidCharsCheck(input)){
        printf("Your opperation: %s\n", input);
        free(input);
    }

    return 0;
}
