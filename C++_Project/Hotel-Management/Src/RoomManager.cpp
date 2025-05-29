#include "RoomManager.hpp"
#include <fstream>
#include <iostream>
#include <limits>      // use for ignore wrong input

using namespace std;

RoomManager::RoomManager() {}

RoomManager::~RoomManager() {}

void RoomManager::loadFromFile(const string& filename) {}

void RoomManager::saveToFile(const string& filename) const {}

int RoomManager::findRoomIndex(int roomID) const {}

bool RoomManager::isRoomExist(int roomID) const {}

bool RoomManager::isRoomAvailable(int roomID) const {}

void RoomManager::bookRoom(int roomID) {}

void RoomManager::checkoutRoom(int roomID) {}

void RoomManager::displayAllRooms() const {}

void RoomManager::addRoom() {}

void RoomManager::modifyRoom(int roomID) {}

void RoomManager::deleteRoom(int roomID) {}

void RoomManager::showMenu() {}