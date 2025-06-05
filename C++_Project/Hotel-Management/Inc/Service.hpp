#ifndef SERVICE_HPP
#define SERVICE_HPP

using namespace std;

#include <string>
#include <sstream>

class Service {
private:
    int serviceID;        // service ID
    string name;     // service name (Laundry, Food, Spa…)
    double price;         // service price (unit: VNĐ)

public:
    Service();
    Service(int id, const string& n, double p);
    ~Service();

    // Accessors
    int getID() const;
    string getName() const;
    double getPrice() const;

    // Mutators
    void setName(const string& n);
    void setPrice(double p);

    // toCSV, fromCSV
    string toCSV() const;
    static Service fromCSV(const string& csvLine);

    // Display
    void display() const;
};

#endif 
