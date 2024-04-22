#include <stdio.h>

// action 1: print error message
void printError(const char *message) {
    printf("Error: %s\n", message);
}

// action 2: print warning message
void printWarning(const char *message) {
    printf("Warning: %s\n", message);
}

// add more contents

// action 3: print content message
void printContent(const char *message) {
    printf("Content: %s\n", message);
}

// action 4: print fix error message
void printFix(const char *message) {
    printf("Fix: %s\n", message);
}


// action 5: print message succesfully updated
void printUpdate(const char *message) {
    printf("Update: %s\n", message);
}

// Macro fix_error
#define HANDLE_ERROR(condition,action, message) \
do  { \
    if (condition){ \
    action(message); \
    }\
    } while(0)

int main() {
    int x = 5;

    // using HANDLE_ERROR with different actions
    HANDLE_ERROR(x > 10, printError, "x is not greater than 10");
    HANDLE_ERROR(x == 10, printError, "x is not equal to 10");
    HANDLE_ERROR(x < 10, printWarning, "x is less than 10");
    HANDLE_ERROR(x == 5, printUpdate, "x is equal to 5");

    return 0;
}