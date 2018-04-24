/*
 * File:   main.cpp
 * Author: Nathan R, Brandon Youngquist, Hai Le
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
#include "customerUtilities.h"

using namespace std;

int main(int argc, char** argv) {
    // variables that will be used in multiple places or multiple times
    Customer * newCustomer;
    vector<Customer *> customerList;
    vector<int> foundList; // to store the index of found records with duplicate name
    int choice;
    int size; // to keep track of # of existing records
    bool exit = false;

    // read customer___data.txt and parse the data
    vector<vector < string>> data;

    string s;
    cout << "Parse Data? (y/n)" << endl;
    cin >> s;
    
    //user edits bad data
    if (s.compare("y") == 0) {
        data = getData(data);
        data = rm_spaces(data, 4);
        data = rm_spaces(data, 3);
        data = rm_nonNum(data, 5);
        cout << "Parsing through data..." << endl;
        bad_data(data);
        cout << "Possible bad data saved to badData.csv file" << endl;
        cout << "Fix the bad data now and resave data. Press any key, then enter to continue" << endl;
        cout << ("note: type 'delete' into an element to delete that entire row.") << endl;
        cin >> s;
        data = fix_bad(data);
        save(data, "fixed_data");
    } else { //uses last saved edited badData file
        data = getData(data);
        data = rm_spaces(data, 4);
        data = rm_spaces(data, 3);
        data = rm_nonNum(data, 5);
        data = fix_bad(data);
        save(data, "fixed_data");
    }
    cout << "\n\n\n\n\n";

    // translate the data into Customer objects and push them into the customerList vector
    for (int i = 0; i < data.size(); i++) {
        newCustomer = new Customer(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5]);
        customerList.push_back(newCustomer);
    }

    size = customerList.size(); // to keep the track of # of existing records
    // vector is used to store the options that the user can choose
    vector<string> options;
    options.push_back("(1) Add a customer");
    options.push_back("(2) Search for a customer by last name");
    options.push_back("(3) Exit");



    cout << "What would you like to do?\n";
    // for loop iterates through the available options that the user can choose
    for (int i = 0; i < (int) options.size(); i++) {
        cout << options.at(i) << endl;
    }

    // to store the user input
    string fname, lname, street, city, state, zip;

    while (!exit) {
        cout << "\nEnter an above number to continue: ";
        cin >> choice;

        /* Switch is used to determine what option the user chooses
         * case 1 - user is prompted to add new customer
         * case 2 - user is prompted to look up a customer by last name
         * case 3 - exit
         */

        switch (choice) {
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
                break;

            case 2:
                cout << "\nEnter last name to search: ";
                cin >> lname;
                foundList = searchLastName(customerList, lname);

                //multiple last names
                if (foundList.size() > 1) {
                    for (int i = 0; i < foundList.size(); i++) {
                        cout << (i + 1) << ". " << customerList[foundList[i]]->getFname() << " " << customerList[foundList[i]]->getLname() << endl;
                    }
                    cout << "Enter a number to choose a record: " << endl;
                    cin >> choice;
                    choice--;
                    cout << "\n" << customerList[foundList[choice]]->getFname() << " "
                            << customerList[foundList[choice]]->getLname() << ", "
                            << customerList[foundList[choice]]->getAddress() << endl;
                }//one last name found
                else if (foundList.size() == 1) {
                    cout << "\n" << customerList[foundList[0]]->getFname() << " "
                            << customerList[foundList[0]]->getLname() << ", "
                            << customerList[foundList[0]]->getAddress() << endl;
                } else
                    cout << "No match was found. Try again!" << endl;
                break;
            case 3:
                updateRecordFile(customerList, size);
                exit = true;
                break;
            default:
                cout << "Not valid input. Try again!" << endl;
                
                //fix infinite loop error for invalid inputs
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
    return 0;
}