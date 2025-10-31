#ifndef _STUDENT_H_
#define _STUDENT_H_

using namespace std;
#include <iostream>
#include <string>

class Student
{   private:
        string name;
        int regNumber, year;
    public:
        Student(int regNo, string name, int year);

        // operator methods instantiate operators for a class. I don't know why we need to do this but it's needed I guess. This is operator overloading
        // for example this operator method, we are comparing to another object belonging to Student, so it follows nicely when we have s1 < s2.

        bool operator<(const Student &s) const;

        // what is friend? why are we using ostream and &?
        friend ostream & operator<<(ostream &str, const Student &s);
        int getYear() const { return year; }
        int getRegNumber() const { return regNumber;}
};

#endif