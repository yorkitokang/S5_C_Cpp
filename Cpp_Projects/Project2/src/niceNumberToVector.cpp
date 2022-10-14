#include "calculator.h"
#include <vector>
#include <string>
using std::to_string;
using std::string;
vector<char> niceNumberToVector(nice_number nice_number_o)
{
    vector<char> nice_vector;
    if(nice_number_o.positive == false)
    {
        nice_vector.push_back('-');
    }

    if(nice_number_o.exponential == 0)
    {
        for(int i = 0; i < nice_number_o.critical.size();i++)
        {
            nice_vector.push_back(nice_number_o.critical[i]);
        }
        return nice_vector;
    } else if(nice_number_o.exponential != 0)
    {
        if(nice_number_o.exponential < 0)
        {
            nice_vector.push_back('-');
        }
        for(int i = 0; i < nice_number_o.critical.size();i++)
        {
            nice_vector.push_back(nice_number_o.critical[i]);
        }
        nice_vector.push_back('e');
        string exponential = to_string(nice_number_o.exponential);
        for(int i = 0; i < exponential.size();i++)
        {
            nice_vector.push_back(exponential[i]);
        }
        return nice_vector;
    }
}