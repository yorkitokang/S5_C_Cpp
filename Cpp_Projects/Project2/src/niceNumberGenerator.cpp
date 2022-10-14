#include "calculator.h"
#include <vector>
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
nice_number niceNumberGenerator(vector<char> input_stream, map<string, nice_number> variable_map)
{
    char number_one_temp[100] = "";
    for(int i = 0; i < input_stream.size();i++)
    {
        number_one_temp[i] = input_stream[i];
    }
    string number_one(number_one_temp);
    string number_one_critical;
    long long number_one_tens = 0;
    bool one_positive = true;
    regex positive_int_reg("[1-9][0-9]*");
    regex zero_reg("[0][.]?[0]*");
    regex negative_int_teg("[-][1-9][0-9]*");
    regex positive_float_reg("[1-9][0-9]*[.][0-9]+");
    regex negative_float_reg("[-][1-9][0-9]*[.][0-9]+");
    regex positive_scientific_float("[1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
    regex negative_scientific_float("[-][1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
    regex positive_scientific_exp("[1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
    regex negative_scientific_exp("[-][1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
    if(regex_match(number_one,positive_int_reg))
    {
        //cout<<"positive int"<<endl;
        if (number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        number_one_critical = number_one;
    }else if(regex_match(number_one,zero_reg))
    {
        //cout<<"zero_reg"<<endl;
        number_one_critical = "0";
    }else if(regex_match(number_one,negative_int_teg))
    {
        //cout<<"negative_int_teg"<<endl;
        number_one.erase(0,1);
        number_one_critical = number_one;
        one_positive = false;
    }else if(regex_match(number_one,negative_float_reg))
    {
        //cout<<"negative_float_reg"<<endl;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                number_one_tens = -(number_one.length() - i - 1);
                number_one.erase(i,1);
            }
        }
        number_one_critical = number_one;
        one_positive = false;
    }else if(regex_match(number_one,positive_float_reg))
    {
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                number_one_tens = -(number_one.length() - i - 1);
                number_one.erase(i,1);
            }
        }
        number_one_critical = number_one;
        //cout<<"positive_float_reg"<<endl;
    }else if(regex_match(number_one,positive_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position+1, number_one.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        
        //cout<<"positive_scientific_float"<<endl;
    }else if(regex_match(number_one,negative_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position+1, number_one.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        one_positive = false;
        //cout<<"negative_scientific_float"<<endl;
    }else if(regex_match(number_one,positive_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                if(number_one[i+1] == '+')
                {
                    number_one.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position + 1, number_one.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        //cout<<"positive_scientific_exp"<<endl;
    }else if(regex_match(number_one,negative_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                if(number_one[i+1] == '+')
                {
                    number_one.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position + 1, number_one.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        one_positive = false;
        //cout<<"negative_scientific_exp"<<endl;
    }else
    {

        map<string, nice_number>::iterator iter;
        iter = variable_map.begin();
        while(iter != variable_map.end()) {
            if(iter->first == number_one)
            {
                return variable_map[number_one];
            }
            iter++;
        }
        cout << "The input cannot be interpret as numbers!" << endl;
        nice_number temp_number = {false,true,"",0};
        return temp_number;
    }
    nice_number this_number = {true,one_positive,number_one_critical, number_one_tens};
    return this_number; 
}