#include "ReadArray.h"
#include <cstdlib>

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
            throw;
        }
    }
    catch
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
        try
        {
            cout << n << endl;
        }
        catch //handling when loop has reached end of array
        {
            f.close();
        }
    }
}