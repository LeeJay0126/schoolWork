// Jay Seung Yeon Lee
#include <iostream>
using namespace std;
const int TOTALGRADES = 10;	// TOTALGRADES is the maximum size of the array

// function prototypes
void getData(int array[], int& sizeOfArray); // will read values into the array
float findAverage(const int array[], int sizeOfArray); // compute avg 

int main(){
int grades[TOTALGRADES];	// defines an array that holds up to 10 integers
int numberOfGrades = 0;	// the number of grades read 
float average;	               // the average of all grades read

getData(grades, numberOfGrades); // getData is called to read the grades into
				   // the array and store how many grades there
				   // are in numberOfGrades 
average = findAverage(grades, numberOfGrades);
cout << endl << "The average of the	" << numberOfGrades
<< " grades read in is "  << average << "." << endl << endl;

return 0;
}



//***********************************************************************
//	getData
//
// task:	This function inputs and stores data in the grades array.
// data in:	none (the parameters contain no information needed by the getData function)
// data out:   an array containing grades and the number of grades
//***********************************************************************


void getData(int array[], int& sizeOfArray)
{
int pos = 0;	// array index which starts at 0
int grade;	// holds each individual grade read in


cout << "Please input a grade or type -99 to stop: " << endl;

	for(pos = 0; pos < 10; pos++){
	    cin >> grade;
	    if(grade == -99){
	        break;
	    }else{
	        array[pos] = grade;
	        sizeOfArray++;
	    }
	}

}

//****************************************************************************
//	findAverage
//
// task:	This function finds and returns the average of the values
// data in:	the array containing grades and the array size
// data returned: the average of the grades contained in that array
//****************************************************************************


float findAverage (const int array[], int sizeOfArray)
{
float sum = 0;	// holds the sum of all grades in the array

for(int i = 0; i < sizeOfArray; i++){
    sum += array[i];
}

sum /= sizeOfArray;

return sum;

}
