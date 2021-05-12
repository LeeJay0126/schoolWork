/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 25, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//Purpose: To calculate Bmi from user input 
public class CalculateBmi {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get user's weight in kg
		System.out.print("Please enter your weight in kg:\n");
		double weight = input.nextDouble();
		//Get users height in meters
		System.out.print("Please enter your height in meters:\n");
		double height = input.nextDouble();
		//Calculate user's bmi
		double bmi = weight/(height*height);
		//display the result
		System.out.printf("Your BMI is: "+ "%.2f", bmi);
		
		
		
	}
	
}