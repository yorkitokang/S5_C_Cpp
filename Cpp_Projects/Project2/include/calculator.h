#ifndef _Pro2_H
#define _Pro2_H
#include <vector>
#include <map>
#include <string>
#include <list>
#include <regex>
#include <iostream>
using std::cout;
using std::endl;
using std::regex;
using std::list;
using std::string;
using std::map;
using std::vector;

enum Actions {MULTIPLY, ADD, MINUS, DIVIDE_PRECISE, MOD, POWER};

struct nice_number
{
    bool valid;
    bool positive;
    string critical;
    long long exponential;
};

nice_number add(nice_number first_number, nice_number second_number);

nice_number multiply(nice_number first_number, nice_number second_number);

nice_number minus(nice_number first_number, nice_number second_number);

nice_number dividePrecise(nice_number first_number, nice_number second_number, map<string,nice_number> variable_map);

nice_number mod(nice_number first_number, nice_number second_number);

nice_number squareRoot(nice_number number);

nice_number power(nice_number first_number, nice_number second_number);

nice_number niceNumberGenerator(vector<char> input_stream ,map<string, nice_number> variable_map);

bool variableCheck(int input_length, char *input_stream);

bool operationCheck(char operation);

nice_number calculate(vector<char> input_stream, map<string,nice_number> variable_map);

vector<char> niceNumberToVector(nice_number nice_number_o);

#endif