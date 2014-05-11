/*//////////////////////////////////////////////////////////////
Program: bankstatement.cpp
Author: Robert Payne
Date: 3/9/2012
Lecture/Lab Section: ITCS 1212-001-L15
Purpose: Receives the customers account number, account type,
        minimum balance needed, and the current balance. The
        program then calculates how much interest is earned
        and adds that to the balance. The program checks to
        see if the customer has minimum funds available.
        The program will display a message if the account is
        below or above the minimum balance and display the
        new balance as well as the rest of the account
        information.
///////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

int main()
{
    int accountNumber;  //user input; account number
    char accountType;   //user input; savings or checking
    double accountBalance; //user input; balance in the account
    double minimumBalance; //user input; minimum balance required
    int const SAVINGS_FEE = 10;  //fee for below minimum balance
                                        //on savings
    int const CHECKING_FEE = 25; //fee for belowminimum balance
                                        //on checking
    int const SAVINGS_SERVICE_CHARGE = 10; //fee for being under minimum
                                            //balance
    int const CHECKING_SERVICE_CHARGE = 25; //fee for being under minimum
                                             //balance

    double const SAVINGS_INTEREST = 1.03; //interest for savings accounts
    double const HALF_CHECKING_INTEREST = 1.02; //interest for checking
                            //up to 5000 dollars over the minimum balance
    double const CHECKING_INTEREST = 1.04; //inerest for checking 5000
                            //dollars or more over the minimum

    //Prompting for user input
    cout << "Enter the account number: \a";
    cin >> accountNumber;
    cout << "Enter the accout type (S)avings or (C)hecking: \a";
    cin >> accountType;
    cout << "Enter the account balance: $\a";
    cin >> accountBalance;
    cout << "Enter the minimum balance required for this account: $\a";
    cin >> minimumBalance;
    cout << endl << endl <<endl;
    switch(accountType) //checks account type then routes to correct computation for interest
    {
        case 's':
        case 'S':
                    if(accountBalance < minimumBalance)     //outputs below minimum balance if not enough funds
                    {
                        accountBalance -= SAVINGS_SERVICE_CHARGE;
                        cout << "       ***Your account is below the minimum balance required***\n\a";
                    }
                    else    //calculates interest
                    {
                        accountBalance *= SAVINGS_INTEREST;
                        cout << "       ***Your account earned interest***\a\n";
                    }
        break;
        case 'c':
        case 'C':   if(accountBalance < minimumBalance)    //outputs below minimum if not enough funds
                    {
                        accountBalance -= CHECKING_SERVICE_CHARGE;
                        cout << "       ***Your account is below the minimum balance required***\a\n";
                    }
                    else    //calculates interest
                    {
                         if((accountBalance- minimumBalance) > 5000)
                            accountBalance *= CHECKING_INTEREST;
                         else
                            accountBalance *= HALF_CHECKING_INTEREST;

                         cout << "      ***Your account earned interest***\a\n";
                    }
        break;
        default:    //executes when incorrect input for account type occurs
                    cout << "INVALID ACCOUNT TYPE";
                    return 0; //ends the program
    }

    //outputs the account statement
    cout << "************************************************" << endl;
    cout << "*Account Number: \t" << accountNumber << endl;
    cout << "*Account Type: \t\t";
    if (accountType == 'c' || accountType == 'C')
        cout << "Checking" << endl;
    else
        cout << "Savings" << endl;
    cout << "*Account Balance: \t$" << accountBalance << endl;
    cout << "************************************************";

    return 0;
}
