#include "Booking.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// --- Constructor & Destructor ---
Booking::Booking() : bookingID(0), guestID(0), roomID(0), checkIn(""), checkOut(""), roomCharge(0.0), serviceCharge(0.0), totalCharge(0.0) {}

Booking::Booking(int bID, int gID, int rID, const string& inD, const string& outD, double rCharge, double sCharge)
    : bookingID(bID), guestID(gID), roomID(rID), checkIn(inD), checkOut(outD), roomCharge(rCharge), serviceCharge(sCharge) 
{
    totalCharge = roomCharge + serviceCharge;
}

Booking::~Booking() {}

// --- Accessors ---
int Booking::getBookingID() const { return bookingID; }
int Booking::getGuestID() const { return guestID; }
int Booking::getRoomID() const { return roomID; }
string Booking::getCheckIn() const { return checkIn; }
string Booking::getCheckOut() const { return checkOut; }
double Booking::getRoomCharge() const { return roomCharge; }
double Booking::getServiceCharge() const { return serviceCharge; }
double Booking::getTotalCharge() const { return totalCharge; }

string Booking::toCSV() const {
    ostringstream oss;
    oss << bookingID << "," << guestID << "," << roomID << ","
        << checkIn << "," << checkOut << ","
        << roomCharge << "," << serviceCharge << "," << totalCharge;
    return oss.str();
}

Booking Booking::fromCSV(const string& csvLine) {
    istringstream iss(csvLine);
    string token;
    int bID = 0, gID = 0, rID = 0;
    string inD, outD;
    double rCharge = 0.0, sCharge = 0.0, tCharge = 0.0;

    getline(iss, token, ',');
    bID = stoi(token);
    getline(iss, token, ',');
    gID = stoi(token);
    getline(iss, token, ',');
    rID = stoi(token);
    getline(iss, inD, ',');
    getline(iss, outD, ',');
    getline(iss, token, ',');
    rCharge = stod(token);
    getline(iss, token, ',');
    sCharge = stod(token);
    getline(iss, token, ',');
    tCharge = stod(token);

    Booking b(bID, gID, rID, inD, outD, rCharge, sCharge);
    b.totalCharge = tCharge; 
    return b;
}

void Booking::display() const {
    cout << "| " << bookingID << "\t| "
         << guestID << "\t| "
         << roomID << "\t| "
         << checkIn << "\t| "
         << checkOut << "\t| "
         << roomCharge << "\t| "
         << serviceCharge << "\t| "
         << totalCharge << " |\n";
}
