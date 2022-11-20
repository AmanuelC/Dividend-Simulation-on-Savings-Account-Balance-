#include <iostream>
#include <iomanip>
#include <fstream>
#include "Person.cpp"
#include "Savings.cpp"


/**
 * Program that has the user input personal information
 * To open a SavingsAccount, and calculates their balance after
 * An inputted amount of months with an inputted dividend percent.
 * Uses the Person Class for personal information and the SavingsAccount
 * Class for banking information
 * BUG: While the program does validate zip code entries by making sure they
 * Are 5 numbers long, zip codes starting with 0 don't get accepted
 * BUG: graph.py is not plotting the data correctly when 2 or more simulations
 * are plotted together. Differing y values cause the y-axis values to fluctuate incorrectly
 */
//Using namespace
using namespace std;
//Declare functions for validated user input
string stringInput();
int intInput();
double doubleInput();
//Main
int main() {
    //Introduce the program to user
    cout << "Welcom to Amanuel Chase Banking, The best bank in America." << endl;
    cout << "First, some personal information" << endl;

    //Open file for writing simulation results to
    ofstream myFile;
    myFile.open ("simulations.txt");

    //Get personal information from user
    cout << "First Name: ";
    string firstName = stringInput();
    cout << "Last Name: ";
    string lastName = stringInput();
    cout << "Age: ";
    int age = intInput();
    cout << "Zip Code: ";
    int zipCode = intInput();
    while (to_string(zipCode).length() != 5) {
        cout << "Please enter a 5 digit Zip Code: ";
        zipCode = intInput();
    }

    //Create Person Object
    Person accountHolder;

    //Store inputted information into Person Object
    accountHolder.setFirstName(firstName);
    accountHolder.setLastName(lastName);
    accountHolder.setAge(age);
    accountHolder.setZipCode(zipCode);

    //Display inputted details back to user
    cout << accountHolder.fullDetails() << endl;

    //Write to simulations.txt user details
    myFile << accountHolder.fullDetails() << "\n";
    myFile << "\n";

    //Introduce Program
    cout << "Welcome to our dividend simulation" << endl;
    cout << "We add dividend amounts to your account monthly, with a monthly fee of $25.00" << endl;
    cout << "Please input account information, and we will calculate your balance for the next inputted months" << endl;

    //Create Savings Object to store inputted details
    Savings savingsAccount;

    //Set none varying details into Savings Object
    savingsAccount.setOwner(accountHolder);
    savingsAccount.setMonthlyFee(25);


    //Open file to write balances to for graphing in python
    ofstream pythonFile;
    string fileName = "pythonGraph.txt";
    pythonFile.open (fileName);

    //Set count equal to 1 to keep while loop going
    int count = 1;
    while(count == 1) {
        //Prompt user for bank balance
        cout << "Balance: ";
        double balance = doubleInput();
        //Set Balance of Savings Object to inputted value
        savingsAccount.setBalance(balance);

        //Write to simulations.txt the starting balance of simulation
        myFile << "Starting balance: " << fixed << setprecision(2) << savingsAccount.getBalance() << "\n";

        //Write starting balance to pythonFile for graphing
        pythonFile << fixed << setprecision(2) << savingsAccount.getBalance() << "\n";

        //Prompt user for dividend rate
        cout << "Dividend rate (.02, .04, .06): ";
        double dividend = doubleInput();
        //While inputted Dividend rate isn't one of the listed options, keep prompting user
        while (dividend != .02 && dividend != .04 && dividend != .06) {
            cout << "Please choose a dividend option of .02, .04, or .06: ";
            dividend = doubleInput();
        }
        //Set Dividend of Savings Object to inputted value
        savingsAccount.setDividend(dividend);

        //Write to simulations.txt dividend percent for simulation
        myFile << "Dividend percent: " << setprecision(2) << savingsAccount.getDividend() << '\n';


        //Prompt user for number of months to calculate
        cout << "Number of months to calculate: ";
        int numMonths = intInput();

        //Display Savings Balance for every month inputted
        //Start with starting balance
        cout << "Starting Balance: " << savingsAccount.getBalance() << endl;
        //Track how many years the person ages in simulation
        int yearsOlder = 0;
        for (int i = 1; i <= numMonths; i++) {
            //Add dividend credit to balance
            ++savingsAccount;
            //Subtract monthly fee
            --savingsAccount;
            //Display balance to user
            cout << "After month " << i << " you have $" << fixed << setprecision(2) << savingsAccount.getBalance() << endl;
            //Write balance to myFile
            myFile << "After month " << i << " you have $" << fixed << setprecision(2) << savingsAccount.getBalance() << "\n";
            //Write balance to pythonFile
            pythonFile << fixed << setprecision(2) << savingsAccount.getBalance() << "\n";
            //Every 12 months increase age and display age to user
            if (i % 12 == 0) {
                ++accountHolder;
                //Add 1 to yearsOlder
                yearsOlder = yearsOlder + 1;
                cout << "You are now " << accountHolder.getAge() << " years old" << endl;
                myFile << "You are now " << setprecision(2) << accountHolder.getAge() << " years old \n";
            }

        }

        //Set break point for current simulation in pythoFile
        //Used to detect when the current simulation data set ends
        pythonFile << '-' << "\n";

        //Close myFile
        myFile.close();

        //Prompt user to make another calculation or quit program
        cout << "Would you like to make another calculation(Y/N): ";
        string choice = stringInput();
        //While inputted choice isn't Y or N, keep prompting user
        //If 'N', then count set to 0 and while loop ends, graph.py called through command line to graph simulation data
        //If 'Y', then count stays the same and Person object age set back to original value
        while (choice != "Y" && choice != "N") {
            cout << "Please Enter Y or N: ";
            choice = stringInput();
        }

        if (choice == "N") {
            //While loop ends, program ends
            count = 0;
            //Close pythonFile for graph.py to access data
            pythonFile.close();
            //Graph data
            string python = "py";
            string command = python + " ../graph.py " + fileName;
            system(command.c_str());
        } else {
            //Reset age for next simulation
            accountHolder.setAge(accountHolder.getAge() - yearsOlder);
            //Separate new simulation details from last simulation in simulations.txt
            myFile << "\n";
        }

    }


    return 0;
};

/**
 * Function that takes in string user input and validates it
 * @return stringInput The string inputted
 */
string stringInput() {
    string stringInput;
    while (!(cin >> stringInput)) {
        cout << "Please enter a valid entry: ";
        cin.clear();
        string stringStr;
        getline(cin, stringStr);
    }
    return stringInput;
}

/**
 * Function that takes in integer user input and validates it
 * @return intInput The integer inputted
 */
int intInput() {
    int intInput;
    while (!(cin >> intInput && intInput > 0)) {
        cout << "Please enter a valid entry: ";
        cin.clear();
        string intStr;
        getline(cin, intStr);
    }
    return intInput;
}

/**
 * Function that takes in double user input and validates it
 * @return doubleInput The integer inputted
 */
double doubleInput() {
    double doubleInput;
    while (!(cin >> doubleInput && doubleInput > 0)) {
        cout << "Please enter a valid entry: ";
        cin.clear();
        string doubleStr;
        getline(cin, doubleStr);
    }
    return doubleInput;
}

