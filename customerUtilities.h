/* 
 * File:   customerUtility.h
 * Author: Hai Le
 *
 * Created on April 22, 2018, 2:24 PM
 */

#ifndef CUSTOMERUTILITY_H
#define CUSTOMERUTILITY_H

#include <vector>
#include <fstream>
#include "customer.h"


using namespace std;

vector<int> searchLastName(vector<Customer *>&, string);
void updateRecordFile(vector<Customer *>&, int);


#endif /* CUSTOMERUTILITY_H */

