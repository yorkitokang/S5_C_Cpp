#include "calculator.h"
#include <iostream>
using std::endl;
using std::cout;

nice_number add(nice_number first_number, nice_number second_number)
{
    cout <<"----------------------" << endl;
    cout << "DOING ADDING" <<endl;
    cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << "Positive : " << first_number.positive << endl;
    cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << "Positive : " << second_number.positive << endl;
    nice_number temp_number = {};
    string first_adder = first_number.critical;
    string second_adder = second_number.critical;

    if(first_number.positive^second_number.positive)
    {
        if(first_number.positive)
        {
            second_number.positive = true;
            return minus(first_number,second_number);
        } else
        {
            first_number.positive = true;
            return minus(second_number,first_number);
        }
    } else if(first_number.positive)
    {
        temp_number.positive = true;
    } else{
        temp_number.positive = false;
    }

    if(second_number.exponential < 0 && first_number.exponential < 0)
    {
        for(int i = second_number.exponential; i < 0; i++)
        {
            first_adder.append("0");
        }
        for(int i = first_number.exponential; i < 0; i++)
        {
            second_adder.append("0");
        }
        temp_number.exponential = second_number.exponential + first_number.exponential;
    } else if(second_number.exponential >= 0 && first_number.exponential < 0)
    {
        for(int i = first_number.exponential; i < second_number.exponential; i++)
        {
            second_adder.append("0");
        }

        temp_number.exponential = first_number.exponential;
    } else if(first_number.exponential >= 0 && second_number.exponential < 0)
    {
        for(int i = second_number.exponential; i < first_number.exponential; i++)
        {
            first_adder.append("0");
        }

        temp_number.exponential = second_number.exponential;
    } else 
    {
        for(int i = 0; i < first_number.exponential;i++)
        {
            first_adder.append("0");
        }

        for(int i = 0; i < second_number.exponential;i++)
        {
            second_adder.append("0");
        }
        temp_number.exponential = 0;
    }
    int size = 0;
    first_adder.size() >= second_adder.size() ? size = first_adder.size() : size = second_adder.size();
    for(int i = 0; i < size ; i++)
    {
        if(first_adder.size() < size) first_adder.insert(0,"0");
        if(second_adder.size() < size) second_adder.insert(0,"0");
    }
    int reserve = 0;
    for(int i = size-1; i >=0 ; i--)
    {
        int plot = 0;
        if(reserve)
        {
            plot += 1;
            reserve = 0;
        }
        plot = first_adder[i] + second_adder[i] - '0' -'0';
        if(plot >= 10)
        {
            reserve = 1; 
            plot -= 10;
        }
        string temp_char;
        temp_char.push_back((char)(plot+(int)'0'));
        temp_number.critical.insert(0,temp_char);
    }
    if(reserve)
    {
        temp_number.critical.insert(0,"1");
    }
    temp_number.valid = true;
    return temp_number;
}