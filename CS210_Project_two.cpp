// Josielyn Alcala-Perez
// CS-210
// Module 5: Project Two
// April 12, 2026



#include <iostream>
#include "two.h"
#include <iomanip>
using namespace std;



int main() {
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') { //while user choses y (yes) loop will run
		BankingApp app; //object created from banking app class
		double t_input; //variables declared
		int t_yearsInput;


		app.display(); //calls display function that belongs to app object

		cout << endl;

		app.promptInitialInvestment(); //calls promptInitialInvestment function that belongs to app object

		cout << endl;

		app.display();

		cout << endl;

		app.promptMonthlyDeposit(); //calls promptMonthlyDeposit function that belongs to app object

		app.display();

		cout << endl;

		app.promptAnnualInterestRate(); //calls promptAnnualInterestRate function that belongs to app object

		cout << endl;

		app.display();

		cout << endl;

		app.promptEnterYears(); // calls promptEnterYears function that belongs to app object

		cout << endl;

		//report with no additional deposits

		app.displayHeaderWithNoDeposits(); //calls this function from h file

		double balance = app.getInitialInvestment(); // sets balance to what the user has entered as the initial investment

		for (int year = 1; year <= app.getYears(); year++) { //loop runs once per year for the amount of years entered by user
			double yearlyInterest = 0; //interests resets at the beginning of each year to calculate interest for that specific year

			for (int month = 1; month <= 12; month++) { //runs loop once per month
				double interest = app.calculateMonthlyInterestRate(balance, 0); //calls function with no monthly deposit
				balance = balance + interest; //interests is adding to total balance
				yearlyInterest = yearlyInterest + interest; //adds interest to yearly total interest
			}
			cout << year << setw(25) << balance << setw(30) << yearlyInterest << endl;
			cout << endl;
		}

		//report with monthly additional deposits
		app.displayHeaderWithMonthlyDeposits(); //calls this function from h file

		double balanceWithDeposits = app.getInitialInvestment();

		for (int year = 1; year <= app.getYears(); year++) { //loop runs once per year for the amount of years entered by user
			double yearlyInterest = 0; //interests resets at the beginning of each year to calculate interest for that specific year

			for (int month = 1; month <= 12; month++) { //runs loop once per month
				double interest = app.calculateMonthlyInterestRate(balance, app.getMonthlyDeposit()); //calls function with monthly deposit
				balance = balance + interest + app.getMonthlyDeposit(); //interests is adding to total balance
				yearlyInterest = yearlyInterest + interest; //adds interest to yearly total interest
			}
			cout << year << setw(25) << balance << setw(30) << yearlyInterest << endl;
			cout << endl;
		}
		cout << "Press y to enter a different amount or n to exit program" << endl; //prompts user to enter choice to enter different amount
		cin >> choice; //user enters choice
		cout << endl;
	}
	return 0;
	
}

