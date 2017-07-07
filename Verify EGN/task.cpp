#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

char checkMaleOrFemale(string egn)
{
        string ninthDigit = egn.substr(8, 1);
        char maleOrFemale;
        if(ninthDigit == "0" || ninthDigit == "2" ||
           ninthDigit == "4" || ninthDigit == "6" ||
           ninthDigit == "8")
        {
            maleOrFemale = 'M';
        }
        else
        {
            maleOrFemale = 'F';
        }
    return maleOrFemale;
}

bool inputIsValid(string input)
{
    if(input.length() != 10)
    {
        return false;
    }
    int yearToInt = atoi(input.substr(0, 2).c_str());
    int monthToInt = atoi(input.substr(2, 2).c_str());
    int dayToInt = atoi(input.substr(4, 2).c_str());
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear = (yearToInt % 4 == 0 && yearToInt % 100 != 0) || ( yearToInt % 400 == 0);

    if (!(monthToInt != 0 && dayToInt != 0))
    {
        return false;
    }

    if (yearToInt < 0 || monthToInt < 1 || dayToInt < 1)
    {
        return false;
    }

    if (monthToInt >= 13 && monthToInt <= 20)
    {
        return false;
    }
    else if (monthToInt >= 21 && monthToInt <= 32)
    {
        monthToInt = monthToInt - 20;
    }
    else if (monthToInt >= 33 && monthToInt <= 40)
    {
        return false;
    }
    else if (monthToInt >= 41 && monthToInt <= 52)
    {
        monthToInt = monthToInt - 40;
    }
    else if (monthToInt >= 53)
    {
        return false;
    }

    if (monthToInt == 2 && isLeapYear)
    {
        daysPerMonth[1] = 29;
    }

    if (dayToInt > daysPerMonth[monthToInt - 1])
    {
        return false;
    }

return true;
}

int main()
{
    string egn;
    cin >> egn;
    if(inputIsValid(egn))
    {
        int year = atoi(egn.substr(0, 2).c_str());
        int month = atoi(egn.substr(2, 2).c_str());
        string day = egn.substr(4, 2);
        string ninthDigit = egn.substr(8, 1);

        if(year >=0 && year <=99 && month >=1 && month < 13)
        {
            year = year + 1900;
            if(month >=1 && month <=9)
            {

                cout << day << "." << "0" << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
            else if(month >= 10 && month <= 12)
            {
                cout << day << "." << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
        }
        else if(year >=0 && year <=16 && month >= 41 && month <= 52)
        {
            month -= 40;
            year += 2000;
            if(month >=1 && month <=9)
            {
                cout << day << "." << "0" << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
            else if(month >= 10 && month <= 12)
            {
                cout << day << "." << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
        }
        else if(year >=0 && year <=99 && month >= 21 && month <= 32)
        {
            month -= 20;
            year += 1800;
            if(month >=1 && month <=9)
            {
                cout << day << "." << "0" << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
            else if(month >= 10 && month <= 12)
            {
                cout << day << "." << month << "." << year << " " << checkMaleOrFemale(egn) << '\n';
            }
        }
    }
    else
    {
        cout << "Bad input data!";
    }
}

