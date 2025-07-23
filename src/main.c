#include <stdio.h>
#include <stdlib.h>
#include "io.h"
//#include "parsing.h"
//#include "math.h"

int main(int argc, char* argv[]) {
    char *input = promptUser("Wright something here... ");
    if (input != NULL){
        printf("You wrote: %s\n", input);
        free(input);
    }

    return 0;
}
