ri#include<iostream>

using namespace std;

const int MAX_LENGTH = 100000;



void sortMod3(int* arr, unsigned int size)
{
    bool isFirstElement = true;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] % 3 == 0)
        {
           if(isFirstElement)
            {
                cout << arr[i];
                isFirstElement = false;
            }
            else
            {
                 cout << " " << arr[i];
            }
        }
    }
}

void sortMod1(int* arr, unsigned int size)
{
    bool isFirstElement = true;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] % 3 == 1)
        {


                 cout << " " << arr[i];

        }
    }
}



void sortOther(int* arr, unsigned int size)
{
    bool isFirstElement = true;
    for(int i = 0; i < size; ++i)
    {
        if((arr[i] % 3 != 1) && (arr[i] % 3 != 0))
        {

                 cout << " " << arr[i];
        }
    }
}

int main()
{
    unsigned int n;
    cin >> n;
    int a[MAX_LENGTH];

    int size = n;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sortMod3(a, size);
    sortMod1(a, size);
    sortOther(a, size);

}
