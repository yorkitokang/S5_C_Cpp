#include <iostream>
#include <regex>
#include <string>
#include <math.h>
using namespace std;
int main(int argc, char *numbers[])
{
    if(argc != 3)
    {
        cout << "You can only enter two numbers" << endl;
        return 0;
    }
    string number_one = numbers[1];
    string number_one_critical;
    long long number_one_tens = 0;
    string number_two = numbers[2];
    string number_two_critical;
    long long number_two_tens = 0;
    bool one_positive = true;
    bool two_positive = true;
    regex positive_int_reg("[+]?[1-9][0-9]*");
    regex zero_reg("[+--]?[0][.]?[0]*");
    regex negative_int_teg("[-][1-9][0-9]*");
    regex positive_float_reg("[+]?[1-9][0-9]*[.][0-9]+");
    regex negative_float_reg("[-][1-9][0-9]*[.][0-9]+");
    regex positive_scientific_float("[+]?[1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
    regex negative_scientific_float("[-][1-9][0-9]*[.]?[0-9]*[Ee][-][0-9]+");
    regex positive_scientific_exp("[+]?[1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
    regex negative_scientific_exp("[-][1-9][0-9]*[.]?[0-9]*[Ee][+]?[0-9]+");
    if(regex_match(number_one,positive_int_reg))
    {
        //cout<<"positive int"<<endl;
        if (number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        number_one_critical = number_one;
    }else if(regex_match(number_one,zero_reg))
    {
        //cout<<"zero_reg"<<endl;
        number_one_critical = "0";
    }else if(regex_match(number_one,negative_int_teg))
    {
        //cout<<"negative_int_teg"<<endl;
        number_one.erase(0,1);
        number_one_critical = number_one;
        one_positive = false;
    }else if(regex_match(number_one,negative_float_reg))
    {
        //cout<<"negative_float_reg"<<endl;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                number_one_tens = -(number_one.length() - i - 1);
                number_one.erase(i,1);
            }
        }
        number_one_critical = number_one;
        one_positive = false;
    }else if(regex_match(number_one,positive_float_reg))
    {
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                number_one_tens = -(number_one.length() - i - 1);
                number_one.erase(i,1);
            }
        }
        number_one_critical = number_one;
        //cout<<"positive_float_reg"<<endl;
    }else if(regex_match(number_one,positive_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position+1, number_one.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        
        //cout<<"positive_scientific_float"<<endl;
    }else if(regex_match(number_one,negative_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position+1, number_one.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        one_positive = false;
        //cout<<"negative_scientific_float"<<endl;
    }else if(regex_match(number_one,positive_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_one[0] == '+')
        {
            number_one.erase(0,1);
        }
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                if(number_one[i+1] == '+')
                {
                    number_one.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position + 1, number_one.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        //cout<<"positive_scientific_exp"<<endl;
    }else if(regex_match(number_one,negative_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_one.erase(0,1);
        for(int i = 0; i < number_one.length(); i++)
        {
            if(number_one[i] == '.')
            {
                dot_position = i;
            }
            if(number_one[i] == 'e' || number_one[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_one_tens = - (e_position - dot_position - 1);
                }
                if(number_one[i+1] == '+')
                {
                    number_one.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_one.substr(e_position + 1, number_one.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_one_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_one_tens << endl;
        }
        if (dot_position != 0)
        {
            number_one.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_one_critical = number_one.substr(0, e_position - 1);
        }else
        {
            number_one_critical = number_one.substr(0, e_position);
        }
        one_positive = false;
        //cout<<"negative_scientific_exp"<<endl;
    }else{
        cout << "The input cannot be interpret as numbers!" << endl;
        return 0;
    } 
    //cout << number_one_critical << endl;
    //cout << number_one_tens << endl;


    if(regex_match(number_two,positive_int_reg))
    {
        //cout<<"positive int"<<endl;
        if (number_two[0] == '+')
        {
            number_two.erase(0,1);
        }
        number_two_critical = number_two;
    }else if(regex_match(number_two,zero_reg))
    {
        //cout<<"zero_reg"<<endl;
        number_two_critical = "0";
    }else if(regex_match(number_two,negative_int_teg))
    {
        //cout<<"negative_int_teg"<<endl;
        number_two.erase(0,1);
        number_two_critical = number_two;
        two_positive = false;
    }else if(regex_match(number_two,negative_float_reg))
    {
        //cout<<"negative_float_reg"<<endl;
        number_two.erase(0,1);
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                number_two_tens = -(number_two.length() - i - 1);
                number_two.erase(i,1);
            }
        }
        number_two_critical = number_two;
        two_positive = false;
    }else if(regex_match(number_two,positive_float_reg))
    {
        if(number_two[0] == '+')
        {
            number_two.erase(0,1);
        }
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                number_two_tens = -(number_two.length() - i - 1);
                number_two.erase(i,1);
            }
        }
        number_two_critical = number_two;
        //cout<<"positive_float_reg"<<endl;
    }else if(regex_match(number_two,positive_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_two[0] == '+')
        {
            number_two.erase(0,1);
        }
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                dot_position = i;
            }
            if(number_two[i] == 'e' || number_two[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_two_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_two.substr(e_position+1, number_two.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_two_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_two_tens << endl;
        }
        if (dot_position != 0)
        {
            number_two.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_two_critical = number_two.substr(0, e_position - 1);
        }else
        {
            number_two_critical = number_two.substr(0, e_position);
        }
        
        //cout<<"positive_scientific_float"<<endl;
    }else if(regex_match(number_two,negative_scientific_float))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_two.erase(0,1);
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                dot_position = i;
            }
            if(number_two[i] == 'e' || number_two[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_two_tens = - (e_position - dot_position - 1);
                }
                break;
            }
        }
        e_string = number_two.substr(e_position+1, number_two.length() - e_position - 1);
        for (int i = 1; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_two_tens -= (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_two_tens << endl;
        }
        if (dot_position != 0)
        {
            number_two.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_two_critical = number_two.substr(0, e_position - 1);
        }else
        {
            number_two_critical = number_two.substr(0, e_position);
        }
        two_positive = false;
        //cout<<"negative_scientific_float"<<endl;
    }else if(regex_match(number_two,positive_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        if(number_two[0] == '+')
        {
            number_two.erase(0,1);
        }
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                dot_position = i;
            }
            if(number_two[i] == 'e' || number_two[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_two_tens = - (e_position - dot_position - 1);
                }
                if(number_two[i+1] == '+')
                {
                    number_two.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_two.substr(e_position + 1, number_two.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_two_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_two_tens << endl;
        }
        if (dot_position != 0)
        {
            number_two.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_two_critical = number_two.substr(0, e_position - 1);
        }else
        {
            number_two_critical = number_two.substr(0, e_position);
        }
        //cout<<"positive_scientific_exp"<<endl;
    }else if(regex_match(number_two,negative_scientific_exp))
    {
        int dot_position = 0;
        int e_position;
        string e_string;
        number_two.erase(0,1);
        for(int i = 0; i < number_two.length(); i++)
        {
            if(number_two[i] == '.')
            {
                dot_position = i;
            }
            if(number_two[i] == 'e' || number_two[i] == 'E')
            {
                e_position = i;
                if (dot_position != 0)
                {
                    number_two_tens = - (e_position - dot_position - 1);
                }
                if(number_two[i+1] == '+')
                {
                    number_two.erase(i+1,1);
                }
                break;
            }
        }
        e_string = number_two.substr(e_position + 1, number_two.length() - e_position);
        for (int i = 0; i < e_string.length(); i++)
        {
            //cout << e_string << endl;
            number_two_tens += (e_string[i]-'0')*pow(10, e_string.length() - i -1);
            //cout << number_two_tens << endl;
        }
        if (dot_position != 0)
        {
            number_two.erase(dot_position,1);//前面设置了过滤器使得.开头不得通过
            number_two_critical = number_two.substr(0, e_position - 1);
        }else
        {
            number_two_critical = number_two.substr(0, e_position);
        }
        two_positive = false;
        //cout<<"negative_scientific_exp"<<endl;
    }else{
        cout << "The input cannot be interpret as numbers!" << endl;
        return 0;
    } 
    //cout << number_two_critical << endl;
    //cout << number_two_tens << endl;
    // calculate critical
    int sum_critical[10000];
    for(int i = 0; i < 100; i++)
    {
        sum_critical[i] = 0;
    }

    for (int i = 0; i < number_one_critical.length(); i++)
    {
        int temp = 0;
        for (int j = 0; j < number_two_critical.length(); j++)
        {
            //cout << number_one_critical[i]-'0' << number_two_critical[j]-'0'<< endl;
            //cout << (number_one_critical[i]-'0') * (number_two_critical[j]-'0') + temp << endl;
            sum_critical[i+j] += (number_one_critical[number_one_critical.length() - i - 1]-'0') * (number_two_critical[number_two_critical.length() - j - 1]-'0') + temp;
            temp = sum_critical[i+j]/10;
            sum_critical[i+j] %= 10 ;
        }
        sum_critical[i+number_two_critical.length()] += temp;
    }
    // calculate tens
    string sum;
    int index = number_one_critical.length() + number_two_critical.length();
    while(sum_critical[index]==0 && index>0) index--;
    //cout << index << endl;
    for(int i=index; i >=0; i--)
    {
        sum.append(to_string(sum_critical[i]));
    }
		

    //cout << sum << endl;
    long long final_tens = number_one_tens + number_two_tens;
    if(final_tens < 0 && final_tens >= -10)
    {
        //cout<< sum.length()<<endl;
        sum.insert(sum.length()+final_tens,1,'.');
        for(int i = sum.length();;i--)
        {
            if (sum[sum.length()-1] == '0')
            {
                sum.erase(sum.length()-1);
                continue;
            }
            if (sum[sum.length()-1] == '.')
            {
                sum.erase(sum.length()-1);
                break;
            }
            break;
        }
    }else if(final_tens < -10)
    {
        long long sum_length = sum.length();
        sum.insert(1,1,'.');
        for(int i = sum.length();;i--)
        {
            if (sum[sum.length()-1] == '0')
            {
                sum.erase(sum.length()-1);
                if (sum[sum.length()-2] == '.')
                {
                    break;
                }
                continue;
            }
            break;
        }
        sum.insert(sum.length(), 1, 'e');
        sum.insert(sum.length(), 1, '-');
        final_tens += sum_length-1;
        string final_ten_string = to_string(abs(final_tens));
        //cout << int(log10(abs(final_tens))) << endl;
        for (int i = 0; i < (int)log10(abs(final_tens))+1; i++)
        {
            int a = pow(10,i+1);
            sum.append(to_string(final_ten_string[i]-'0'));
        }
    }else if (final_tens > 0)
    {
        long long sum_length = sum.length();
        sum.insert(1,1,'.');
        final_tens += sum_length-1;
        for(int i = sum.length();;i--)
        {
            if (sum[sum.length()-1] == '0')
            {
                sum.erase(sum.length()-1);
                if (sum[sum.length()-2] == '.')
                {
                    break;
                }
                continue;
            }
            break;
        }
        sum.insert(sum.length(),1,'e');
        sum.insert(sum.length(),1,'+');
        string final_ten_string = to_string(abs(final_tens));
        for (int i = 0; i < (int)log10(final_tens)+1; i++)
        {
            int a = pow(10,i+1);
            sum.append(to_string(final_ten_string[i]-'0'));
        }
    }
    if(one_positive^two_positive)
    {
        sum.insert(0,1,'-');
    }
    cout << numbers[1] <<" * "<< numbers[2]<< " = " << sum << endl;
}
