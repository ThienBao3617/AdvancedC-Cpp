#include "BookingManager.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>

using namespace std;

BookingManager::BookingManager() {}
BookingManager::~BookingManager() {}

void BookingManager::loadFromFile(const string& filename) {
    bookings.clear();
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: cannot open file " << filename << "\n";
        return;
    }
    string line;
    getline(inFile, line); // remove header
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        Booking b = Booking::fromCSV(line);
        bookings.push_back(b);
    }
    inFile.close();
}

void BookingManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: cannot write to file " << filename << "\n";
        return;
    }
    outFile << "bookingID,guestID,roomID,checkIn,checkOut,roomCharge,serviceCharge,totalCharge\n";
    for (const auto& b : bookings) {
        outFile << b.toCSV() << "\n";
    }
    outFile.close();
}

void BookingManager::addBooking(const Booking& b) {
    bookings.push_back(b);
    cout << "Booking record added.\n";
}

void BookingManager::displayAllBookings() const {
    cout << "-------------------------------------------------------------"
              << "--------------------------------\n";
    cout << "| BkID\t| GuestID\t| RoomID\t| CheckIn\t| CheckOut\t| "
                 "RCharge\t| SCharge\t| Total\t|\n";
    cout << "-------------------------------------------------------------"
              << "--------------------------------\n";
    for (const auto& b : bookings) {
        b.display();
    }
    cout << "-------------------------------------------------------------"
              << "--------------------------------\n";
}

// Calculate revenue for a specific day (YYYY-MM-DD)
double BookingManager::calculateRevenueByDate(const string& date) const {
    double sum = 0.0;
    for (const auto& b : bookings) {
        if (b.getCheckIn() <= date && date < b.getCheckOut()) {
            // if date in the range of [checkIn, checkOut)
            sum += b.getTotalCharge();
        }
    }
    return sum;
}

//  Calculate revenue for a month (YYYY-MM)
double BookingManager::calculateRevenueByMonth(const string& month) const {
    double sum = 0.0;
    for (const auto& b : bookings) {
        if (b.getCheckIn().substr(0,7) == month || b.getCheckOut().substr(0,7) == month) {
            sum += b.getTotalCharge();
        }
    }
    return sum;
}

void BookingManager::showMenuRevenue() const {
    int choice;
    do {
        cout << "\n====== Revenue Report ======\n";
        cout << "1. Display all booking records\n";
        cout << "2. Calculate revenue by date\n";
        cout << "3. Calculate revenue by month\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayAllBookings();
                break;
            case 2: {
                string date;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                double rev = calculateRevenueByDate(date);
                cout << "Revenue on " << date << ": " << rev << "\n";
                break;
            }
            case 3: {
                string month;
                cout << "Enter month (YYYY-MM): ";
                cin >> month;
                double rev = calculateRevenueByMonth(month);
                cout << "Revenue in " << month << ": " << rev << "\n";
                break;
            }
            case 0:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
