#ifndef __DATA_H_
#define __DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char uid[20]; 
    char roomNumber[10]; 
    char name[50]; 
    char licensePlate[20]; 
} Member;

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member);
Member* enterDataNewMember();
int sizeApartment(MemberNode* list);
void addMember(MemberNode** list, Member member);
void deleteMember(MemberNode** list, const char* uid);
void editMember(MemberNode** list, const char* uid);
void getInfo(Member* member);
void searchByUID(MemberNode* list, const char* uid);
void searchByLicensePlate(MemberNode* list, const char* licensePlate);
void searchMember(MemberNode* list);

#endif