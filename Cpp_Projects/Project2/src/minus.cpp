#include "calculator.h"

nice_number minus(nice_number first_number, nice_number second_number)
{
    cout <<"----------------------" << endl;
    cout << "DOING MINUS" <<endl;
    cout << "The first number is :" << first_number.critical << "e" << first_number.exponential << " Positive : " << first_number.positive << endl;
    cout << "The second number is :" << second_number.critical << "e" << second_number.exponential << " Positive : " << second_number.positive << endl;

    nice_number temp_number;
    string first_sub = first_number.critical;
    string second_sub = second_number.critical;
    bool pre_positive;

    if(first_number.positive^second_number.positive)
    {
        if(first_number.positive)
        {
            second_number.positive = true;
            return add(first_number,second_number);
        }else
        {
            second_number.positive = false;
            return add(first_number, second_number);
        }
    }
    if(first_number.positive)
    {
        pre_positive = true;
    } else 
    {
        pre_positive = false;
    }

    if(second_number.exponential < 0 && first_number.exponential < 0)
    {
        for(int i = second_number.exponential; i < 0; i++)
        {
            first_sub.append("0");
        }
        for(int i = first_number.exponential; i < 0; i++)
        {
            second_sub.append("0");
        }
        temp_number.exponential = second_number.exponential + first_number.exponential;
    } else if(second_number.exponential >= 0 && first_number.exponential < 0)
    {
        for(int i = first_number.exponential; i < second_number.exponential; i++)
        {
            second_sub.append("0");
        }

        temp_number.exponential = first_number.exponential;
    } else if(first_number.exponential >= 0 && second_number.exponential < 0)
    {
        for(int i = second_number.exponential; i < first_number.exponential; i++)
        {
            first_sub.append("0");
        }
        temp_number.exponential = second_number.exponential;
    } else 
    {
        for(int i = 0; i < first_number.exponential;i++)
        {
            first_sub.append("0");
        }

        for(int i = 0; i < second_number.exponential;i++)
        {
            second_sub.append("0");
        }
        temp_number.exponential = 0;
    }

    int size = 0;
    first_sub.size() >= second_sub.size() ? size = first_sub.size() : size = second_sub.size();
    for(int i = 0; i < size ; i++)
    {
        if(first_sub.size() < size) first_sub.insert(0,"0");
        if(second_sub.size() < size) second_sub.insert(0,"0");
    }

    if(first_sub.size() > second_sub.size())
    {
        pre_positive ? temp_number.positive = true : temp_number.positive = false;
    } else if(first_sub.size() < second_sub.size())
    {
        pre_positive ? temp_number.positive = false : temp_number.positive = true;
        string temp = first_sub;
        first_sub = second_sub;
        second_sub = temp;
    } else 
    {
        bool is_zero;
        for(int i = 0; i  <first_sub.size() ;i++)
        {
            if(first_sub[i] > second_sub[i])
            {
                pre_positive ? temp_number.positive = true : temp_number.positive = false;
                is_zero = false;
                break;
            } else if(first_sub[i] < second_sub[i])
            {
                pre_positive ? temp_number.positive = false : temp_number.positive = true;
                string temp = first_sub;
                first_sub = second_sub;
                second_sub = temp;
                is_zero = false;
                break;
            }
        }
        if(is_zero)
        {
            temp_number.critical = "0";
            temp_number.positive = true;
            temp_number.exponential = 0;
            return temp_number;
        }
    }

    vector<char> result_vector_reverse;
    bool lent = false;
    for(int i = first_sub.size() -1;i >= 0 ; i--)
    {
        int temp;
        lent ? temp = first_sub[i] - second_sub[i] - 1,lent = false : temp = first_sub[i] - second_sub[i];
        if(temp < 0)
        {
            lent = true;
            temp += 10;
        }
        result_vector_reverse.push_back((char)(temp + '0'));
    }
    bool trigger = false;
    for(int i = result_vector_reverse.size()-1; i >= 0; i--)
    {
        if(!trigger)
        {
            if( result_vector_reverse[i] != '0')
            {
                trigger = true;
                break;
            } else 
            {
                result_vector_reverse.pop_back();
                continue;
            }
        }
    }
    for(int i = 0; i < result_vector_reverse.size();i++)
    {
        temp_number.critical.push_back(result_vector_reverse[result_vector_reverse.size()-1-i]);
    }
    if(result_vector_reverse.size() == 0)
    {
        temp_number.critical = "0";
    }
    
    return temp_number;
}