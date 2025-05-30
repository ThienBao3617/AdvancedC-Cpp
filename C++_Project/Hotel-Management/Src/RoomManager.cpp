#include "RoomManager.hpp"
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

bool RoomManager::isRoomAvailable(int roomID) const {}

void RoomManager::bookRoom(int roomID) {}

void RoomManager::checkoutRoom(int roomID) {}

void RoomManager::displayAllRooms() const {}

void RoomManager::addRoom() {}

void RoomManager::modifyRoom(int roomID) {}

void RoomManager::deleteRoom(int roomID) {}

void RoomManager::showMenu() {}