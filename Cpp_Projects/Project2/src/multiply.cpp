#include "calculator.h"
#include <iostream>
#include <regex>
#include <string>
#include <math.h>

using std::cout;
using std::string;
using std::regex;
using std::endl;
using std::to_string;

nice_number multiply(nice_number first_number, nice_number second_number)
{
    cout <<"----------------------" << endl;
    cout << "DOING MUL" <<endl;
    cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << " Positive : " << first_number.positive << endl;
    cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << " Positive : " << second_number.positive << endl;
    string number_one_critical = first_number.critical;
    string number_two_critical = second_number.critical;
    long long number_one_tens = first_number.exponential;
    long long number_two_tens = second_number.exponential;
    // calculate critical
    int sum_critical[1000];
    for(int i = 0; i < 100; i++)
    {
        sum_critical[i] = 0;
    }

    for (int i = 0; i < number_one_critical.length(); i++)
    {
        int temp = 0;
        for (int j = 0; j < number_two_critical.length(); j++)
        {
            //cout << number_one_critical[i]-'0' << number_two_critical[j]-'0'<< endl;
            //cout << (number_one_critical[i]-'0') * (number_two_critical[j]-'0') + temp << endl;
            sum_critical[i+j] += (number_one_critical[number_one_critical.length() - i - 1]-'0') * (number_two_critical[number_two_critical.length() - j - 1]-'0') + temp;
            temp = sum_critical[i+j]/10;
            sum_critical[i+j] %= 10 ;
        }
        sum_critical[i+number_two_critical.length()] += temp;
    }
    // calculate tens
    string sum;
    int index = number_one_critical.length() + number_two_critical.length();
    while(sum_critical[index]==0 && index>0) index--;
    //cout << index << endl;
    for(int i=index; i >=0; i--)
    {
        sum.append(to_string(sum_critical[i]));
    }
		
    bool final_positive = true;
    if(first_number.positive ^ second_number.positive)
    {
        final_positive = false;
    }
    //cout << sum << endl;
    long long final_tens = number_one_tens + number_two_tens;
    nice_number temp_number = {true,final_positive,sum,final_tens};
    return temp_number;
}