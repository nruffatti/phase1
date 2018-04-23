#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>

#include "part1.h"

using namespace std;

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
    int size =  125;
    int i = 0;
    for(i; i < size; i++)
    {
        cout << data[i][j] << endl;
    }
}
void rm_spaces(string data[][6], int j)
{
    //remove unneeded spaces from city, state
    int size =  125;
    int i = 0;
    for(i; i < size; i++)
    {
        data[i][j] = data[i][j].substr(1);
    }
}
void rm_nonNum(string data[][6], int j)
{
    //remove non-numbers from ZIP code
    int size =  125;
    int i = 0;
    for(i; i < size; i++)
    {
        data[i][j] = data[i][j].substr(1,5);
    }
}

//export bad_data
void bad_data(string data[][6])
{
    int size = 125;
    int bad[7];
    string temp;
    string badTemp[125][6];
    int k = 0;
    
    //find empty or partial data
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < size; i++)
        {
            temp = data[i][j];
            if(temp.length() < 5 && j == 5 || temp.length() < 6 && j == 2 || temp.length() < 2)
            {
                bad[k] = i;
                k++;
            }
        }
    }
    
    //duplicates
    string firstTemp;
    int after;
    for (int z = 0; z < size; z++)
    {
        temp = data[z][1];
        firstTemp = data[z][0];
        after = z+1;
        for (int i = after; i < size; i++)
        {
            if(temp.compare(data[i][1]) == 0)
            {
                if(firstTemp.find(data[i][0]) != string::npos || data[i][0].find(firstTemp) != string::npos)
                {
                    bad[k] = i;
                    k++;
                    bad[k] = z;
                    k++;
                }
            }
        }
    }
    
    //export bad data
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            badTemp[i][j] = data[bad[i]][j];
        }
    }
    save(badTemp, "badData");
    save(bad, "badDataPos");
    
}

//save 2d array to file
void save(string data[][6], string name)
{
    int size = 125;
    ofstream file;
    name += ".csv";
    file.open(name);
    
    for(int i = 0; i < size; i++)
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
void save(int data[], string name)
{
    int size = 7;
    ofstream file;
    name += ".csv";
    file.open(name);
    
    for(int i = 0; i < size; i++)
    {
        file << data[i] << ",";
    }
    file.close();
}

//fix bad data
void fix_bad(string data[][6])
{
    //import location
    string line;
    ifstream file ("badDataPos.csv");
    int bad[7];
    if(file.is_open())
    {
        int j = 0;
        char delimiter = ',';
        while(getline(file, line, delimiter))
        {
            bad[j] = stoi(line);
            j++;
        }
        file.close();
    }
    
    //import fixed data
    string temp[7][6];
    ifstream f ("fixedBadData.csv");
    if(f.is_open())
    {
        int j = 0;
        int i = 0;
        char delimiter = ',';
        while(getline(f, line, delimiter))
        {
            temp[i][j] = line;
            j++;
            if(j == 5)
            {
                delimiter = '\n';
            }
            if(j == 6)
            {
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
            data[bad[i]][j] = temp[i][j];
        }
    }
}