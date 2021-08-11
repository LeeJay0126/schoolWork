#include <iostream>
#include <string>
using namespace std;

int binarySearch(int array[], int number, int n);
int recursiveBinary(int array[], int number, int n, int left, int right);

int main(){
    
    int arr[] = {2,3,4,5,6,7,8,9,10};
    int number;
    //n is the size of the array. Because in C++, there is no array.length like java,
    //This step is necessary.
    int n = sizeof(arr) / sizeof(arr[0]);
    while(number != -99){
        cout << "Testing iterative Binary Search" << endl;
        cout << "Enter a number you want to find and enter -99 if you want to quit : " << endl;
        cin >> number;
        int result = binarySearch(arr,number,n);
        if(result != -1){
            cout << "Number you want to find is at index " << result  << endl;
        }else{
            cout <<"Number you want to find is not found" << endl;
        }
    }
    number = 0;
    while(number != -99){
        cout << "Testing recursive Binary Search" << endl;
        cout << "Enter a number you want to find and enter -99 if you want to quit : " << endl;
        cin >> number;
        int result = recursiveBinary(arr,number,n,0,n-1);
        if(result != -1){
            cout << "Number you want to find is at index " << result  << endl;
        }else{
            cout <<"Number you want to find is not found" << endl;
        }
    }
}

//recurisve binary search
int recursiveBinary(int array[], int number, int n, int left, int right){

    if(left > right){
        return -1;
    }

    int mid = (right + left) /2;

    if(array[mid] == number){
        return mid;
    }else if(array[mid] > number){
        recursiveBinary(array,number,n,left,mid-1);
    }else{
        recursiveBinary(array,number,n,mid+1,right);
    }

}

int binarySearch(int array[], int number, int n){
    //left is first index of the array
    int left = 0;
    //use variable n to get the size of the array. But note that since the first index of the array starts
    //at 0, when we want the last index of an array, we should use n-1.
    int right = n-1;
    //declare mid variable so that we don't declare it more than once in the while loop.
    int mid = 0;
    //Loop that iterates until left is greater than right, which should not happen.
    while(left <= right){
        // setting a new mid point
        mid = (left + right) /2;
        if(array[mid] == number){
            return mid;
        }else if(number > array[mid]){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return -1;
    
}