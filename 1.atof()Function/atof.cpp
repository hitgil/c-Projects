#include <iostream>
#include <string.h>

using namespace std;

bool isspace(char ch)
{
    bool flag = false;
    if (ch == ' ')
    {
        flag = true;
    }
    return flag;
}

bool isdigit(char ch)
{
    bool flag = false;
    if ((ch - '0') >= 0 && (ch - '0') <= 9)
    {
        flag = true;
    }
    return flag;
}

double atof(char *ch)
{
    int index = 0;
    double value = 0.000;
    double adder = 0.00;
    for (index = 0; isspace(ch[index]); ++index)
        ;
    for (value = 0.0; isdigit(ch[index]); ++index)
    {
        value = value * 10.0 + (ch[index] - '0');
    }
    if (ch[index] == '.')
    {
        ++index;
        int a = 1;
        for (adder = 0.0; isdigit(ch[index]); ++index)
        {
            a = a * 10;
            adder = adder * 10.0 + (ch[index] - '0');
        }
        adder = (double)adder / a;
    }
    value = value + adder;
    return value;
}

int main()
{
    char ch[50];
    cout << "enter the character" << endl;
    cin.getline(ch, 50);
    cout << atof(ch);
    return 0;
}

