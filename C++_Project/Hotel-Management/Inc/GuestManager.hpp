#ifndef GUESTMANAGER_HPP
#define GUESTMANAGER_HPP

using namespace std;

#include <vector>
#include <string>
#include "Guest.hpp"
#include "RoomManager.hpp" // to check the room's availability

class GuestManager {
private:
	vector<Guest> guests;
public:
	GuestManager();
	~GuestManager();

	void loadFromFile(const string& filename);
	void saveToFile(const string& filename) const;

	void addGuest(RoomManager& roomMgr); // Require user to enter info and book room
	void modifyGuest(int guestID); // Edit guest info (not including room changes)
	void deleteGuest(int guestID); // Delete guest (but need to check if checked out yet)
	void displayAllGuests() const;

	int findGuestIndex(int guestID) const;
	bool isGuestExist(int guestID) const;

	void checkOutGuest(int guetsID, RoomManager& roomMgr); // when checkout, room will be set into "available"
	
	// Allows searching for guests by name/ID, etc.
	void searchGuestByName(const string& name) const;

	void showMenu(RoomManager& roomMgr); // separate menu for this module
};

#endif
