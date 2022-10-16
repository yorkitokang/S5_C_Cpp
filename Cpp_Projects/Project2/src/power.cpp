#include "calculator.h"
#include <iostream>

using namespace std;
nice_number power(nice_number first_number, nice_number second_number)
{
    // cout <<"----------------------" << endl;
    // cout << "DOING POWER" <<endl;
    // cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << " Positive : " << first_number.positive << endl;
    // cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << " Positive : " << second_number.positive << endl;
    nice_number temp_number;
    nice_number result;
    if(second_number.exponential != 0)
    {
        cout << "The exponential part of the power cannot be in scientific mode!" << endl;
        temp_number.valid = false;
        return temp_number;
    }
    if(second_number.positive == false)
    {
        cout << "Calculator doesn't support negative exponential!" << endl;
        temp_number.valid = false;
        return temp_number;
    }
    if(first_number.critical[first_number.critical.size()])
    if(second_number.critical == "0")
    {
        if(first_number.critical == "0")
        {
            temp_number.valid = false;
            cout << "0^0 is not a good expression" << std::endl;
            return temp_number;
        }
        temp_number.positive = true;
        temp_number.critical = "1";
        temp_number.exponential = 0;
        temp_number.valid = true;
        return temp_number;
    }
    temp_number = first_number;
    for(int i = 0; i < second_number.critical.size(); i++)
    {
        int initial = '1';
        for(int j = 0; j < 10; j++)
        {
            if(initial == (int)second_number.critical[i])
            {
                break;
            }
            temp_number = multiply(first_number,temp_number);
            initial++;
        }
    }
    return temp_number;
}