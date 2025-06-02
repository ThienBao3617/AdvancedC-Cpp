#include "Guest.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// --- Constructor & Destructor ---
Guest::Guest() : guestID(0), name(""), phone(""), checkInDate(""), checkOutDate(""), roomID(0) {}

Guest::Guest(int id, const string& n, const string& ph, const string& inDate, const string& outDate, int rID) : guestID(id), name(n), phone(ph), checkInDate(inDate), checkOutDate(outDate), roomID(rID) {}

Guest::~Guest() {}

// --- Accessors ---
int Guest::getID() const { return guestID; }
string Guest::getName() const { return name; }
string Guest::getPhone() const { return phone; }
string Guest::getCheckInDate() const { return checkInDate; }
string Guest::getCheckOutDate() const { return checkOutDate; }
int Guest::getRoomID() const { return roomID; }

// --- Mutators ----
void Guest::setName(const string& n) { name = n; }
void Guest::setPhone(const string& ph) { phone = ph; }
void Guest::setCheckInDate(const string& inD) { checkInDate = inD; }
void Guest::setCheckOutDate(const string& outD) { checkOutDate = outD; }
void Guest::setRoomID(int rID) { roomID = rID; }

// --- toCSV ---
string Guest::toCSV() const {
	ostringstream oss;
	oss << guestID << ","
	    << name << ","
	    << phone << ","
	    << checkInDate << ","
	    << checkOutDate << ","
	    << roomID;
	return oss.str();
}

// --- fromCSV ---
Guest Guest::fromCSV(const string& csvLine) {
	istringstream iss(csvLine);
	string token;
	int id = 0, rID = 0;
	string n, ph, inD, outD;

	getline(iss, token, ',');
	id = stoi(token);
	getline(iss, n, ',');
	getline(iss, ph, ',');
	getline(iss, inD, ',');
	getline(iss, outD, ',');
	getline(iss, token, ',');
	rID = stoi(token);

	return Guest(id, n, ph, inD, outD, rID);
}

// --- display ---
void Guest::display() const {
	cout << "| " << guestID << "\t| "
	     << name << "\t| "
	     << phone << "\t| "
	     << checkInDate << "\t| "
	     << checkOutDate << "\t| "
	     << roomID << " |\n";
}
