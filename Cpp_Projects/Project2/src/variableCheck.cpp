#include "calculator.h"
#include <vector>

using std::vector;

vector<int> alphabet = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
                    95,
                    97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
vector<int> alphaNumber = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
                    95,
                    97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,
                    48,49,50,51,52,53,54,55,56,57}; 

bool variableCheck(int input_length, char *input_stream)
{
    bool first_included = false;
    for(int i = 0; i < alphabet.size(); i++)
    {
        if((int)input_stream[0] == alphabet[i])
        {
            first_included = true;
        }
    }
    if(!first_included)
    {
        return false;
    }
    
    for(int i = 1; i < input_length; i++)
    {
        bool temp_included = false;
        for(int j = 0; j < alphaNumber.size(); j++)
        {
            if((int)input_stream[i] == alphaNumber[j])
            {
                temp_included = true;
            }
        }
        if(!temp_included)
        {
            return false;
        }
    }
    return true;
}