#include "ServiceManager.hpp"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

ServiceManager::ServiceManager() {}
ServiceManager::~ServiceManager() {}

void ServiceManager::loadFromFile(const string& filename) {
    services.clear();
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: cannot open file " << filename << "\n";
        return;
    }
    string line;
    getline(inFile, line); // remove header
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        Service s = Service::fromCSV(line);
        services.push_back(s);
    }
    inFile.close();
}

void ServiceManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: cannot write to file " << filename << "\n";
        return;
    }
    outFile << "serviceID,name,price\n";
    for (const auto& s : services) {
        outFile << s.toCSV() << "\n";
    }
    outFile.close();
}

int ServiceManager::findServiceIndex(int serviceID) const {
    for (size_t i = 0; i < services.size(); ++i) {
        if (services[i].getID() == serviceID) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool ServiceManager::isServiceExist(int serviceID) const {
    return findServiceIndex(serviceID) != -1;
}

void ServiceManager::addService() {
    int id;
    string name;
    double price;

    cout << "Enter Service ID: ";
    cin >> id;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Service ID again: ";
        cin >> id;
    }
    if (isServiceExist(id)) {
        cout << "Service " << id << " already exists.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Service Name: ";
    getline(cin, name);

    cout << "Enter Service Price: ";
    cin >> price;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter Price again: ";
        cin >> price;
    }

    Service newService(id, name, price);
    services.push_back(newService);
    cout << "Service added successfully.\n";
}

void ServiceManager::modifyService(int serviceID) {
    int idx = findServiceIndex(serviceID);
    if (idx == -1) {
        cout << "Service " << serviceID << " not found.\n";
        return;
    }

    cout << "Current Name: " << services[idx].getName() << "\n";
    cout << "Enter new Name: ";
    string newName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newName);
    services[idx].setName(newName);

    cout << "Current Price: " << services[idx].getPrice() << "\n";
    cout << "Enter new Price: ";
    double newPrice;
    cin >> newPrice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter new Price again: ";
        cin >> newPrice;
    }
    services[idx].setPrice(newPrice);

    cout << "Service " << serviceID << " updated successfully.\n";
}

void ServiceManager::deleteService(int serviceID) {
    int idx = findServiceIndex(serviceID);
    if (idx == -1) {
        cout << "Service " << serviceID << " not found.\n";
        return;
    }
    services.erase(services.begin() + idx);
    cout << "Service " << serviceID << " deleted successfully.\n";
}

void ServiceManager::displayAllServices() const {
    cout << "-------------------------------------\n";
    cout << "| ServiceID\t| Name\t| Price\t|\n";
    cout << "-------------------------------------\n";
    for (const auto& s : services) {
        s.display();
    }
    cout << "-------------------------------------\n";
}

double ServiceManager::getServicePrice(int serviceID) const {
    int idx = findServiceIndex(serviceID);
    if (idx == -1) return 0.0;
    return services[idx].getPrice();
}

void ServiceManager::showMenu() {
    int choice;
    do {
        cout << "\n====== Service Management ======\n";
        cout << "1. Display all services\n";
        cout << "2. Add new service\n";
        cout << "3. Modify service\n";
        cout << "4. Delete service\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayAllServices();
                break;
            case 2:
                addService();
                break;
            case 3: {
                int id;
                cout << "Enter Service ID to modify: ";
                cin >> id;
                modifyService(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Service ID to delete: ";
                cin >> id;
                deleteService(id);
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
