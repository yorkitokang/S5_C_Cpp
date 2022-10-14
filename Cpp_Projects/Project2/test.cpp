#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    regex test_reg("(.+)");
    regex squareRoot_regex("[s][q][r][t][(](.+)[)]");
    cout << "hello" << endl;
    string n ;
    cin >> n;
    if(regex_match(n,squareRoot_regex))
    {
        cout << "yes!";
    } else {
        cout << "No!";
    }
}