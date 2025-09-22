#ifndef LOGIC_H_
#define LOGIC_H_

#include <stddef.h>
#include <stdbool.h>

//declaring logic.c functions
bool isValidOpe(char *operation);
char **opeToTok(char *operation);
void removeChar(char *str, size_t index);

#endif //LOGIC_H_
