/*
Да се напише програма, която прочита от стандартния вход две естествени числа ​a​ и ​b​
 и извежда на екрана броя на срещанията на ​a​ в десетичния запис на ​b​. Например, ​a​ = 84
 се съдържа 3 пъти в ​b​ = 6845848456, ​a​ = 70 се съдържа 1 път в b​ = 8574704 и ​a​ = 55 се съдържа ​3​ пъти
 в ​b​ = 5555. Срещанията могат​ да се припокриват.
 */

#include<iostream>
using namespace std;


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

int pow(int n, int power)
{
    if(power == 0) return 1;
    else
    {
        return n*pow(n, power-1);
    }

}
int MeetingAinB(int a, int b)
{
    int digitsIna = CountDigits(a);
    int divisor = pow(10, digitsIna);
    int counter = 0;

    while(b > 0)
    {
        if((b % divisor) == a)
        {
            counter++;
        }
        b /= 10;
    }
    return counter;
}

int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout <<  MeetingAinB(a,b) << '\n';

return 0;
}




