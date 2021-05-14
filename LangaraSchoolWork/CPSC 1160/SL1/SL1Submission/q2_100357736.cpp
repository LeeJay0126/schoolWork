// Jay Seung Yeon Lee
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  cout << "Enter a starting character: ";
  char startChar;
  cin >> startChar;

  cout << "Enter an ending character: ";
  char endChar;
  cin >> endChar;

  // Get a random character
  srand(time(0));
  char randomChar = (startChar + (rand() % (endChar - startChar + 1)));

  cout << "The random character between " << startChar << " and " 
       << endChar << " is " << randomChar << endl;

  return 0;
}
