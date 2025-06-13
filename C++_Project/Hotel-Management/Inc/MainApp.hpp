#ifndef MAINAPP_HPP
#define MAINAPP_HPP

using namespace std;

#include "RoomManager.hpp"
#include "GuestManager.hpp"
#include "ServiceManager.hpp"
#include "BookingManager.hpp"
#include "UI.hpp"

class MainApp {
private:
    RoomManager roomMgr;
    GuestManager guestMgr;
    ServiceManager serviceMgr;
    BookingManager bookingMgr;

    // File paths
    const string roomFile    = "Data/room.csv";
    const string guestFile   = "Data/guest.csv";
    const string serviceFile = "Data/service.csv";
    const string bookingFile = "Data/booking.csv";

public:
    MainApp();
    ~MainApp();

    // function to load all the data when booting
    void loadAllData();

    // function to save all the data before exit
    void saveAllData();

    // UI for main Menu
    void showMainMenu();
};

#endif 