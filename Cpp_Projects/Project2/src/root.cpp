#include "calculator.h"
nice_number root(nice_number number, nice_number exponential, map<string,nice_number> variable_map)
{

    nice_number loss;
    nice_number x_hat;
    nice_number y_hat;
    if(number.exponential%2 != 0)
    {
        number.exponential -= 1;
        number.critical.push_back('0');
    }

    x_hat.critical.push_back('1');
    int predicted_length = number.critical.size()/2;
    for(int i = 0; i < predicted_length; i++)
    {
        x_hat.critical.push_back('0');
    }
    nice_number goal_loss = {true,true,"1",-5};
    nice_number nice_one = {true,true,"1",0};
    nice_number nice_two = {true,true,"2",0};
    int i = 0;
    while (minus(loss,goal_loss).positive)
    {
        
        x_hat = add(dividePrecise(minus(number,power(x_hat,exponential)),multiply(exponential,power(x_hat,minus(exponential,nice_one))),variable_map),x_hat);
        y_hat = power(x_hat,nice_two);
        // cout << "x_hat :" << x_hat.critical << "e" << x_hat.exponential << endl;
        // cout << "y_hat :" << x_hat.critical << "e" << y_hat.exponential << endl;
        loss = minus(x_hat,number);
        // cout << "Loss :" << loss.critical << "e" << loss.exponential << endl;
        loss.positive = true;
        i++;
    }

    return x_hat;
}