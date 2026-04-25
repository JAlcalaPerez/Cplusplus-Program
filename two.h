#include <iostream>
#include <iomanip>

class BankingApp //BankingApp class is declared

{
private: //variables used in private class are declared
	double m_initialInvestment; 
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_years;

public: //constructors are set to 0 in public class
	BankingApp() {
		m_initialInvestment = 0;
		m_monthlyDeposit = 0;
		m_annualInterest = 0;
		m_years = 0;
	}
	//using setter functions because the following variables cannot be accessed directly because they belong to private class
	void setInitialInvestment(double initialAmount) {
		m_initialInvestment = initialAmount;
	}
	void setMonthlyDeposit(double deposit) {
		m_monthlyDeposit = deposit;
	}
	void setAnnualInterest(double rate) {
		m_annualInterest = rate;
	}
	void setYears(int y) {
		m_years = y;
	}
	 //monthly interest rate is calculated
	double calculateMonthlyInterestRate(double openingAmount, double depositedAmount) {
		return (openingAmount + depositedAmount) * ((m_annualInterest / 100) / 12);
	}

	//display function so all the labels do not have to manually retyped every time
	void display() {
		std::cout << "Initial investment amount: " << std::endl;

		if (m_initialInvestment != 0) {
			std::cout << m_initialInvestment << std::endl;
		}

		std::cout << "Monthly deposit: " << std::endl;

		if (m_monthlyDeposit != 0) {
			std::cout << m_monthlyDeposit << std::endl;
		}

		std::cout << "Annual Interest rate: " << std::endl;

		if (m_annualInterest != 0) {
			std::cout << m_annualInterest << std::endl;
		}

		std::cout << "Number of years: " << std::endl;

		if (m_years != 0) {
			std::cout << m_years << std::endl;
		}
	}

	//function for report 1 which contains no monthly deposit
	void displayHeaderWithNoDeposits() {
		std::cout << "Balance and Interest without additional deposits" << std::endl;
		std::cout << std::string(65, '*') << std::endl;
		std::cout << "Year" << std::setw(25) << "Year end balance" << std::setw(30) << "Year end interest earned" << std::endl;
		std::cout << std::string(65, '*') << std::endl;
	}

	//functino for report 2 which does contain monthly deposits
	void displayHeaderWithMonthlyDeposits() {
		std::cout << "Balance and Interest with additional monthly desposits" << std::endl;
		std::cout << std::string(65, '*') << std::endl;
		std::cout << "Year" << std::setw(25) << "Year end balance" << std::setw(30) << "Year end interest earned" << std::endl;
		std::cout << std::string(65, '*') << std::endl;
	}

	//function to prompt user to enter initial investment amount
	void promptInitialInvestment(){
		double t_input;

		std::cout << "Please enter initial investment account: " << std::endl;
		std::cin >> t_input;
		std::cout << std::fixed << std::setprecision(2);
		m_initialInvestment = t_input;
}
	//function to prompt user to enter monthly deposit amount
	void promptMonthlyDeposit() {
		double t_input;

		std::cout << "Please enter monthly deposit amount: " << std::endl;
		std::cin >> t_input;
		m_monthlyDeposit = t_input;
		std::cout << std::endl;
	}

	//function to prompt user to enter annual interest rate
	void promptAnnualInterestRate() {
		double t_input;

		std::cout << "Please enter annual interest rate: " << std::endl;
		std::cin >> t_input;
		m_annualInterest= t_input;
	}

	//function to prompt user to enter years they want amounts to be calculated for
	void promptEnterYears() {
		double t_yearsInput;

		std::cout << "Please enter years: " << std::endl;
		std::cin >> t_yearsInput;
		m_years = t_yearsInput;
		
	}

	//getter functions because these variables are declared in the private class
	double getInitialInvestment() {
		return m_initialInvestment;
	}
	double getYears() {
		return m_years;
	}
	double getMonthlyDeposit() {
		return m_monthlyDeposit;
	}
};