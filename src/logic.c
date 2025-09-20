#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "logic.h"

//operation stats
static const size_t OPERATION_MAX_SIZE = 1000;
//valid characters stats
static const char VALID_CHARS[15] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/', '\0'};
static const size_t VALID_CHARS_SIZE = sizeof(VALID_CHARS) / sizeof(char);
//operands stats
static const char OPERANDS[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
static const size_t OPERANDS_SIZE = sizeof(OPERANDS) / sizeof(char);
//operators stats
static const char OPERATORS[4] = {'+', '-', '*', '/'};
static const size_t OPERATORS_SIZE = sizeof(OPERATORS) / sizeof(char);

/*isValidOpe: checks if an operation is valid
param: operation (char *) the operation inputed from the user
var: operationSize (size_t) operation size
return: (bool)returns true if the Operation is valid*/
bool isValidOpe(char *operation){
	//initializing operation size
	size_t operationSize = strlen(operation);

	//check if the operation excedes the max size
	if(strlen(operation) > OPERATION_MAX_SIZE){
		printf("Error! It's too big sempai!!\n");
		return false;
	}
	
	//check if the operation uses non-valid characters
	for(size_t i = 0; i < operationSize; i++){
		bool match = false;
		for(size_t j = 0; j < VALID_CHARS_SIZE; j++){
			if(operation[i] == VALID_CHARS[j]){
				match = true;
				break;
			}
		}
		if(match == false){
			printf("Error! Non valid character used(%c)!\n", operation[i]);
			return false;
		}
	}
	
	//check first and last char for operators
	for(size_t i = 0; i < OPERATORS_SIZE; i++){
		if(operation[0] == OPERATORS[i]){
			printf("Error! First character can't be an operator!\n");
			return false;
		}
		if(operation[operationSize - 1] == OPERATORS[i]){
			printf("Error! Last character can't be an operator!\n");
			return false;
		}
	}
	
	//check for consecutive operators
	for(size_t i = 0; i < operationSize; i++){
		for(size_t j = 0; j < OPERATORS_SIZE; j++){
			if(operation[i] == OPERATORS[j]){
				for(size_t j = 0; j < OPERATORS_SIZE; j++){
					if(operation[i + 1] == OPERATORS[j]){
						printf("Error! Cannot use consecutive operators!\n");
						return false;
					}
				}
			}
		}
	}
	
	//check for a minimum of two operands and one operator
	bool matchOperator = false;
	for(size_t i = 0; i < operationSize; i++){
		for(size_t j = 0; j < OPERATORS_SIZE; j++){
			if(operation[i] == OPERATORS[j]){
				bool matchOperand = false;
				matchOperator = true;
				for(size_t h = 0; h < OPERANDS_SIZE; h++){
					if(operation[i + 1] == OPERANDS[h]){
						matchOperand = true;
						break;
					}
				}
				if (matchOperand == false){
					printf("Error! You need a minimum of two operands!\n");
					return false;
				}
			}
		}
	}
	if (matchOperator == false){
		printf("Error! You need a minimum of one operator!\n");
		return false;
	}
	
	//return true for passing all checks
	return true;
}

/*opeToTok: turns a string into an array of tokens
param: operation (char *) the operation inputed from the user
var: tokArr (char **) pointer to pointer to char array
var: tokCount (size_t) token counter
var: operationSize (size_t) operation size
var: buffer (char) token buffer
var: bufPos (size_t) buffer posision counter
return: (char **)returns an array of tokens*/
char **opeToTok(char *operation){
	//initializing array of tokens
	char **tokArr = NULL;
	//initializing token counter
	size_t tokCount = 0;
	//initializing operation size
	size_t operationSize = strlen(operation);
	//initializing the token buffer
	char buffer[1000] = {0};
	//initializing buffer posision counter
	size_t bufPos = 0;

	//loops through the operation
	for(size_t i = 0; i < operationSize; i++){
		//updates the buffer position
		bufPos++;

        //initializing operator flag
        bool isOperator = false;

	    //if it's the last char of the operation finish the current token
	    if(i + 1 == operationSize){
            //update the buffer
            buffer[bufPos - 1] = operation[i];

		    //null terminates the buffer
		    buffer[bufPos] = '\0';
		    //update the token counter
		    tokCount++;
			
		    //resize the token array
			    char **tmp = realloc(tokArr, (tokCount +1) * sizeof(char *));
			    if(!tmp) {
				    printf("Error! Failed to realocate tokArr on tokCount='%ld' (last char)!\n", tokCount);
				    return NULL;
			    }
			    tokArr = tmp;
			
		    //allocate memory for the operand token
		    tokArr[tokCount - 1] = malloc((strlen(buffer) + 1)* sizeof(char));
		    //transfer string from buffer to token
		    strcpy(tokArr[tokCount - 1], buffer);

		    //reset buffer
		    memset(buffer, 0, sizeof(buffer));
		    //reset buffer position
		    bufPos = 0;

            //last token as flag
            tokArr[tokCount] = malloc(sizeof(char));
            tokArr[tokCount][0] = '\n';

		    //return the token array
		    return tokArr;
	    }
		
	    //if the current char is an operator finish the current token
	    for(size_t j = 0; j < OPERATORS_SIZE; j++){
            //inisilizing isOperator

		    if(operation[i] == OPERATORS[j]){
			    //null terminates the buffer
			    buffer[bufPos] = '\0';
			    //updates the token counter
			    tokCount+= 2;

			    //resize the token array
			    char **tmp = realloc(tokArr, tokCount * sizeof(char *));
			    if(!tmp) {
				    printf("Error! Failed to realocate tokArr on tokCount='%ld'!\n", tokCount);
				    return NULL;
			    }
			    tokArr = tmp;

			    //allocate memory for the operand token
			    tokArr[tokCount - 2] = malloc((strlen(buffer) + 1)* sizeof(char));
			    //transfer string from buffer to token
			    strcpy(tokArr[tokCount - 2], buffer);

			    //reset buffer
			    memset(buffer, 0, sizeof(buffer));
			    //reset buffer position
			    bufPos = 0;

			    //allocate memory for the operand token
			    tokArr[tokCount - 1] = malloc(2 * sizeof(char));
			    //set the operator token
			    tokArr[tokCount - 1][0] = OPERATORS[j];
			    tokArr[tokCount - 1][1] = '\0';
			    
                isOperator = true;
			    //break for efficiency
			    break;
		    }
	    }

		//fill the buffer
        if(!isOperator){
		    buffer[bufPos - 1] = operation[i];
        }
	}
}

//tokToTree()
//opeTreeSolve()
