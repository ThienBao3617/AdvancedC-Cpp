#ifndef BOOKINGMGR_HPP
#define BOOKINGMGR_HPP

using namespace std;

#include <vector>
#include <string>
#include "Booking.hpp"

class BookingManager {
private:
    vector<Booking> bookings;

public:
    BookingManager();
    ~BookingManager();

    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;

    void addBooking(const Booking& b);   // add 1 booking directly (usually called when the guest checks out)
    void displayAllBookings() const;

    // calculate revenue by day (YYYY-MM-DD) and by month (YYYY-MM)
    double calculateRevenueByDate(const string& date) const;
    double calculateRevenueByMonth(const string& month) const;

    void showMenuRevenue() const; // Menu only calculates revenue report
};

#endif 
