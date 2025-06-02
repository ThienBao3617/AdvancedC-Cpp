#include "GuestManager.hpp"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

GuestManager::GuestManager() {}

GuestManager::~GuestManager() {}

void GuestManager::loadFromFile(const string& filename) {}

void GuestManager::saveToFile(const string& filename) const {}

int GuestManager::findGuestIndex(int guestID) const {}

bool GuestManager::isGuestExist(int guestID) const {}

void GuestManager::addGuest(RoomManager& roomMgr) {}

void GuestManager::modifyGuest(int guestID) const {}

void GuestManager::deleteGuest(int guestID) {}

void GuestManager::displayAllGuest() const {}

void GuestManager::checkOutGuest(int guestID, RoomManager& roomMgr) {}

void GuestManager::searchGuestByName(const string& name) const {}

void GuestManager::showMenu(RoomManager& roomMgr) {}
