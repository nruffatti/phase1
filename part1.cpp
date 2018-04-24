#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>

#include "part1.h"

using namespace std;

const int SIZE = 125;

//get data from file changing
//delimiters when necessary
void getData(string data[][6]) {
    string line;
    ifstream file ("customer___data.txt");
    if(file.is_open())
    {
        int i = -1;
        int j = 0;
        char delimiter = '\n';
        while(getline(file, line, delimiter))
        {
            replace(line.begin(), line.end(), '"', '\0');
            if(i == -1)
            {
                delimiter = '\t';
                i++;
                continue;
            }
            if(j == 1)
            {
                delimiter = ',';
            }
            if(j == 4)
            {
                delimiter = '\t';
            }
            if(j == 5)
            {
                delimiter = '\n';
            }
            if(j == 6)
            {
                delimiter = '\t';
                j = 0;
                i++;
                continue;
            }
            data[i][j] = line;
            j++;
        }
        file.close();
    }
}

//print data for given column
void printData(string data[][6], int j)
{
    int i = 0;
    for(i; i < SIZE; i++)
    {
        cout << data[i][j] << endl;
    }
}

//remove initial space character for given columns(city, state)
void rm_spaces(string data[][6], int j)
{
    for(int i = 0; i < SIZE; i++)
    {
        data[i][j] = data[i][j].substr(1);
    }
}

//take zipcode substring
void rm_nonNum(string data[][6], int j)
{
    for(int i = 0; i < SIZE; i++)
    {
        data[i][j] = data[i][j].substr(1,5);
    }
}

//export bad_data
void bad_data(string data[][6])
{
    vector<int> bad;
    string temp;
    string badTemp[125][7];
    int k = 0;
    
    //find empty or partial data
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            temp = data[i][j];
            if(temp.length() < 5 && j == 5 || temp.length() < 6 && j == 2 || temp.length() < 2)
            {
                bad.push_back(i);
                k++;
            }
        }
    }
    
    //duplicates
    string firstTemp;
    int after;
    for (int z = 0; z < SIZE; z++)
    {
        temp = data[z][1];
        firstTemp = data[z][0];
        after = z+1;
        for (int i = after; i < SIZE; i++)
        {
            if(temp.compare(data[i][1]) == 0)
            {
                if(firstTemp.find(data[i][0]) != string::npos || data[i][0].find(firstTemp) != string::npos)
                {
                    bad.push_back(i);
                    bad.push_back(z);
                }
            }
        }
    }
    
    //export bad data
    string conv;
    for (int i = 0; i < bad.size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(j == 6)
            {
                stringstream tt;
                tt << bad.at(i);
                badTemp[i][j] = tt.str();
                tt.clear();
            } else {
                badTemp[i][j] = data[bad.at(i)][j];
            }
        }
    }
    //save(badTemp, "badData");
    //save(bad, "badDataPos");
    
}

//save 2d array to file
void save(string data[][6], string name)
{
    ofstream file;
    name += ".csv";
    file.open(name);
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            file << data[i][j] << ",";
        }
        file << endl;
    }
    file.close();
}

//overloaded
void save(string data[][7], string name)
{
    ofstream file;
    name += ".csv";
    file.open(name);
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            file << data[i][j] << ",";
        }
        file << endl;
    }
    file.close();
}

//overloaded
void save(vector<int> data, string name)
{
    ofstream file;
    name += ".csv";
    file.open(name);
    
    for(int i = 0; i < data.size(); i++)
    {
        file << data.at(i) << ",";
    }
    file.close();
}

//fix bad data
void fix_bad(string data[][6])
{
    //import fixed data and location
    string line;
    int t;
    vector<int> bad;
    vector<vector<string>> temp;
    vector<string> row;
    ifstream f ("badData.csv");
    if(f.is_open())
    {
        int j = 0;
        int i = 0;
        char delimiter = ',';
        while(getline(f, line, delimiter))
        {
            if(j == 6)
            {
                stringstream ss(line);
                ss >> t;
                cout << t << endl;
                bad.push_back(t);
                ss.clear();
            } else {
                row.push_back(line);
            }
            j++;
            if(j == 6)
            {
                delimiter = '\n';
            }
            if(j == 7)
            {
                temp.push_back(row);
                row.clear();
                j = 0;
                i++;
                delimiter = ',';
            }
        }
        f.close();
    }
    
    //replace bad with good data
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            data[bad.at(i)][j] = temp[i][j];
        }
    }
}