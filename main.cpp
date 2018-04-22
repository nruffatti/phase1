/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Nathan R
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

/*
 *
 */
int main(int argc, char** argv) {
	vector<string> options;
	options.push_back("(1) Add a customer");

    cout << "What would you like to do?\n";
	for(int i = 0; i < (int)options.size() - 1; i++) {
		cout << options.at(i) << endl;
	}
	cout << "\n\nEnter an above number to continue: ";

	int choice;
	cin >> choice;

	vector<Customer *> customerList;
	switch(choice) {
		case 1:
			string fname;
			string lname;
			string address;

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
