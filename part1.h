/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   part1.h
 * Author: Nathan R
 *
 * Created on April 14, 2018, 6:22 PM
 */

#ifndef PART1_H
#define PART1_H

using namespace std;

extern void getData(string data[][6]);
extern void printData(string data[][6], int j);
extern void rm_spaces(string data[][6], int j);
extern void rm_nonNum(string data[][6], int j);
extern void bad_data(string data[][6]);
extern void save(string data[][6], string name);
extern void save(int data[], string name);
extern void fix_bad(string data[][6]);

#endif /* PART1_H */

