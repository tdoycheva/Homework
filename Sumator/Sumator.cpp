
#include<iostream>
using namespace std;

const int maxDigitsForNumber = 6;

bool IsNumberInCorrectSystem(long n, int k)
{
	int arr[maxDigitsForNumber];
	for (int i = 0; i < maxDigitsForNumber; ++i)
	{
		arr[i] = n % 10;
		if (arr[i] > k || arr[i] == k) return false;
		else n = n/10;
	}
return true;
}

int toDecimal(long n, int k)
{
	long rest, base = 1, newnum = 0;
	while (n > 0)
	{
		rest = n % 10;
		n = n / 10;
		newnum = newnum + rest*base;

		base *= k;
	}
	return newnum;
}
int changeSumSystem(long n, int k)
{
	long remainder;
	int newnum = 0;
	int base = 1;
	while (n > 0)
	{
		remainder = n % k;
		newnum = newnum + remainder * base;
		n = n / k;
		base *= 10;
	}
	return newnum;
}

int main()
{
	long n, m, sum;
	int k;
	cin >> n >> m >> k;
	if (IsNumberInCorrectSystem(m, k) == false)
    {
        cout << "Bad input data!";
    }
	else if (IsNumberInCorrectSystem(n, k) == false)
    {
        cout << "Bad input data!";
    }
	else
	{
		sum = toDecimal(n, k) + toDecimal(m, k);
		cout << changeSumSystem(sum, k) << '\n';
	}
}
