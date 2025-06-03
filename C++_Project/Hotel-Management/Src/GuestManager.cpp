#include "GuestManager.hpp"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

GuestManager::GuestManager() {}

GuestManager::~GuestManager() {}

void GuestManager::loadFromFile(const string& filename) {
    guests.clear();
    ifstream inFile(filename);
    if(!inFile.is_open()) {
        cerr << "Error: cannot open file " << filename << "\n";
        return;
    }
    string line;
    getline(inFile, line); // remove header
    while(getline(inFile, line)) {
        if(line.empty()) continue;
        Guest g = Guest::fromCSV(line);
        guests.push_back(g);
    }
    inFile.close();
}

void GuestManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if(!outFile.is_open()) {
        cerr << "Error: cannot write to file " << filename << "\n";
        return;
    }
    outFile << "guestID,name,phone,checkIn,checkOut,roomID\n";
    for(const auto& g : guests) {
        outFile << g.toCSV() << "\n";
    }
    outFile.close();
}

int GuestManager::findGuestIndex(int guestID) const {
    for(size_t i = 0; i < guests.size(); ++i) {
        if(guests[i].getID() == guestID) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool GuestManager::isGuestExist(int guestID) const {
    return findGuestIndex(guestID) != -1;
}

void GuestManager::addGuest(RoomManager& roomMgr) {
    int id, roomID;
    string name, phone, inD, outD;

    cout << "Enter Guest ID: ";
    cin >> id;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Guest ID again: ";
        cin >> id;
    }
    if(isGuestExist(id)) {
        cout << "Guest " << id << " already exists.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Guest Name: ";
    getline(cin, name);

    cout << "Enter Guest Phone: ";
    getline(cin, phone);

    cout << "Enter Check-in Date (YYYY-MM-DD): ";
    getline(cin, inD);

    cout << "Enter Check-out Date (YYYY-MM-DD): ";
    getline(cin, outD);

    cout << "Enter Room ID to book: ";
    cin >> roomID;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Room ID again: ";
        cin >> roomID;  
    }

    if(!roomMgr.isRoomExist(roomID)) {
        cout << "Room " << roomID << " does not exist.\n";
        return;
    }
    if(!roomMgr.isRoomAvailable(roomID)) {
        cout << "Room " << roomID << " is not available.\n";
        return;
    }

    // all conditions is OK, book room
    Guest newGuest(id, name, phone, inD, outD, roomID);
    guests.push_back(newGuest);
    roomMgr.bookRoom(roomID);
    cout << "Guest added and room booked successfully.\n";
}

void GuestManager::modifyGuest(int guestID) {
    int idx = findGuestIndex(guestID);
    if(idx == -1) {
        cout << "Guest " << guestID << " not found.\n";
        return;
    }
    cout << "Current Name: " << guests[idx].getName() << "\n";
    cout << "Enter new Name: ";
    string newName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newName);
    guests[idx].setName(newName);

    cout << "Current Phone: " << guests[idx].getPhone() << "\n";
    cout << "Enter new Phone: ";
    string newPhone;
    getline(cin, newPhone);
    guests[idx].setPhone(newPhone);

    cout << "Guest " << guestID << " updated successfully.\n";
}

void GuestManager::deleteGuest(int guestID) {
    int idx = findGuestIndex(guestID);
    if(idx == -1) {
        cout << "Guest " << guestID << " not found.\n";
        return;
    }
    guests.erase(guests.begin() + idx);
    cout << "Guest " << guestID << " deleted successfully.\n";
}

void GuestManager::displayAllGuests() const {
    std::cout << "------------------------------------------------------------\n";
    std::cout << "| ID\t| Name\t| Phone\t| CheckIn\t| CheckOut\t| RoomID |\n";
    std::cout << "------------------------------------------------------------\n";
    for (const auto& g : guests) {
        g.display();
    }
    std::cout << "------------------------------------------------------------\n";
}

void GuestManager::checkOutGuest(int guestID, RoomManager& roomMgr) {
    int idx = findGuestIndex(guestID);
    if (idx == -1) {
        std::cout << "Guest " << guestID << " not found.\n";
        return;
    }
    int roomID = guests[idx].getRoomID();
    roomMgr.checkoutRoom(roomID);
    // after checkout, remove record if wanted
    guests.erase(guests.begin() + idx);
    std::cout << "Guest checked out and record removed.\n";
}

void GuestManager::searchGuestByName(const string& name) const {
    bool found = false;
    for(const auto& g : guests) {
        if(g.getName().find(name) != string::npos) {
            g.display();
            found = true;
        }
    }
    if(!found) {
        cout << "No guest found with name containing \"" << name << "\".\n";
    }
}

void GuestManager::showMenu(RoomManager& roomMgr) {
    int choice;
    do {
        std::cout << "\n====== Guest Management ======\n";
        std::cout << "1. Display all guests\n";
        std::cout << "2. Add new guest & book\n";
        std::cout << "3. Modify guest info\n";
        std::cout << "4. Delete guest\n";
        std::cout << "5. Check out guest\n";
        std::cout << "6. Search guest by name\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                displayAllGuests();
                break;
            case 2:
                addGuest(roomMgr);
                break;
            case 3: {
                int id;
                std::cout << "Enter Guest ID to modify: ";
                std::cin >> id;
                modifyGuest(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Guest ID to delete: ";
                std::cin >> id;
                deleteGuest(id);
                break;
            }
            case 5: {
                int id;
                std::cout << "Enter Guest ID to check out: ";
                std::cin >> id;
                checkOutGuest(id, roomMgr);
                break;
            }
            case 6: {
                std::string name;
                std::cout << "Enter name keyword to search: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                searchGuestByName(name);
                break;
            }
            case 0:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
