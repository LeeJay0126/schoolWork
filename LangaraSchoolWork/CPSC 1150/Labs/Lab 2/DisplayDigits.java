/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 25, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//Purpose: To display sum of digits of the user input
public class DisplayDigits {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get a number between 0 and 999
		System.out.print("Please enter a number between 0 and 999: \n");
		int threeDigits = input.nextInt();
		//seperating each digit 
		int third = threeDigits % 10;
		threeDigits = threeDigits / 10;
		int second = threeDigits % 10;
		threeDigits = threeDigits /10;
		int first = threeDigits % 10;
		//calculating the sum of each digits
		int sum = first + second + third;
		//display the result
		System.out.print("The three digits in the number are: "+first + " " + second + " " + third + "\n"); 
		System.out.print("The sum of the three digits is: " + sum);
		
	}
}