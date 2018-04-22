/* File: customer.cpp
 * Author: Brandon Youngquist
 *
 * Created on April 22, 2018
 */
#include <string>
using namespace std;

class Customer {
	private:
		string fname, lname, address;
	public:
		Customer(string fname, string lname, string address) {
			this->fname = fname;
			this->lname = lname;
			this->address = address;
		}

		string getFname() {
			return fname;
		}

		string getLname() {
			return lname;
		}

		string getAddress() {
			return address;
		}

		void setFname(string fname) {
			this->fname = fname;
		}

		void setLname(string lname) {
			this->lname = lname;
		}

		void setAddress(string address) {
			this->address = address;
		}
};
