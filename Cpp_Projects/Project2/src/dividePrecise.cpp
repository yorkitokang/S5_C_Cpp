#include "calculator.h"
nice_number dividePrecise(nice_number first_number, nice_number second_number, map<string,nice_number> variable_map)
{
    cout <<"----------------------" << endl;
    cout << "DOING DIVIDE" <<endl;
    cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << " Positive : " << first_number.positive << endl;
    cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << " Positive : " << second_number.positive << endl;

    nice_number temp_number;
    if(first_number.critical == "0")
    {
        temp_number.positive = false;
        temp_number.valid = true;
        temp_number.critical = "0";
        temp_number.exponential = 0;
        return temp_number;
    }

    if(second_number.critical == "0")
    {
        temp_number.positive = true;
        temp_number.valid = false;
        temp_number.critical = "The divisor cannot be 0!";
        temp_number.exponential = 0;
        return temp_number;
    }

    string result;
    vector<char> temp_divisor;
    
    nice_number temp_divisor_nice;
    nice_number num_multiplier;
    temp_divisor_nice.positive = true;

    for(int i = 0; i < first_number.critical.size() + 16; i++)
    {
        int index = 0;
        if(i < first_number.critical.size()){
            temp_divisor.push_back(first_number.critical[i]);
        } else {
            temp_divisor.push_back('0');
        }
        temp_divisor_nice = niceNumberGenerator(temp_divisor,variable_map);
        nice_number temp = temp_divisor_nice;
        while(true)
        {
            index++;
            vector<char> temp_vector;
            if(index == 10){
                temp_vector = {'1','0'};
            } else {
                temp_vector = {(char)(index + '0')};
            }
            num_multiplier = multiply(niceNumberGenerator(temp_vector,variable_map),second_number);
            nice_number capacitor = minus(temp_divisor_nice,num_multiplier);
            cout << capacitor.positive << endl;
            if(capacitor.positive == true && capacitor.critical != "0")
            {
            }else if(capacitor.critical == "0")
            {
                temp_divisor_nice = {true,true,"0",0};
                temp_divisor = niceNumberToVector(temp_divisor_nice);
                char j = (char)(index + '0');
                result.push_back(j);
                break;
            }else{
                temp_divisor_nice = temp;
                temp_divisor = niceNumberToVector(temp_divisor_nice);
                char j = (char)(index + '0' -1);
                result.push_back(j);
                break;
            }
            temp = capacitor;
        }
        
    }


    bool begin = false;
    string cache;
    for(int i = 0; i < result.size(); i ++)
    {
        if(result[i] == '0' && !begin )
        {
            continue;
        }else{
            cache.push_back(result[i]);
            begin = true;
        }
    }
    result = cache;

    temp_number.valid = true;
    temp_number.critical = result;
    temp_number.exponential = first_number.exponential + second_number.exponential - 16;

    if(first_number.positive^second_number.positive)
    {
        temp_number.positive = false;
    } else{
        temp_number.positive = true;
    }

    return temp_number;
}