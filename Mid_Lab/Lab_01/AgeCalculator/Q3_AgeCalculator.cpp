#include <iostream>

using namespace std;

int main()
{
int year_now, month_now, month_born, month_year, age_now, another_year,another_age, another_month;
cout << "Enter the current year then press RETURN.\n";
cin >> year_now;
cout <<"Enter the current month (a number from 1 to 12).\n";
cin >> month_now;
cout << "Enter your current age in years.\n";
cin >> age_now;
cout <<"Enter the month in which you were born (a number from 1 to 12).\n";
cin >> month_born;
cout << "Enter the year for which you wish to know your age.\n";
cin >> another_year;
cout<<"Enter the month in this year.\n";
cin>> month_year;

another_age = another_year - (year_now - age_now);
another_month = month_now + (month_born - month_year);


if (another_age >=0)
{ cout << "Your age in " << month_year << "/" << another_year << ": ";
cout << another_age << " years and " <<another_month << " months" << "\n";
} else
{ cout << "You weren't even born in ";

cout << another_year  << "!\n";
}

return 0;
}
