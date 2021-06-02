#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    string filename = "tmp.txt";
    string fn, ln ;
    ofstream file_out;

    file_out.open(filename, std::ios_base::app); // the 2nd argument is for append mode
    cout << "Enter the firstname : ";
    cin >> fn ;
    file_out << fn << ", " ;
    
    
    cout << "Enter the lastname : ";
    cin >> ln ;
    file_out << ln << endl;
  
    cout << "Done !" << endl;

    return 0;
}