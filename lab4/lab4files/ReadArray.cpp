#include "ReadArray.h"
#include <cstdlib>

using namespace std;

ReadArray::ReadArray(const char* filename)
{
    try
    {
        f.open(filename);
        if (f)
        {
            cout << "file has successfully been opened" << endl;
            count = 0;
        }
        else
        {
            throw 505;
        }
    }
    catch(int errorCode)
    {
        cout << "Error occured, invalid file name/type" << endl;
        exit(1);
    }
}

void ReadArray::inputArray()
{
    int n;
    while (f)
    //Im assuming loop will keep running while file is open
    {
        array[count++] = n;
        cout << n << endl;
    }
    f.close();
}