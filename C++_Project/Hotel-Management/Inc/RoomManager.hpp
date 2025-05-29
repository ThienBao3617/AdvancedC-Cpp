#ifndef ROOMMANAGER_HPP
#define ROOMMANAGER_HPP

#include <vector>
#include <string>
#include "Room.hpp"

class RoomManager{
private:
    vector<Room> rooms; // list of all the room

public:
    RoomManager();
    ~RoomManager();

    // --- Load & Save ---
    // read file CSV (e.g. Data/room.csv) and load into vector<Room>
    void loadFromFile(const string& filename);
    // save vector<Room> into file CSV (overwrite or append)
    void saveToFile(const string& filename);

    // --- Operation functions ---
    void addRoom(); // Require user to enter info, add room
    void modifyRoom(int roomID); // Edit room type or price of a given roomID
    void deleteRoom(int roomID); // delete room with roomID
    void displayAllRoom() const; // display table of all the room + status

    bool isRoomExist(int roomID) const; // check if roomID in vector or not
    bool isRoomAvailable(int roomID) const; // check isBooked == false
    void bookRoom(int roomID); // set isBooked = true;
    void checkoutRoom(int roomID); // set isBooked = false

    // --- Searching ---
    int findRoomIndex(int roomID) const; // Returns to index in the vector or -1 if not found

    // --- Menu interface for this module ---
    void showMenu(); 
};

#endif