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
	string data[125][6];

    getData(data);
    rm_nonNum(data, 5);
    rm_spaces(data, 4);
    rm_spaces(data, 3, 1);

	vector<string> options;
	options.push_back("(1) Add a customer");

    cout << "What would you like to do?\n";
	for(int i = 0; i < (int)options.size(); i++) {
		cout << options.at(i) << endl;
	}
	cout << "\nEnter an above number to continue: ";

	int choice;
	cin >> choice;

	vector<Customer *> customerList;
	switch(choice) {
		case 1:
			string fname;
			string lname;
			string address;

			cout << "\nNew Customer\n============" << endl;

			cout << "Enter first name: ";
			cin >> fname;

			cout << "Enter last name: ";
			cin >> lname;

			cout << "Enter full address (Street, City, State, Zip): ";
			cin >> address;

			Customer * newCustomer = new Customer(fname, lname, address);
			customerList.push_back(newCustomer);
	}

    return 0;
}
