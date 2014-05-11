/*//////////////////////////////////////////////////////////////
Program: carrental.cpp
Author: Robert Payne
Date: 3/9/2012
Lecture/Lab Section: ITCS 1212-001-L15
Purpose: User inputs the total number of miles driven on the rental
        car then the type of rental car. The program calculates
        the total due and prints it in the console output.
///////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

int main()
{
    double mileageDriven; //the mileage driven during the rental
    char carType; //the type of car rented
    double totalDue; //total due for the car rental

    //constants
    double const SUB_COMPACT = .25; //sub-compact rate
    double const SEDAN = .50;   //sedan rate
    double const SUV = .75; //SUV rate
    double const VAN = 1.00; //VAN rate

    //user inputs
    cout << "Enter the milage driven on the rental: \a";
    cin >> mileageDriven;
    cout << "Enter the type of car rented: sub-(C)ompact, se(D)an, (S)uv, (V)an : \a";
    cin >> carType;
    cout << endl << endl;

    //computations; each case checks to see if mileage is
    //over 100 and then computes accordingly
    switch (carType)
    {
        case 'c':
        case 'C':   if (mileageDriven > 100)
                        totalDue = 100 * SUB_COMPACT + (mileageDriven - 100) * (SUB_COMPACT + .1);
                    else
                        totalDue = mileageDriven * SUB_COMPACT;
        break;
        case 'd':
        case 'D':   if (mileageDriven > 100)
                        totalDue = 100 * SEDAN + (mileageDriven - 100) * (SEDAN + .1);
                    else
                        totalDue = mileageDriven * SEDAN;
        break;
        case 's':
        case 'S':   if (mileageDriven > 100)
                        totalDue = 100 * SUV + (mileageDriven - 100) * (SUV + .1);
                    else
                        totalDue = mileageDriven * SUV;
        break;
        case 'v':
        case 'V':   if (mileageDriven > 100)
                        totalDue = 100 * VAN + (mileageDriven - 100) * (VAN + .1);
                    else
                        totalDue = mileageDriven * VAN;
        break;
        default:
            cout<< "INVALID CAR TYPE";
            return 0;
      }

    //total output
    cout<< "Total Due: $" <<totalDue;
    return 0;
}
