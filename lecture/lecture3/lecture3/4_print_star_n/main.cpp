#include <iostream>

using namespace std;

// Print a pyramid of N lines of stars
void print_star_N (int numOfLines)
{
    for (int i = 1; i <= numOfLines; ++i)   {
       // Start a new line
	 cout << endl;
       // Print the space
       for (int j = 1; j <= numOfLines-i; ++j)
	   cout << ' ';
       // Print the stars
       for (int j = 1; j <= 2 * i - 1; ++j)
 	   cout << "*";
   }
}

int main()
{
    int n;
    cin >> n;
    print_star_N(n);
    return 0;
}
