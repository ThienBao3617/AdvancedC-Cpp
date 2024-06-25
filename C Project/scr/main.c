//#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"

void displayMenu(const char* fileName, MemberNode** list) {
    int choice = 0;
    char uid[20];

    while (1) {
        printf("\n_________List of Options_________\n");
        printf("1. Population numbers\n");
        printf("2. Add a new resident\n");
        printf("3. Search resident information\n");
        printf("4. Edit resident information\n");
        printf("5. Delete resident from list\n");
        printf("6. Exit program\n");

        printf("Enter your option: ");
        if (scanf_s("%d", &choice) != 1) {
            printf("Error reading choice\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
        case 1:
            printf("Number of residents: %d\n", sizeApartment(*list));
            break;
        case 2: {
            Member* newMember = enterDataNewMember();
            if (newMember == NULL) {
                printf("Failed to add new member.\n");
                break;
            }
            addMember(list, *newMember);
            free(newMember);
            writeData(fileName, *list);
            break;
        }
        case 3:
            searchMember(*list);
            break;
        case 4:
            printf("Enter UID of the resident to edit: ");
            if (scanf("%19s", uid) != 1) {
                printf("Error reading UID\n");
                break;
            }
            editMember(list, uid);
            writeData(fileName, *list);
            break;
        case 5:
            printf("Enter UID of the resident to delete: ");
            if (scanf("%19s", uid) != 1) {
                printf("Error reading UID\n");
                break;
            }
        }
    }
}