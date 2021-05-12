/*
*Program Name: CheckerBoard.java
*Author: Jay Seung Yeon Lee
*Date: March 22, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: Generating checker board
public class lab12{
	
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		
		int[] array = new int[10];
		for(int i = 0; i < 10; i++){
			array[i] = i;
		}
		System.out.print("Enter your value: ");
		int value = input.nextInt();
		
		int index = iterativeBinarySearch(array, value);
		
		if(index == -1){
			
			System.out.print("Value you entered was not found in the array.");
			
		}else{
			
			System.out.print(value + " is stored in " + index + " index");
			
		}
		
		recursiveBinarySearch(array, value, 0, array.length-1); 
		
	}
	
	public static int iterativeBinarySearch(int[] arr, int value){
		
		int middle = 0;
		int left = 0;
		int right = arr.length-1;
		
		while(left <= right){
			
			middle = (left+right)/2;
			if(value < arr[middle]){
				right = middle-1;
			}else if(value > arr[middle]){
				left = middle+1;
			}else{
				return middle;
			}
			
		}
		return -1;
	}
	
	public static int recursiveBinarySearch(int[] arr, int value,int left, int right){
		
		int middle = (left + right) / 2;	
		
		if(left >= right){
			if(arr[middle] == value){
				return middle;
			}else{
				return -1;
			}
		}else{
			
			if(value > arr[middle]){
				left = middle+1;
			}else if(value < arr[middle]){
				right = middle-1;
			}else if(arr[middle] == value){
				return middle;
			}
			
		}
		recursiveBinarySearch(arr, value, left, right);
	}
	
}