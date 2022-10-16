#include "calculator.h"
#include <iostream>
using std::cout;

nice_number mod(nice_number first_number, nice_number second_number)
{
    // cout <<"----------------------" << endl;
    // cout << "DOING MOD" <<endl;
    // cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << " Positive : " << first_number.positive << endl;
    // cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << " Positive : " << second_number.positive << endl;

    nice_number temp_number= minus(first_number,second_number);
    nice_number previous;
    if(temp_number.positive == false)
    {
        return first_number;
    }

    if(second_number.positive == false)
    {
        temp_number.valid = false;
        cout<< "The model should be positive!" << std::endl;
        return temp_number;
    }

    // if(second_number.exponential < 0)
    // {
    //     temp_number.valid = false;
    //     cout << "The model should be an integer!" << std::endl;
    //     return temp_number;
    // }

    while(temp_number.positive == true)
    {
        previous = temp_number;
        temp_number= minus(temp_number,second_number);
        // cout << temp_number.critical << endl;
        if(temp_number.critical == "0")
        {
            return temp_number;
        }
    }

    return previous;
}