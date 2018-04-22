#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
	public:
		Customer();
		Customer(string, string, string);

		string getFname();
		string getLname();
		string getAddress();

		void setFname(string);
		void setLname(string);
		void setAddress(string);
	private:
		string fname, lname, address;
};

#endif
