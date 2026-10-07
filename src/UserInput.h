#ifndef USERINPUT_H
#define USERINPUT_H

#include "Direction.h"

namespace UserInput {
void clearInputBuffer();
void clearInput();
bool isValidInput(char);
char getValidInput();
char getCommandFromUser();
Direction charToDirection(char);
} // namespace UserInput

#endif // !UserInput
