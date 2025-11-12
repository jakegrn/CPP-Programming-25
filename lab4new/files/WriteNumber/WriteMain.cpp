/*
  This is a little test file. You don't needt to use it unless you wish to
  test the functions in WriteNumber.
*/

using namespace std;
#include "WriteNumber.h"

int main(int argc, char *argv[])
{   WriteNumber wn("file.dat");  // call the constructor.
    /* wn.writeString("a number ");
    wn.writeInt(33);
    wn.writeInt(-4);
    wn.writeDouble(44.5); */

    ReadArray inputFile = ReadArray("/home/jake/Downloads/CPP-Programming-25/lab4new/Data.dat");
    inputFile.inputArray();
    int arrayCount = inputFile.count;
    wn.writeString("The average is: ");
    wn.writeDouble(Stats::average(inputFile.array, arrayCount));
    wn.writeString("The sum is: ");
    wn.writeInt(Stats::sum(inputFile.array, inputFile.count));
    wn.writeString("The largest is: ");
    wn.writeInt(Stats::largest(inputFile.array, inputFile.count));
    wn.close();
    return 0; // normal exit
}
