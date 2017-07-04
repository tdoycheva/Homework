#include<iostream>
using namespace std;

int deleteKdigit(int x, int k)
{
    int digit = 0;
    int y = 0;
    int currentDigit = 1;
    while (x != 0)
    {
        digit = x % 10;

        if (currentDigit != k)
        {
           y = y * 10 + digit;
        }

        x /= 10;
        currentDigit++;
    }

    while (y != 0)
    {
        digit = y % 10;
        x = x * 10 + digit;
        y /= 10;
    }
return x;
}

int CountDigits(int a)
{
    int digits = 0;

    while(a > 0)
    {
        a /= 10;
        digits++;
    }
return digits;
}

bool CheckIfEqual(int firstNumber, const int secondNumber)
{
    int digits = CountDigits(firstNumber);
    for(int k = 1; k <= digits; ++k)
    {
         if(deleteKdigit(firstNumber,k) == secondNumber)
        {
            return 1;
        }

    }
return 0;
}


int main()
{
    unsigned int x, y;
    cin >> x >> y;

    switch(CheckIfEqual(x, y)){
        case 1: cout << "Yes" << '\n';
                break;
        case 0: cout << "No" << '\n';
                break;
        default: cout << "No" << '\n';
                break;
    }


return 0;
}
