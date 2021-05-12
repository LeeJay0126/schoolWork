/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 28, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//Purpose: To check user's bmi
public class CheckBMI {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get user's weight in kg and height in meters
		System.out.print("Enter your weight in kg: ");
		int weight = input.nextInt();
		System.out.print("Enter your height in meters: ");
		double height = input.nextDouble();
		//Calculate user's bmi
		double bmi = weight / Math.pow(height, 2);
		//Checking if user's input is greater than 0
		if (weight <= 0 || height <= 0){
			
			System.out.print("Your height or weight must be greater than 0. ");
			
		}else {
			//displaying according to user's bmi if user's height or weight is not 0.
			if(bmi > 25){
				
				System.out.print("You are overweight.");
				
			}else if(bmi > 20){
				
				System.out.print("Your BMI is normal.");
				
			}else if(bmi < 20){
				
				System.out.print("You are underweight.");
				
			}
			
		}
		
	}
}