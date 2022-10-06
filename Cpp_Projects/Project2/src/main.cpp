#include "calculator.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::map;

int main()
{
    //The number cache is 40 max,
    struct nice_number numbers[40];

    //Take the input as a 2D array
    cout << "Please input the your calculation:" << endl;
    vector<vector<char>> input_streams;//read multiple lines
    map<string,nice_number> variable_map;//store the variable

    //READ streams and store
    while (true)
    {
        bool end_of_input = true;
        vector<char> input_str;//line input
        char temp_c;
        char temp_s[100];//The maximum of a line input is 100
        cin.getline(temp_s, 100);
        int equal_index;
        int real_index = 0;

        //COMPRESS the spaces
        //CHECK if it is an equation
        for(int i = 0; i < strlen(temp_s); i++)
        {
            
            if(temp_s[i] == ' ')
            {

                continue;
            }

            if(temp_s[i] == '=')
            {
                if(end_of_input == true)
                {
                    cout << "Input Error: Your entered more than one '='";
                }else{
                    end_of_input = true;
                }
            }

            input_str.push_back(temp_s[i]);
        }

        // !!!!!!!!!!!!!!!!!!!!!!
        // test
        for(int i = 0; i < input_str.size(); i++)
        {
            cout << input_str[i];
        }
        //test
        // !!!!!!!!!!!!!!!!!!!!!!

        //TURN to string to do the test easily
        string test_stream(input_str.begin(),input_str.end());

        //CHECK if you want to stop the operation
        if(test_stream.compare("q"))
        {
            cout << "The end of the calculation";
            break;
        }

        //CHECK if it is an equation, if not, do the calculation
        if(end_of_input)
        {
            calculate(input_streams, variable_map);
        }else
        {
            variable_map.insert();
        }
    }
}