/*Да се напише програма, която прочита от стандартния вход цяло положително число ​п​
и извежда на екрана, коефициентите пред различните степени в разлагането на двучлена (x+y)^n.
*/
#include <iostream>
using namespace std;

unsigned long long fact(int n)
{
unsigned long long f = 1;
for (int i = 1; i <= n; i++)
{
	f = f * i;
}
return f;
}

unsigned long long factorialNK(int n, int k)
{
    unsigned long long fact = 1;

    for(int i = n; i > n- k; --i)
    {
        fact = fact * i;
    }
    return fact;
}
unsigned long long binom(int n, int k)
{
	unsigned long long b;
	  if( k > n/2 )
      {
         b = factorialNK(n, n-k) / fact(n-k);
      }
      else
        {
        b = factorialNK(n, k) / fact(k);
        }

	return b;
}

int main()
{
	int n;
	cin >> n;


    for (int k = 0; k <= n; k++)
	{
		if (k != n)
        {
            cout << binom(n, k) << " ";
        }
        else
        {
            cout << binom(n, k) << '\n';
        }

	}
}
