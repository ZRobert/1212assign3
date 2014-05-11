/*//////////////////////////////////////////////////////////////
Program: carpurchase.cpp
Author: Robert Payne
Date: 3/9/2012
Lecture/Lab Section: ITCS 1212-001-L15
Purpose: User inputs what kind of package they want for their car
    and then inputs their annual income, down payment, length of
    the loan (yrs) and the annual interest rate. The program
    calculates the price of the car and determines what their
    monthly payment will be and if they are eligible for the loan.
    Then it displays package price, and the loan information.
///////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double annualIncome;    //annual income of user
    char carPackage;        //car package selection
    double carPrice = 0;    //car price w/ package selection
    double downPayment;     //how much the user is putting down for the car
    double lifeLoan;        //how long the loan is for
    double annualInterestRate;  //annual interest rate offered by the bank
    double monthlyInterestRate; //calculated monthly interest rate
    double monthsLoan;      //how long the loan is for in months
    double monthlyPayment;  //the monthly car payment

    //output explaining to the user the different car packages
    cout << "___________________________________________________________\n";
    cout << "| The base price for the Honda Civic is $17,800.          |\n";
    cout << "| The different packages available are:                   |\n";
    cout << "|                                                         |\n";
    cout << "|(P) auto transmission, power windows and locks,          |\n";
    cout << "| stereo sound system. Cost + $1200                       |\n";
    cout << "|                                                         |\n";
    cout << "|(L) includes all above, plus MP3 player, security        |\n";
    cout << "| alarm, cruise control. Cost + $1800                     |\n";
    cout << "|                                                         |\n";
    cout << "|(D) includes all above, plus deluxe detailing, pin       |\n";
    cout << "| stripes, leather seats, wind bar. Cost + $2300          |\n";
    cout << "|                                                         |\n";
    cout << "|(S) includes all above, plus seat heaters, Bose          |\n";
    cout << "| speakers, OnStar, steering wheel control of music       |\n";
    cout << "| system, chrome rims. Cost + $2800                       |\n";
    cout << "|                                                         |\n";
    cout << "|(B) for just the base model.                             |\n";
    cout << "|                                                         |\n";
    cout << "\\=========================================================\n";

    //prompts the user for their package choice
    cout << "\n\n__________________________________________________________\n";
    cout << "| Which car package would you like: ";
    cin >> carPackage;

    //adds up the price based on the package choice
    switch(carPackage)
    {
        default: cout << "INVALID SELECTION";
                  return 0;
        case's':
        case'S': carPrice = 500;
        case'd':
        case'D': carPrice = carPrice + 500;
        case'l':
        case'L': carPrice = carPrice + 600;
        case'p':
        case'P': carPrice = carPrice + 1200;
        case'b':
        case'B': carPrice = carPrice + 17800;
    }

    //tells the user what the cost of the package choice they made is
    //then asks for more information to set up for the loan calculations
    cout << "| Package cost: $" <<carPrice;
    cout << "\n| How much for the down payment on the car: $";
    cin >> downPayment;
    cout << "| What is the annual interest rate of the loan (%): ";
    cin >> annualInterestRate;
    cout << "| How many years is the car loan for: ";
    cin >> lifeLoan;
    cout << "| What is your annual income: $";
    cin >> annualIncome;
    cout << "\\=========================================================\n";

    //compute the monthly interest based on the inputs
    monthsLoan = lifeLoan * 12; //number of months calculated
    monthlyInterestRate = annualInterestRate / (12* 100); //monthly interest calculated
    carPrice -= downPayment;    //principle car price minus the down payment
    //monthly payment calculation
    monthlyPayment = carPrice * (monthlyInterestRate / (1 -(pow((1+ monthlyInterestRate), -monthsLoan))));

    //checks to see if the user is ineligible for the loan
    if(((annualIncome / 12)/4)< monthlyPayment)
    {
        cout << "\n\n\a ***You are ineligible for the loan***";
        return 0; //ends the program
    }
    //if eligible, outputs the car loan information
    else
    {
        cout << "\n__________________________________________________________\n";
        cout << "| \n";
        cout << "| Total Car Price is: $ " << carPrice + downPayment <<endl;
        cout << "| \n";
        cout << "| Loan length in years: " << lifeLoan << " yr(s) \n";
        cout << "| \n";
        cout << "| Annual Interest Rate: " << annualInterestRate << "%\n";
        cout << "| \n";
        cout << "| Down Payment: $" <<downPayment << endl;
        cout << "| \n";
        cout << "| Principle: $" << carPrice << endl;
        cout << "| \n";
        cout << "| Monthly Payment: $" << monthlyPayment << endl;
        cout << "| \n";
        cout << "| --------------------------------------------------------\n";
        cout << "| \n";
        cout << "| Congratulations on your new car! \n";
        cout << "| \n";
        cout << "\\=========================================================";
    }

    return 0;
}
