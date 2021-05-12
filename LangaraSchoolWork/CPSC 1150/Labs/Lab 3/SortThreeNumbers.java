/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 28, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//Purpose: To sort three numbers from smallest to largest
public class SortThreeNumbers{
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get three numbers 
		System.out.print("Enter the first integer: ");
		int firstInt = input.nextInt();
		System.out.print("Enter the second integer ");
		int secondInt= input.nextInt();
		System.out.print("Enter the third integer ");
		int thirdInt = input.nextInt();
		//Setting up variables to store #int
		int temp = 0;
		int temp1 = 0;
		int temp2 = 0;
		//Comparing first and second int and replace if first > second
		if(firstInt > secondInt){
		
			temp = firstInt;
			firstInt = secondInt;
			secondInt = temp;
			
		}
		//Comparing second and third int and replace if second > third
		if(secondInt > thirdInt){
			
			temp1 = secondInt;
			secondInt = thirdInt;
			thirdInt = temp1;
			
		}
		//Comparing first and second int again in case second int (third int originally) is greater than first int.
		if(firstInt > secondInt){
		
			temp2 = firstInt;
			firstInt = secondInt;
			secondInt = temp2;
			
		}
		//display result.
		System.out.print("Integers from smallest to largers: " + firstInt + " " + secondInt + " " + thirdInt);
		
		
		
	}
}