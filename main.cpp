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


int main(int argc, char** argv) {
	vector<Customer *> customerList;
	Customer * newCustomer;
	string data[126][6];

    getData(data);
    rm_nonNum(data, 5);
    rm_spaces(data, 4);
    rm_spaces(data, 3, 1);

	for(int i = 0; i < (int)sizeof(data); i++) {
		newCustomer = new Customer(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5]);
		customerList.push_back(newCustomer);
	}

	vector<string> options;
	options.push_back("(1) Add a customer");

    cout << "What would you like to do?\n";
	for(int i = 0; i < (int)options.size(); i++) {
		cout << options.at(i) << endl;
	}
	cout << "\nEnter an above number to continue: ";

	int choice;
	cin >> choice;

	switch(choice) {
		case 1:
			string fname, lname, street, city, state, zip;

			cout << "\nNew Customer\n============" << endl;

			cout << "Enter first name: ";
			cin >> fname;

			cout << "Enter last name: ";
			cin >> lname;

			cout << "Enter street address: ";
			cin >> street;

			cout << "Enter city name: ";
			cin >> city;

			cout << "Enter state name: ";
			cin >> state;

			cout << "Enter zipcode: ";
			cin >> zip;

			newCustomer = new Customer(fname, lname, street, city, state, zip);
			customerList.push_back(newCustomer);
	}

    return 0;
}
