#include "calculator.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <regex>

using std::cout;
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::map;
using std::pair; 
using std::regex;

// regex positive_int_reg("[+]?[1-9][0-9]*");
// regex zero_reg("[+-]?[0][.]?[0]*");
// regex negative_int_teg("[-][1-9][0-9]*");
// regex positive_float_reg("[+]?[1-9][0-9]*[.][0-9]+");
// regex negative_float_reg("[-][1-9][0-9]*[.][0-9]+");
// regex positive_scientific_float("[+]?[1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
// regex negative_scientific_float("[-][1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
// regex positive_scientific_exp("[+]?[1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
// regex negative_scientific_exp("[-][1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
// list<regex> regex_list= {
//     positive_int_reg,
//     zero_reg,
//     negative_int_teg,
//     positive_float_reg,
//     negative_float_reg,
//     positive_scientific_float,
//     negative_scientific_float,
//     positive_scientific_exp,
//     negative_scientific_exp
// };

int main()
{

    //Take the input as a 2D array
    cout << "Please input your calculation:" << endl;
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
        cout<< "suppressed input:";
        for(int i = 0; i < input_str.size(); i++)
        {
            cout << input_str[i];
        }
        cout << endl; 
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
            std::cout << "calculate!" << std::endl;
            //calculate the result
            nice_number temp_number = calculate(input_str, variable_map);
            cout << "Final Result : " << temp_number.critical << "e" << temp_number.exponential << std::endl;
            cout << "Positive : " << temp_number.positive << endl;
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
            cout << "The variable: "<< variable_name << endl;
             //variable_map.insert();
            char variable_value[100] = {'\0'};
            int j = 0;
            for(int i = equal_index + 1; i < input_str.size(); i++)
            {
                variable_value[j] = input_str[i];
                j++;
            }
            cout << "The value: "<< variable_value << endl;
            vector<char> variable_value_vector = {};
            for(int i = 0; i < strlen(variable_name);i++)
            {
                variable_value_vector.push_back(variable_value[i]);
            }
            variable_map.insert(pair<string,nice_number> (variable_name,niceNumberGenerator(variable_value_vector,variable_map)));
        }
    }
    return 0;
}