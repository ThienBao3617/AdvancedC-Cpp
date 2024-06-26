#ifndef __UI_H_
#define __UI_H_

#include "data.h"

void readData(const char* fileName, MemberNode** list);
void writeData(const char* fileName, MemberNode* list);

#endif
