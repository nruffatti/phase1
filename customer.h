/* File: customer.h
 * Author: Brandon Youngquist
 *
 * Created on April 22, 2018
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
    public:
        Customer();
        Customer(string, string, string, string, string, string);

        string getFname();
        string getLname();
        string getStreet();
        string getCity();
        string getState();
        string getZip();

        void setFname(string);
        void setLname(string);
        void setStreet(string);
        void setCity(string);
        void setState(string);
        void setZip(string);

    private:
        string fname, lname, street, city, state, zip;
};

#endif /* CUSTOMER_H */


