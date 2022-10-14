#include "calculator.h"
#include <vector>

using std::vector;

vector<int> operations = {37,42,43,45,47,94}; 

bool operationCheck(char operation)
{   
    bool temp_included = false;
    for(int j = 0; j < operations.size(); j++)
    {
        if((int)operation == operations[j])
        {
            temp_included = true;
        }
    }
    if(!temp_included)
    {
        return false;
    }
    return true;
}