/* 
 * File:   customerUtility.cpp
 * Author: Hai Le
 * 
 * Created on April 22, 2018, 2:24 PM
 */

#include "customerUtilities.h"

using namespace std;

vector<int> searchLastName(vector<Customer *>& searchList, string name) {
    vector<int> foundList;

    // if match is found, add the index of that record to the vector
    for (int i = 0; i < searchList.size(); i++) {
        if (searchList[i]->getLname() == name)
            foundList.push_back(i);
    }

    return foundList;
}

void updateRecordFile(vector<Customer *>& list, int size) {
    ofstream outfile;

    outfile.open("customer___data.txt", ios_base::app);
    
    // append only newly added records
    for (int i = size + 1; i < list.size(); i++) {
        outfile << list[i]->getFname() << " " << list[i]->getLname() << " " << list[i]->getAddress() << endl;
    }
}

