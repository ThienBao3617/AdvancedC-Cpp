#include "MainApp.hpp"
#include <iostream>
#include <limits>

using namespace std;

MainApp::MainApp() {}

MainApp::~MainApp() {}

void MainApp::loadAllData() {
    cout << "Loading data...\n";
    roomMgr.loadFromFile(roomFile);
    guestMgr.loadFromFile(guestFile);
    serviceMgr.loadFromFile(serviceFile);
    bookingMgr.loadFromFile(bookingFile);
    cout << "Data loaded successfully.\n\n";
}

void MainApp::saveAllData() {
    cout << "Saving data...\n";
    roomMgr.saveToFile(roomFile);
    guestMgr.saveToFile(guestFile);
    serviceMgr.saveToFile(serviceFile);
    bookingMgr.saveToFile(bookingFile);
    cout << "Data saved successfully.\n";
}

void MainApp::showMainMenu() {
    int choice;
    do {
        UI::clearScreen();
        UI::printWelcome();
        cout << "\n====== Main Menu ======\n";
        cout << "1. Room Management\n";
        cout << "2. Guest Management\n";
        cout << "3. Service Management\n";
        cout << "4. Booking History & Revenue\n";
        cout << "5. Save All Data\n";
        cout << "0. Exit Application\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                roomMgr.showMenu();
                UI::pause();
                break;
            case 2:
                guestMgr.showMenu(roomMgr);
                UI::pause();
                break;
            case 3:
                serviceMgr.showMenu();
                UI::pause();
                break;
            case 4:
                bookingMgr.showMenuRevenue();
                UI::pause();
                break;
            case 5:
                saveAllData();
                UI::pause();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                UI::pause();
        }
    } while (choice != 0);

    // before exit, auto save
    saveAllData();
}

