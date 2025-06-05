#include "Service.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// --- Constructor & Destructor ---
Service::Service() : serviceID(0), name(""), price(0.0) {}
Service::Service(int id, const string& n, double p)
    : serviceID(id), name(n), price(p) {}
Service::~Service() {}

// --- Accessors ---
int Service::getID() const { return serviceID; }
string Service::getName() const { return name; }
double Service::getPrice() const { return price; }

// --- Mutators ---
void Service::setName(const string& n) { name = n; }
void Service::setPrice(double p) { price = p; }

// --- toCSV ---
string Service::toCSV() const {
    ostringstream oss;
    oss << serviceID << "," << name << "," << price;
    return oss.str();
}

// --- fromCSV ---
Service Service::fromCSV(const string& csvLine) {
    istringstream iss(csvLine);
    string token;
    int id = 0;
    string n;
    double p = 0.0;

    getline(iss, token, ',');
    id = stoi(token);
    getline(iss, n, ',');
    getline(iss, token, ',');
    p = stod(token);

    return Service(id, n, p);
}

// --- display ---
void Service::display() const {
    cout << "| " << serviceID << "\t| "
              << name << "\t| "
              << price << "\t|\n";
}
