/*
*Program Name: LargestInArray.java
*Author: Jay Seung Yeon Lee
*Date: March 09, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: returning largest double number in an array
public class LargestInArray{
	
	public static int max(int[] array){
		//method that compares all integer numbers in an array and returning the greatest one
		int temp = 0;
		
		for(int i = 0; i < array.length; i++){
			
			if(i == 0){
				temp = array[i];
			}else{
				if(temp < array[i]){
					temp = array[i];
				}
			}
		}
		return temp;
	}
	
	public static double max(double[] array){
		//method that returns biggest double number in an array 
		double temp = 0;
		
		for(int i = 0; i < array.length; i++){
			if(i == 0){
				temp = array[i];
			}else{
				if(temp < array[i]){
					temp = array[i];
				}
			}
		}
		return temp;
		
	}
	
	public static void main(String[] args){
		//main method
		
		Scanner input = new Scanner(System.in);
		//gets 5 integers from user
		System.out.print("Enter 5 integers: ");
		
		int[] intArray = new int[5];
		//initialize array
		for(int i = 0; i < intArray.length; i++){
			//assign each integer to the index
			intArray[i] = input.nextInt();
		}
		
		int intResult = max(intArray);
		// use max method to get the largest int 
		System.out.println("");
		System.out.println("Largest integer number in your array is: " + intResult);
		//display result
		System.out.print("Enter 5 double numbers: ");
		//get 5 double numbers
		double[] doubleArray = new double[5];
		//initialize
		for(int j = 0; j < doubleArray.length; j++){
			//assign each double to the index
			doubleArray[j] = input.nextDouble();
		}
		
		double result = max(doubleArray);
		//use max method
		System.out.println("");
		System.out.println("Largest double number in your array is: " + result);
		//display result
		
		
	}
	
}