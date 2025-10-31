#include "Student.h"
#include <algorithm>

Student::Student(int regNo, string name, int year) {
    this->regNo = regNo;
    this->name = name;
    this->year = year;
}

// I guess we need to declare constant so we don't overload it again?

bool Student::operator<(const Student &s) const {
    return this->regNo < s.regNo;
};

ostream & operator<<(ostream &str, const Student &s) {
    str << "Student Reg No " << s.regNo
        << "Student Name " << s.name
        << "Student Year" << s.year << endl;
    return str;
}