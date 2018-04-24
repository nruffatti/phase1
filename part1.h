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
extern void rm_spaces(string data[][6], int j, int flag = 0);
extern void rm_nonNum(string data[][6], int j);

#endif /* PART1_H */