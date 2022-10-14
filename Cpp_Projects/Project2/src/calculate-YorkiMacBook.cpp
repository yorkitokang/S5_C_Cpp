#include "calculator.h"
#include <iostream>
#include <assert.h>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::regex;

nice_number calculate(vector<char> input_stream, map<string, nice_number> variable_map)
{

    regex squareRoot_regex("[s][q][r][t][(](.+)[)]");
    regex minus_regex("[-](.+)");

    nice_number not_valid_number = {false, true, "", 0};
    vector<vector<char>> expression_vector;
    vector<char> action_vector;
    vector<int> expression_positions = {0};
    vector<char> minus_ion = {'-','1'};

    string input_string;
    for (int i = 0; i < input_stream.size(); i++)
    { 
        input_string.push_back(input_stream[i]);
    }
    cout << "Input string!" << input_string << endl;

    if (regex_match(input_string, squareRoot_regex))
    {
        cout << "Doing square root!" << std::endl;
        return squareRoot(niceNumberGenerator(input_stream,variable_map));
    }

    if(regex_match(input_string,minus_regex))
    {
        cout << "You've input a minus number" << endl;
        vector<char> temp_char;
        for(int i = 1; i < input_stream.size();i++)
        {
            temp_char.push_back(input_stream[i]);
        }
        nice_number temp_number = calculate(temp_char,variable_map);
        temp_number.positive ? temp_number.positive = false:temp_number.positive = true;
        return temp_number;
    }

    for (int i = 0; i < input_stream.size(); i++)
    {

        if (input_stream[i] == '(')
        {
            int round_bracket = 1;
            expression_positions[expression_vector.size()] = i + 1;
            bool minus = false;
            for (i = i + 1; i < input_stream.size(); i++)
            {
                if (input_stream[i] == ')')
                {
                    round_bracket -= 1;
                    assert(round_bracket >= 0);
                }
                if (input_stream[i] == '(')
                {
                    round_bracket += 1;
                }
                if (input_stream[i] == ')' && round_bracket == 0)
                {
                    vector<char> temp_expression;
                    for (int k = expression_positions[expression_vector.size()]; k < i; k++)
                    {
                        temp_expression.push_back(input_stream[k]);
                    }
                    cout << "calculate!" << std::endl;
                    //very important, iteration
                    nice_number temp_nice_number = calculate(temp_expression, variable_map);
                    vector<char> temp_expression_2 = niceNumberToVector(temp_nice_number);
                    expression_vector.push_back(temp_expression_2); // push_back can avoid index;
                    break;
                }
            }
            assert(round_bracket == 0);
            continue;
        }

        if (operationCheck(input_stream[i]))
        {
            if (((input_stream[i] == '-' || input_stream[i] == '+') && input_stream[i - 1] == 'e' )|| input_stream[i-1] == ')')
            {
                continue;
            }
            action_vector.push_back(input_stream[i]);
            vector<char> temp_expression;
            for (int j = expression_positions[expression_vector.size()]; j < i; j++)
            {
                temp_expression.push_back(input_stream[j]);
            }

            expression_positions.push_back(i + 1);
            expression_vector.push_back(temp_expression);

            
            continue;
        }

        if (i == input_stream.size() - 1)
        {
            assert(!operationCheck(input_stream[i]));
            vector<char> temp_expression;
            for (int j = expression_positions[expression_vector.size()]; j <= i; j++)
            {
                temp_expression.push_back(input_stream[j]);
            }
            expression_vector.push_back(temp_expression);
            break;
        }
    }
    //
    cout << "Number of expressions: " << expression_vector.size() << std::endl;
    cout << "Number of actions: " << action_vector.size() << std::endl;
    for (int i = 0; i < expression_positions.size(); i++)
    {
        cout << "Expression positions " << i << ":" << expression_positions[i] << std::endl;
    }
    cout << "expression_vectors : " << std::endl;
    for (int i = 0; i < expression_vector.size(); i++)
    {
        for (int j = 0; j < expression_vector[i].size(); j++)
        {
            cout << expression_vector[i][j];
        }
        cout << std::endl;
    }
    cout << "action_vectors :" << std::endl;
    for (int i = 0; i < action_vector.size(); i++)
    {
        cout << action_vector[i] << std::endl;
    }

    // second part
    vector<char> add_minus;
    vector<nice_number> basket;
    int action_quantity = action_vector.size();

    for (int i = 0; i < action_quantity; i++)
    {
        cout << "p1" << std::endl;
        if (action_vector[i] == '+' || action_vector[i] == '-')
        {
            cout << "Action quantity" << action_quantity << std::endl;
            if (i == 0)
            {
                cout << "p4" << std::endl;
                basket.push_back(niceNumberGenerator(expression_vector[i], variable_map));
                cout << "p4" << std::endl;
            }
            if (i == action_quantity - 1)
            {
                cout << "p5" << std::endl;
                basket.push_back(niceNumberGenerator(expression_vector[i + 1], variable_map));
            }
            if (action_vector[i + 1] == '+' || action_vector[i + 1] == '-')
            {
                cout << "p6" << std::endl;
                basket.push_back(niceNumberGenerator(expression_vector[i + 1],variable_map));
            }
            add_minus.push_back(action_vector[i]);
            continue;
        }

        if (i == 0 || (action_vector[i - 1] == '+' || action_vector[i - 1] == '-')) // actually, we don't need this
        {
            cout << "p2" << std::endl;
            vector<nice_number> temp_number;
            vector<char> temp_action;
            temp_number.push_back(niceNumberGenerator(expression_vector[i],variable_map));
            if (!niceNumberGenerator(expression_vector[i],variable_map).valid)
            {
                return not_valid_number;
            }
            temp_number.push_back(niceNumberGenerator(expression_vector[i + 1],variable_map));
            if (!niceNumberGenerator(expression_vector[i + 1],variable_map).valid)
            {
                return not_valid_number;
            }
            temp_action.push_back(action_vector[i]);

            for (i = i + 1; i < action_vector.size(); i++)
            {
                if (!(action_vector[i] == '+' || action_vector[i] == '-'))
                {
                    temp_number.push_back(niceNumberGenerator(expression_vector[i],variable_map));
                    if (!niceNumberGenerator(expression_vector[i],variable_map).valid)
                    {
                        return not_valid_number;
                    }
                    temp_action.push_back(action_vector[i]);
                    continue;
                }
                break;
            }
            cout << "p3" << std::endl;
            for (int j = 0; j < temp_action.size(); j++)
            {
                switch (temp_action[j])
                {
                case '*':
                    temp_number[j + 1] = multiply(temp_number[j], temp_number[j + 1]);
                    break;
                case '/':
                    temp_number[j + 1] = dividePrecise(temp_number[j], temp_number[j + 1],variable_map);
                    break;
                case '^':
                    temp_number[j + 1] = power(temp_number[j], temp_number[j + 1]);
                    break;
                case '%':
                    temp_number[j + 1] = mod(temp_number[j], temp_number[j + 1]);
                    break;
                }
            }
            cout << "p4" << std::endl;
            basket.push_back(temp_number[temp_number.size() - 1]);
            cout << "p5" << std::endl;
        }
    }

    if (basket.size() == 0)
    {
        return basket[0];
    }
    for (int i = 0; i < add_minus.size(); i++)
    {
        switch (add_minus[i])
        {
        case '-':
            basket[i + 1] = minus(basket[i], basket[i + 1]);
            break;
        case '+':
            basket[i + 1] = add(basket[i], basket[i + 1]);
            break;
        }
    }
    return basket[basket.size() - 1];
}