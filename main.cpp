/*
 * File:   main.cpp
 * Author: Nathan R, Brandon Youngquist
 *
 * Created on April 12, 2018, 9:45 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "part1.h"
#include "customer.h"

using namespace std;

int getChoice() {
	int choice;

	// vector is used to store the options that the user can choose
	vector<string> options;
	options.push_back("(1) Add a customer");
	options.push_back("(2) Search for a customer by last name");


	cout << "==========================\nWhat would you like to do?\n";
	// for loop iterates through the available options that the user can choose
	for(int i = 0; i < (int)options.size(); i++) {
		cout << options.at(i) << endl;
	}
	cout << "\nEnter an above number to continue (0 to exit): ";
	cin >> choice;

	return choice;
}

int main(int argc, char** argv) {
	// variables that will be used in multiple places or multiple times
	Customer * newCustomer;
	vector<Customer *> customerList;
	int choice;

	// read customer___data.txt and parse the data
	string data[125][6];
	getData(data);
	rm_nonNum(data, 5);
	rm_spaces(data, 4);
	rm_spaces(data, 3, 1);

	// translate the data into Customer objects and push them into the customerList vector
	for(int i = 0; i < 125; i++) {
		newCustomer = new Customer(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5]);
		customerList.push_back(newCustomer);
	}

	choice = getChoice();

	while(choice != 0) {
		/* Switch is used to determine what option the user chooses
		 * case 1 - user is prompted to add new customer
		 * case 2 - search for customer by last name
		 */
		string fname, lname, street, city, state, zip, fullName;
		switch(choice) {
			case 1:
			cout << "\nNew Customer\n============" << endl;

			cout << "Enter first name: ";
			cin >> fname;

			cout << "Enter last name: ";
			cin >> lname;

			cout << "Enter street address: ";
			cin.ignore();
			getline(cin, street);

			cout << "Enter city name: ";
			cin >> city;

			cout << "Enter state name: ";
			cin >> state;

			cout << "Enter zipcode: ";
			cin >> zip;

			newCustomer = new Customer(fname, lname, street, city, state, zip);
			customerList.push_back(newCustomer);

			fullName = newCustomer->getFname() + " " + newCustomer->getLname();

			cout << "\nNew Customer, " << fullName << " was added to the list.\n\n";
			break;

			case 2:
			break;

			default:
			cout << "\nPlease enter a valid number.\n\n";
			break;
		}

		choice = getChoice();
	}


	return 0;
}
