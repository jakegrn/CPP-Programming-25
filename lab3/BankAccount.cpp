#include <iostream> // C++ standard library similar to stdio.h
#include <string>
#include <windows.h>

using namespace std;

// Here we are initialising class BankAccount and assigning all necessary variables

class BankAccount
{
private:
    string accountHolderName;
    int accountNo;
    double balance;
public:

    // Important to instantiate constructor and destructor

    BankAccount(string accountHolderName, int accountNo);
    ~BankAccount();
    void deposit(double amount);
    bool withdraw(double amount);
    void displayAccountInfo();
};

// This is the constructor

BankAccount::BankAccount(string accountHolderName, int accountNo)
{
    this->accountHolderName = accountHolderName;
    this->accountNo = accountNo;
    this->balance = 0.0;
}

// This is the deconstructor
BankAccount::~BankAccount()
{
}

// Deposit method that adds funds to balance

void BankAccount::deposit(double amount)
{
    balance = balance + amount; 
}

bool BankAccount::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance = balance - amount;
        return true;
    }
    return false;
}

void BankAccount::displayAccountInfo()
{
    cout << "Account Holder Name - " << accountHolderName << "\nAccount Number - " << accountNo << "\nCurrent Balance - " << balance << endl;
}

int main(int argc, char const *argv[])
{
    BankAccount b1("Jake Green", 10304050);
    b1.deposit(123456789.0);
    b1.withdraw(3609070.42);
    b1.displayAccountInfo();
    return 0;
}
