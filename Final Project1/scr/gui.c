//#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"

void readData(const char* fileName, MemberNode** list) {
    char row[500];

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }

    char* ptr;
    while (fgets(row, sizeof(row), file) != NULL) {
        Member curMember;
        memset(&curMember, 0, sizeof(Member)); // Initialize the memory

        int cnt = 0;

        ptr = strtok(row, ",");
        while (ptr != NULL) {
            switch (++cnt) {
            case 1: strcpy(curMember.uid, ptr); break;
            case 2: strcpy(curMember.roomNumber, ptr); break;
            case 3: strcpy(curMember.name, ptr); break;
            case 4: strcpy(curMember.licensePlate, ptr); break;
            }
            ptr = strtok(NULL, ",");
        }
        addMember(list, curMember);
    }
    fclose(file);
}

void writeData(const char* fileName, MemberNode* list) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }

    MemberNode* ptr = list;
    while (ptr != NULL) {
        fprintf(file, "%s,%s,%s,%s\n", ptr->data.uid, ptr->data.roomNumber, ptr->data.name, ptr->data.licensePlate);
        ptr = ptr->next;
    }

    fclose(file);
}
