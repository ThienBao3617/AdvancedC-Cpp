#ifndef ROOM_HPP
#define ROOM_HPP

using namespace std;

#include <string>

class Room{
private:
    int roomID; // room's code, e.g. 101, 102,..
    string type; // room's type: "single", "double", "suite"
    double price; // room's price (per night)
    bool isBooked; // true = had been booked, false = available

public:
    // --- Constructor & Destructor ---
    Room();
    Room(int id, const string& type, double price, bool booked = false);
    ~Room();

    // --- Accessors ---
    int getID() const;
    string getType() const;
    double getPrice() const;
    bool getIsBooked() const;

    // --- Mutators ---
    void setType(const string& newType);
    void setPrice(double newPrice);
    void setBooked(bool booked);

    // convert Room into string CSV (forming "101,Single,500,0")
    string toCSV() const;

    // init Room from string CSV (split and parse)
    static Room fromCSV(const string& csvLine);

    // display room's info in the console
    void display() const;
};

#endif