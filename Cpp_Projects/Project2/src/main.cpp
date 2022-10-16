#include "calculator.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <regex>
#include <math.h>

using std::cout;
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::map;
using std::pair; 
using std::regex;

int main()
{

    //Take the input as a 2D array
    // cout << "Please input your calculation:" << endl;
    //vector<vector<char>> input_streams;//read multiple lines
    map<string,nice_number> variable_map;//store the variable

    //READ streams and store
    while (true)
    {
        bool end_of_input = true;
        bool equal_appear = false;
        vector<char> input_str;//line input
        char temp_c;
        char temp_s[100];//The maximum of a line input is 100
        cin.getline(temp_s, 100);
        int equal_index;
        int real_index = 0;

        bool valid_calculation = true;

        //COMPRESS the spaces
        //CHECK if it is an equation
        for(int i = 0; i < strlen(temp_s); i++)
        {
            
            if(temp_s[i] == ' ' || temp_c == '\t')
            {
                continue;
            }

            if(temp_s[i] == '=')
            {
                if(equal_appear)
                {
                    cout << "Input Error: Your entered more than one '='" << endl;
                    continue;
                }else{
                    equal_appear = true;
                    equal_index = real_index;
                    end_of_input = false;
                }
            }
            real_index ++;
            input_str.push_back(temp_s[i]);
        }

        if(input_str.size() == 0)
        {
            cout<< "The input cannot be empty!" << endl;
            continue;
        }

        // !!!!!!!!!!!!!!!!!!!!!!
        // test
        // cout<< "suppressed input:";
        // for(int i = 0; i < input_str.size(); i++)
        // {
        //     cout << input_str[i];
        // }
        // cout << endl; 
        //test
        // !!!!!!!!!!!!!!!!!!!!!!
        //TURN to string to do the test easily
        string test_stream(input_str.begin(),input_str.end());

        //CHECK if you want to stop the operation
        if(test_stream.compare("q") == 0)
        {
            cout << "The end of the calculation";
            break;
        }

        //CHECK if it is an equation, if not, do the calculation
        if(end_of_input)
        {
            //std::cout << "calculate!" << std::endl;
            //calculate the result
            nice_number temp_number = calculate(input_str, variable_map);
            //Remove the zeros in the end
            if(temp_number.exponential < 0 && temp_number.exponential >= -10)
            {
                //cout<< sum.length()<<endl;
                temp_number.critical.insert(temp_number.critical.length()+temp_number.exponential,1,'.');
                for(int i = temp_number.critical.length();;i--)
                {
                    if (temp_number.critical[temp_number.critical.length()-1] == '0')
                    {
                        temp_number.critical.erase(temp_number.critical.length()-1);
                        continue;
                    }
                    if (temp_number.critical[temp_number.critical.length()-1] == '.')
                    {
                        temp_number.critical.erase(temp_number.critical.length()-1);
                        break;
                    }
                    break;
                }
            }else if(temp_number.exponential < -10)
            {
                long long sum_length = temp_number.critical.length();
                temp_number.critical.insert(1,1,'.');
                for(int i = temp_number.critical.length();;i--)
                {
                    if (temp_number.critical[temp_number.critical.length()-1] == '0')
                    {
                        temp_number.critical.erase(temp_number.critical.length()-1);
                        if (temp_number.critical[temp_number.critical.length()-2] == '.')
                        {
                            break;
                        }
                        continue;
                    }
                    break;
                }
                temp_number.exponential += sum_length-1;
                
                if(temp_number.exponential < 0)
                {
                    temp_number.critical.insert(temp_number.critical.length(), 1, 'e');
                    temp_number.critical.insert(temp_number.critical.length(), 1, '-');
                } else if(temp_number.exponential == 0)
                {
                } else
                {
                    temp_number.critical.insert(temp_number.critical.length(), 1, 'e');
                    temp_number.critical.insert(temp_number.critical.length(), 1, '+');
                }
                string final_ten_string = std::to_string(abs(temp_number.exponential));
                //cout << int(log10(abs(final_tens))) << endl;
                for (int i = 0; i < (int)log10(abs(temp_number.exponential))+1; i++)
                {
                    int a = pow(10,i+1);
                    temp_number.critical.append(std::to_string(final_ten_string[i]-'0'));
                }
            }else if (temp_number.exponential > 0)
            {
                long long sum_length = temp_number.critical.length();
                temp_number.critical.insert(1,1,'.');
                temp_number.exponential += sum_length-1;
                for(int i = temp_number.critical.length();;i--)
                {
                    if (temp_number.critical[temp_number.critical.length()-1] == '0')
                    {
                        temp_number.critical.erase(temp_number.critical.length()-1);
                        if (temp_number.critical[temp_number.critical.length()-2] == '.')
                        {
                            break;
                        }
                        continue;
                    }
                    break;
                }
                if(temp_number.exponential != 0)
                {
                    temp_number.critical.insert(temp_number.critical.length(),1,'e');
                    temp_number.critical.insert(temp_number.critical.length(),1,'+');
                }
                
                string final_ten_string = std::to_string(abs(temp_number.exponential));
                for (int i = 0; i < (int)log10(temp_number.exponential)+1; i++)
                {
                    int a = pow(10,i+1);
                    temp_number.critical.append(std::to_string(final_ten_string[i]-'0'));
                }
            }
            cout << temp_number.critical << endl;
            // if(temp_number.exponential == 0)
            // {
            //     cout << "Final Result : " << temp_number.critical << std::endl;
            // }else
            // {
            //     cout << "Final Result : " << temp_number.critical << "e" << temp_number.exponential << std::endl;
            // }
        }else
        {
            char variable_name[10] = {'\0'};// have to initialize with that
            for(int i = 0; i < equal_index; i++)
            {
                variable_name[i] = input_str[i];
            }
            //check the validation of the variable 
            if(!variableCheck(strlen(variable_name), variable_name))
            {
                cout << "The variable name is wrong!" << endl;
                continue;
            }
            //cout << "The variable: "<< variable_name << endl;
             //variable_map.insert();
            char variable_value[100] = {'\0'};
            int j = 0;
            for(int i = equal_index + 1; i < input_str.size(); i++)
            {
                variable_value[j] = input_str[i];
                j++;
            }
            //cout << "The value: "<< variable_value << endl;
            vector<char> variable_value_vector = {};
            for(int i = 0; i < strlen(variable_value);i++)
            {
                variable_value_vector.push_back(variable_value[i]);
            }
            variable_map.insert(pair<string,nice_number> (variable_name,niceNumberGenerator(variable_value_vector,variable_map)));
        }
    }
    return 0;
}