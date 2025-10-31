#include "machine.h"
#include <algorithm>

// initialize static
int Machine::count = 0;

// Default constructor
Machine::Machine() {
    cout << "Machine object created" << endl;
    this->model = "Unknown";
    this->currentLoad = 0;
    this->maintenanceLevel = 1;
    this->hoursRun = 0.0;
    this->maxOutput = 0;
    this->category = "Undefined";
    this->isNetworked = false;
    this->manufactureYear = 2000;
    this->manufacturer = "Unknown";
    count++;
}

// Parameterized constructor
Machine::Machine(string modelValue, int loadValue, int maintLevel,
                 string categoryValue, bool networked, int year,
                 string manufacturerValue, int peakOutput) {
    cout << "Machine object created" << endl;
    this->model = modelValue;
    this->currentLoad = loadValue;
    this->maintenanceLevel = maintLevel;
    this->hoursRun = 0.0;
    this->maxOutput = peakOutput;
    this->category = categoryValue;
    this->isNetworked = networked;
    this->manufactureYear = year;
    this->manufacturer = manufacturerValue;
    count++;
}

// Copy constructor
Machine::Machine(const Machine &other) {
    cout << "Machine object copied" << endl;
    model = other.model;
    currentLoad = other.currentLoad;
    maintenanceLevel = other.maintenanceLevel;
    hoursRun = other.hoursRun;
    maxOutput = other.maxOutput;
    category = other.category;
    isNetworked = other.isNetworked;
    manufactureYear = other.manufactureYear;
    manufacturer = other.manufacturer;
    count++;
}

// Destructor
Machine::~Machine() {
    cout << "Machine object destructed." << endl;
    count--;
}

// Bulk setter
void Machine::setAttributes(string modelValue, int loadValue, int maintLevel,
                            string categoryValue, bool networked, int year,
                            string manufacturerValue, int peakOutput) {
    this->model = modelValue;
    this->currentLoad = loadValue;
    this->maintenanceLevel = maintLevel;
    this->category = categoryValue;
    this->isNetworked = networked;
    this->manufactureYear = year;
    this->manufacturer = manufacturerValue;
    this->maxOutput = peakOutput;
}

// Getters
string Machine::getModel() { return this->model; }
int    Machine::getCurrentLoad() { return this->currentLoad; }
int    Machine::getMaintenanceLevel() { return this->maintenanceLevel; }
double Machine::getHoursRun() { return this->hoursRun; }
int    Machine::getMaxOutput() { return this->maxOutput; }
string Machine::getCategory() { return this->category; }
bool   Machine::getIsNetworked() { return this->isNetworked; }
int    Machine::getManufactureYear() { return this->manufactureYear; }
string Machine::getManufacturer() { return this->manufacturer; }
int    Machine::getCount() { return this->count; }

// Actions
void Machine::operate(double hours) {
    this->hoursRun += hours;
    cout << "Operating " << this->model << " for " << hours << " hours." << endl;
}

void Machine::updateMaxOutput(int newPeak) {
    if (newPeak > this->maxOutput) {
        this->maxOutput = newPeak;
        cout << "New peak output: " << this->maxOutput << " units/hour" << endl;
    }
}

// Operators
bool Machine::operator>(const Machine &other) const {
    return this->maxOutput > other.maxOutput;
}

bool Machine::operator<(const Machine &other) const {
    return this->maxOutput < other.maxOutput;
}

Machine Machine::operator+(const Machine &other) const {
    Machine combined = *this;
    // Combine loads (clamp 0..100); keep the better (higher) peak output
    combined.currentLoad = std::min(100, this->currentLoad + other.currentLoad);
    combined.maxOutput = std::max(this->maxOutput, other.maxOutput);
    // hoursRun unchanged (represents this instance's lifetime)
    return combined;
}

Machine& Machine::operator=(const Machine &other) {
    if (this != &other) {
        model = other.model;
        currentLoad = other.currentLoad;
        maintenanceLevel = other.maintenanceLevel;
        hoursRun = other.hoursRun;
        maxOutput = other.maxOutput;
        category = other.category;
        isNetworked = other.isNetworked;
        manufactureYear = other.manufactureYear;
        manufacturer = other.manufacturer;
    }
    return *this;
}

// Conversion and stream
Machine::operator string() const {
    string s = "Model: " + model +
               " Load:" + to_string(currentLoad) + "%" +
               " Peak:" + to_string(maxOutput) + " u/h";
    return s;
}

ostream& operator<<(ostream &os, const Machine &m) {
    os << "Machine: " << m.model
       << " | Load " << m.currentLoad << "%, Peak " << m.maxOutput << " u/h"
       << " | Count: " << m.count << endl;
    return os;
}