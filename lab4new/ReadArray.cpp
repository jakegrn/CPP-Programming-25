#include "ReadArray.h"
#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

ReadArray::ReadArray(const char* filename)
{
    //ifstream str(filename);
    f.open(filename);
    // ^^ This is redundant since ifstream already passes filename to ifstream constructor.
    if (!f)
    {
        cout << "Failed to open file." << endl;
        exit(1);
    }
    count = 0;
}

void ReadArray::inputArray()
{
    int n;
    //declared value with no initialised value, leading to errors
    while(f >> n)
    {
        array[count] = n;
        count++;
        //forgot to increment count
        //cout << n << endl;
        //Since we are printing full array in main
    }
    //while loop which assigns next file line value to n, checks if its valid and runs condition code
}
