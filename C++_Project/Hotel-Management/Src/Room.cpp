#include "Room.hpp"
#include <sstream> // use for parse CSV
#include <iostream>

using namespace std;

// --- Constructors & Destructors ---
Room::Room() : roomID(0), type(""), price(0.0), isBooked(false) {}

Room::Room(int id, const string& t, double p, bool booked)
    : roomID(id), type(t), price(p), isBooked(booked) {}

Room::~Room() {}

// --- Accessors ---
int Room::getID() const { return roomID; }
string Room::getType() const { return type; }
double Room::getPrice() const { return price; }
bool Room::getIsBooked() const { return isBooked; }

// --- Mutators ---
void Room::setType(const string& newType) { type = newType; }
void Room::setPrice(double newPrice) { price = newPrice; }
void Room::setBooked(bool booked) { isBooked = booked; }

// --- toCSV ---
string Room::toCSV() const{
    ostringstream oss;
    oss << roomID << "," << type << "," << price << "," << (isBooked ? 1 : 0);
    return oss.str();
}

// --- fromCSV ---
Room Room::fromCSV(const string& csvLine){
    istringstream iss(csvLine);
    string token;
    int id = 0;
    string t = "";
    double p = 0.0;
    bool booked = false;

    // Separate each token with a ',' 
    getline(iss, token, ',');
    id = stoi(token);
    getline(iss, t, ',');
    getline(iss, token, ',');
    p = stod(token);
    getline(iss, token, ',');
    booked = (token == "1" || token == "true");

    return Room(id, t, p, booked);
}

// --- display ---
void Room::display() const{
    cout << "| "
         << roomID << "\t| "
         << type << "\t| "
         << price << "\t| "
         << (isBooked ? "Booked" : "Available")
         << " |\n";
}