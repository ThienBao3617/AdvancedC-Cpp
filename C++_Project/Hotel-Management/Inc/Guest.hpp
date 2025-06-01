#ifndef GUEST_HPP
#define GUEST_HPP

using namespace std;

#include <string>
#include <sstream>

class Guest {
private:
    int guestID;          // guest's code (auto increase or entered by users)
    std::string name;     // full name
    std::string phone;    // phone number
    std::string email;    // if needed
    std::string checkInDate;   // arrived date (e.g., "2023-05-29")
    std::string checkOutDate;  // left date (e.g., "2023-05-31")
    int    roomID;        // reserved room's code

public:
    Guest();
    Guest(int id, const string& n, const string& ph, 
          const string& inDate, const string& outDate, int rID);
    ~Guest();

    // Getters
    int getID() const;
    string getName() const;
    string getPhone() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
    int getRoomID() const;

    // Setters
    void setName(const string& n);
    void setPhone(const string& ph);
    void setCheckInDate(const string& inD);
    void setCheckOutDate(const string& outD);
    void setRoomID(int rID);

    // Convert to CSV: guestID,name,phone,checkIn,checkOut,roomID
    string toCSV() const;

    // Parse từ CSV
    static Guest fromCSV(const string& csvLine);

    // Display thông tin Guest
    void display() const;
};

#endif 
