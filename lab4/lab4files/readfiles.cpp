// Include necessary libraries for input and output operations
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{   
    // Define the name of the file to be read
    const char *filename = "Data.txt";

    // Create an input file stream object and open the file
    ifstream f(filename);

    // Check if the file was opened successfully
    if(!f)
    {
        cout << "Sorry, cannot open file: " << filename << endl;
        return 0; // Exit the program if the file cannot be opened
    }

    string n; // Variable to store data read from the file

    bool reading = true; // A flag to control the reading loop

    // Continue reading from the file until the end is reached
    while(reading)
    {
        // Attempt to read a string from the file
        f >> n;

        // Check if the end-of-file (EOF) has been reached
        if(!f.eof())
        {
            cout << n << endl; // Output the read string
        }
        else
        {
            reading = false; // Set the flag to end the reading loop
            f.close(); // Close the file
        }
    }

    return 0; // Exit the program
}
