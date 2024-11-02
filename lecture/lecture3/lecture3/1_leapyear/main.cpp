// Checking of leap years
#include <iostream>
using namespace std;

// Check leap years
bool is_leap_year(int year)
{
  bool leapyear;

  leapyear = ((year % 4 == 0) && (year  % 100 != 0))
             || (year % 400 == 0);

  return leapyear;
}

int main()
{
   int year;
   cout << "Please enter the year: ";
   cin >> year;

   if (is_leap_year(year))
     cout << year << " is a leap year!" << endl;
   else
     cout << year << " is not a leap year." << endl;
   return 0;
 }
