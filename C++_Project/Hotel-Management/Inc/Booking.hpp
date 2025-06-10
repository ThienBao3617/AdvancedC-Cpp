#ifndef BOOKING_HPP
#define BOOKING_HPP

using namespace std;

#include <string>
#include <sstream>

class Booking {
private:
    int bookingID;         
    int guestID;           
    int roomID;            
    string checkIn;   
    string checkOut;  
    double roomCharge;     // room rate = number of nights * room rate at that time
    double serviceCharge;  // total cost of services incurred
    double totalCharge;    // totalCharge = roomCharge + serviceCharge

public:
    Booking();
    Booking(int bID, int gID, int rID, const string& inD, 
            const string& outD, double rCharge, double sCharge);
    ~Booking();

    // Getters
    int getBookingID() const;
    int getGuestID() const;
    int getRoomID() const;
    string getCheckIn() const;
    string getCheckOut() const;
    double getRoomCharge() const;
    double getServiceCharge() const;
    double getTotalCharge() const;

    // toCSV, fromCSV
    string toCSV() const;
    static Booking fromCSV(const string& csvLine);

    // Display Booking info
    void display() const;
};

#endif
