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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string data[125][6];
    getData(data);
    rm_spaces(data, 4);
    rm_spaces(data, 3);
    rm_nonNum(data, 5);
    bad_data(data);
    fix_bad(data);
    save(data, "fixed_data");

    return 0;
}