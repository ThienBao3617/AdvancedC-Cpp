//#define _CRT_SECURE_NO_WARNINGS
#include "structure.h"

MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

Member* enterDataNewMember() {
    Member* member = (Member*)malloc(sizeof(Member));
    if (!member) {
        printf("Memory allocation error\n");
        exit(1);
    }

    printf("Enter the new information of resident\n");
    printf("Enter UID: ");
    if (scanf("%19s", member->uid) != 1) {
        printf("Error reading UID\n");
        free(member);
        return NULL;
    }

    printf("Enter room number: ");
    if (scanf("%9s", member->roomNumber) != 1) {
        printf("Error reading room number\n");
        free(member);
        return NULL;
    }

    printf("Enter name: ");
    if (scanf("%49s", member->name) != 1) {
        printf("Error reading name\n");
        free(member);
        return NULL;
    }

    printf("Enter license plate: ");
    if (scanf("%19s", member->licensePlate) != 1) {
        printf("Error reading license plate\n");
        free(member);
        return NULL;
    }

    return member;
}

int sizeApartment(MemberNode* list) {
    int count = 0;
    MemberNode* ptr = list;
    while (ptr != NULL) {
        ptr = ptr->next;
        ++count;
    }
    return count;
}

void addMember(MemberNode** list, Member member) {
    MemberNode* newNode = createMemberNode(member);
    if (*list == NULL) {
        *list = newNode;
    }
    else {
        MemberNode* ptr = *list;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void deleteMember(MemberNode** list, const char* uid) {
    MemberNode* ptr = *list;
    MemberNode* prev = NULL;

    while (ptr != NULL && strcmp(ptr->data.uid, uid) != 0) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Member with UID %s not found.\n", uid);
        return;
    }

    if (prev == NULL) {
        *list = ptr->next;
    }
    else {
        prev->next = ptr->next;
    }

    free(ptr);
}

void editMember(MemberNode** list, const char* uid) {
    MemberNode* cur = *list;

    while (cur != NULL) {
        if (strcmp(cur->data.uid, uid) == 0) {
            Member* newEdit = enterDataNewMember();
            if (newEdit == NULL) {
                printf("Failed to edit member.\n");
                return;
            }

            strcpy(cur->data.roomNumber, newEdit->roomNumber);
            strcpy(cur->data.name, newEdit->name);
            strcpy(cur->data.licensePlate, newEdit->licensePlate);

            free(newEdit);
            return;
        }
        cur = cur->next;
    }
    printf("Member with UID %s not found.\n", uid);
}

void getInfo(Member* member) {
    printf("UID: %s\n", member->uid);
    printf("Room Number: %s\n", member->roomNumber);
    printf("Name: %s\n", member->name);
    printf("License Plate: %s\n", member->licensePlate);
    printf("__________________________________________\n");
}

void searchByUID(MemberNode* list, const char* uid) {
    MemberNode* ptr = list;
    while (ptr != NULL) {
        if (strcmp(ptr->data.uid, uid) == 0) {
            getInfo(&(ptr->data));
            return;
        }
        ptr = ptr->next;
    }
    printf("Member with UID %s not found.\n", uid);
}

void searchByLicensePlate(MemberNode* list, const char* licensePlate) {
    MemberNode* ptr = list;
    while (ptr != NULL) {
        if (strcmp(ptr->data.licensePlate, licensePlate) == 0) {
            getInfo(&(ptr->data));
            return;
        }
        ptr = ptr->next;
    }
    printf("Member with License Plate %s not found.\n", licensePlate);
}

void searchMember(MemberNode* list) {
    int searchFunc;
    char searchValue[20];
    printf("Enter the method you want to find \n");
    printf("1. Search by UID \n");
    printf("2. Search by license plate \n");
    if (scanf("%d", &searchFunc) != 1) {
        printf("Error reading choice\n");
        return;
    }

    if (searchFunc == 1) {
        printf("Enter UID: ");
        if (scanf("%19s", searchValue) != 1) {
            printf("Error reading UID\n");
            return;
        }
        searchByUID(list, searchValue);
    }
    else if (searchFunc == 2) {
        printf("Enter License Plate: ");
        if (scanf("%19s", searchValue) != 1) {
            printf("Error reading License Plate\n");
            return;
        }
        searchByLicensePlate(list, searchValue);
    }
    else {
        printf("Invalid choice. Please try again.\n");
    }
}
