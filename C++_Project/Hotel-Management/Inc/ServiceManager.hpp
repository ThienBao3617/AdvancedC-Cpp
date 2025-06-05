#ifndef SERVICEMGR_HPP
#define SERVICEMGR_HPP

using namespace std;

#include <vector>
#include <string>
#include "Service.hpp"

class ServiceManager {
private:
    vector<Service> services;

public:
    ServiceManager();
    ~ServiceManager();

    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;

    void addService();
    void modifyService(int serviceID);
    void deleteService(int serviceID);
    void displayAllServices() const;

    int findServiceIndex(int serviceID) const;
    bool isServiceExist(int serviceID) const;

    // Allows assigning services to a booking (choice optional)
    double getServicePrice(int serviceID) const;

    void showMenu();
};

#endif 
