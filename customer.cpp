/* File: customer.cpp
 * Author: Brandon Youngquist
 *
 * Created on April 22, 2018
 */
#include "customer.h"

using namespace std;

Customer::Customer(string fname, string lname, string address) {
	this->fname = fname;
	this->lname = lname;
	this->address = address;
}

string Customer::getFname() {
	return fname;
}

string Customer::getLname() {
	return lname;
}

string Customer::getAddress() {
	return address;
}

void Customer::setFname(string fname) {
	this->fname = fname;
}

void Customer::setLname(string lname) {
	this->lname = lname;
}

void Customer::setAddress(string address) {
	this->address = address;
}
