#include "machine.h"

// Main function: Create and manipulate Machine objects
int main() {
    // Create two Machine objects with initial values
    Machine m1("Concave Phased Array UT0037", 35, 2, "Ultrasound Transducer",
               true, 2025, "NDT-KITS", 1200);
    Machine m2("Copner GRAPE S1", 20, 3, "Bioprinter",
               false, 2024, "Copner", 800);

    m1.operate(3.5);           // Simulate running the first machine
    m1.updateMaxOutput(1400);  // Update peak output for the first machine

    m2.updateMaxOutput(900);

    // Print details for the first machine
    cout << "Machine: " << m1.getModel() << " peak " << m1.getMaxOutput()
         << " u/h. Number of Machine objects: " << m1.getCount() << endl;

    if (m1 > m2) {
        cout << "First machine has higher peak output than the second." << endl;
    }
    if (m1 < m2) {
        cout << "First machine has lower peak output than the second." << endl;
    }

    Machine m3(m1);         // Copy-construct
    m3 = m1 + m2;           // Combine loads, keep best peak

    cout << m3;             // Friend <<

    string s = string(m3);
    //OR
    // string s = m3;
    // OR
    // string s = static_cast<string>(m3);

    cout << s;

    return 0;
}
