#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>

#include "part1.h"

using namespace std;

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
            //cout << line;
            j++;
        }
        file.close();
    }
}
void printData(string data[][6], int j)
{
    int size =  125;
    int i = 0;
    for(i; i < size; i++)
    {
        cout << data[i][j] << endl;
    }
}
void rm_spaces(string data[][6], int j, int flag)
{
    //remove spaces from city, state, & ZIP code
    //can also rm alphabetic characters from ZIP code
    //last name duplicate >> substring/string match?
    int size =  125;
    int i = 0;
    string temp;
    regex f("^ ");
    regex g(" ");
    for(i; i < size; i++)
    {
        temp = data[i][j]; //temp pointer to data or separate???
        if(flag == 1)
        {
            temp = regex_replace(temp, f, "");
        } else {
            temp = regex_replace(temp, g, "");
        }
        
        data[i][j] = temp;
    }
}
void rm_nonNum(string data[][6], int j)
{
    //remove spaces from city, state, & ZIP code
    //can also rm alphabetic characters from ZIP code
    //last name duplicate >> substring/string match?
    int size =  125;
    int i = 0;
    string temp;
    regex e("[^0-9]");
    for(i; i < size; i++)
    {
        temp = data[i][j]; //temp pointer to data or separate???
        temp = regex_replace(temp, e, "");
        data[i][j] = temp;
    }
}