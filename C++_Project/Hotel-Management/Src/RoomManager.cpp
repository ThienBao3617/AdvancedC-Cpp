#include "RoomManager.hpp"
#include "Utils.hpp" 
#include <fstream> // use for read file, write file
#include <iostream>
#include <limits> // use for ignore wrong input

using namespace std;

RoomManager::RoomManager() {}

RoomManager::~RoomManager() {}

void RoomManager::loadFromFile(const string& filename) {
    rooms.clear();
    ifstream inFile(filename);
    if(!inFile.is_open()){
        cerr << "Error: cannot open file " << filename << "\n";
        return;
    }

    string line;
    // remove header (if any)
    getline(inFile, line);
    while(getline(inFile, line)){
        if(line.empty()) continue;
        Room r = Room::fromCSV(line);
        rooms.push_back(r);
    }
    inFile.close();
}

void RoomManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if(!outFile.is_open()){
        cerr << "Error: cannot write to file " << filename << "\n";
        return;
    }
    // write header
    outFile << "roomID,type,price,isBooked\n";
    for(const auto& r : rooms){
        outFile << r.toCSV() << "\n";
    }
    outFile.close();
}

int RoomManager::findRoomIndex(int roomID) const {
    for(size_t i = 0; i < rooms.size(); i++){
        if(rooms[i].getID() == roomID){
            return static_cast<int>(i);
        }
    }
    return -1; // not found
}

bool RoomManager::isRoomExist(int roomID) const {
    return findRoomIndex(roomID) != -1;
}

bool RoomManager::isRoomAvailable(int roomID) const {
    int idx = findRoomIndex(roomID);
    if(idx == -1) return false;
    return !rooms[idx].getIsBooked();
}

void RoomManager::bookRoom(int roomID) {
    int idx = findRoomIndex(roomID);
    if(idx == -1){
        cout << "Room " << roomID << " not found.\n";
        return;
    }
    if(rooms[idx].getIsBooked()){
        cout << "Room " << roomID << " is already booked.\n";
        return;
    }
    rooms[idx].setBooked(true);
    cout << "Room " << roomID << " booked successfully.\n";
}

void RoomManager::checkoutRoom(int roomID) {
    int idx = findRoomIndex(roomID);
    if(idx == -1){
        cout << "Room " << roomID << " not found.\n";
        return;
    }
    if(!rooms[idx].getIsBooked()){
        cout << "Room " << roomID << " is not currently booked.\n";
        return;
    }
    rooms[idx].setBooked(false);
    cout << "Room " << roomID << " is now available.\n";
}

void RoomManager::displayAllRooms() const {
    cout << "-------------------------------------------\n";
    cout << " ID\t| Type\t| Price\t| Status    |\n";
    cout << "-------------------------------------------\n";
    for(const auto& r : rooms){
        r.display();
    }
    cout << "-------------------------------------------\n";
}

void RoomManager::addRoom() {
    int id;
    string t;
    double p;

    cout << "Enter Room ID: ";
    cin >> id;
    // check if enter wrong
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Room ID again: ";
        cin >> id;
    }

    if(isRoomExist(id)){
        cout << "Room " << id << " already exists.\n";
        return;
    }

    cout << "Enter Room Type (e.g., Single/Double/Suite): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t);

    cout << "Enter Price per night: ";
    cin >> p;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Price again: ";
        cin >> p;
    }

    Room newRoom(id, t, p, false);
    rooms.push_back(newRoom);
    cout << "Room added successfully.\n";
}

void RoomManager::modifyRoom(int roomID) {
    int idx = findRoomIndex(roomID);
    if(idx == -1){
        cout << "Room " << roomID << " not found.\n";
        return;
    }

    cout << "Current Type: " << rooms[idx].getType() << "\n";
    cout << "Enter new Type: ";
    string newType;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newType);
    rooms[idx].setType(newType);

    cout << "Current Price: " << rooms[idx].getPrice() << "\n";
    cout << "Enter new Price: ";
    double newPrice;
    cin >> newPrice;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter new Price again: ";
        cin >> newPrice;
    }
    rooms[idx].setPrice(newPrice);

    cout << "Room " << roomID << " update successfully.\n";
}

void RoomManager::deleteRoom(int roomID) {
    int idx = findRoomIndex(roomID);
    if(idx == -1){
        cout << "Room " << roomID << " not found.\n";
        return;
    }
    rooms.erase(rooms.begin() + idx);
    cout << "Room " << roomID << " deleted successfully.\n";
}

void RoomManager::showMenu() {
    int choice;
    int id;
    do{
        cout << "\n===== Room Management =====\n";
        cout << "1. Display all rooms\n";
        cout << "2. Add new room\n";
        cout << "3. Modify room\n";
        cout << "4. Delete room\n";
        cout << "5. Book room\n";
        cout << "6. Check out room\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                displayAllRooms();
                break;
            case 2:
                addRoom();
                break;
            case 3:
                cout << "Enter Room ID to modify: ";
                cin >> id;
                modifyRoom(id);
                break;
            case 4:
                cout << "Enter Room ID to delete: ";
                cin >> id;
                deleteRoom(id);
                break;
            case 5:
                cout << "Enter Room ID to book: ";
                cin >> id;
                bookRoom(id);
                break;
            case 6:
                cout << "Enter Room ID to check out: ";
                cin >> id;
                checkoutRoom(id);
                break;
            case 0:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }while (choice != 0);
}