/*
*Program Name: DisplayDayOfWeek.java
*Author: Jay Seung Yeon Lee
*Date: February 2, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: displaying days of week depending on user input
public class DisplayDayOfWeek {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//get an integer between 0 and 6
		System.out.print("Enter an integer between 0 and 6 : ");
		int days = input.nextInt();
		//using switch method, I will assign each string to a case and display the result accordingly
		switch(days){
			
			case 0:
				System.out.println("Monday");
			break;
			
			case 1:
				System.out.println("Tuesday");
			break;
			
			case 2:
				System.out.println("Wednesday");
			break;
			
			case 3:
				System.out.println("Thursday");
			break;
			
			case 4:
				System.out.println("Friday");
			break;
			
			case 5:
				System.out.println("Saturday");
			break;
			
			case 6:
				System.out.println("Sunday");
			break;
			//if invalid input is entered (something that is not an integer or integer not between 0 and 6), it will display "Invalid Input"
			default:
				System.out.println("Invalid Input!");
				
		}	

		
	}
	
	
}