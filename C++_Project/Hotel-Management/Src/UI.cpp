#include "UI.hpp"
#include <iostream>
#include <limits>


using namespace std;

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

namespace UI {

void printWelcome() {
    std::cout << "=====================================\n";
    std::cout << "   Welcome to Hotel Management App   \n";
    std::cout << "=====================================\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        // ANSI escape code: \033[2J clears screen, \033[H đặt con trỏ về góc trên
        cout << "\033[2J\033[H";
    #endif
}

void pause() {
    cout << "Press ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // If the user just entered a number in the menu, ignore it.
    cin.get();
}

}