#ifndef _MACHINE_H_
#define _MACHINE_H_
#include <string>
#include <iostream>

using namespace std;

/* TO DO (now implemented)
* Define attributes
* Getters and Setters
* Constructors and destructor
* Use of static variables
* Operator overloads (>,<,+,=)
* Copy assign operator
* Copy constructor
* Type conversion
* Friend stream operator
*/

class Machine {
private:
    string model;            // Model name / number (e.g., "UT0037 Pump")
    int    currentLoad;      // Current load/utilisation in percent [0..100]
    int    maintenanceLevel; // 1 (low) .. 5 (high) maintenance requirement
    double hoursRun;         // Total operating hours
    int    maxOutput;        // Peak output capacity (units/hour)
    string category;         // e.g., "CNC", "3D Printer", "Pump", "Robot Arm"
    bool   isNetworked;      // Connected to network/IoT?
    int    manufactureYear;  // Year of manufacture
    string manufacturer;     // Vendor name
    static int count;        // Number of Machine objects alive

public:
    // ctors / dtor
    Machine();
    Machine(string modelValue, int loadValue, int maintLevel,
            string categoryValue, bool networked, int year,
            string manufacturerValue, int peakOutput);
    Machine(const Machine &other);
    ~Machine();

    // bulk setter
    void setAttributes(string modelValue, int loadValue, int maintLevel,
                       string categoryValue, bool networked, int year,
                       string manufacturerValue, int peakOutput);

    // getters
    string getModel();
    int    getCurrentLoad();
    int    getMaintenanceLevel();
    double getHoursRun();
    int    getMaxOutput();
    string getCategory();
    bool   getIsNetworked();
    int    getManufactureYear();
    string getManufacturer();
    int    getCount();

    // actions
    void operate(double hours);          // accumulate run time
    void updateMaxOutput(int newPeak);   // raise peak capability if higher

    // operators
    bool   operator>(const Machine &other) const;
    bool   operator<(const Machine &other) const;
    Machine operator+(const Machine &other) const; // combine loads; keep max peak
    Machine& operator=(const Machine &other);

    // conversions / friends
    operator string() const;
    friend ostream& operator<<(ostream &os, const Machine &m);
};

#endif
