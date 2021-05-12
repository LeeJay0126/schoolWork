/*
*Program Name: DaysInMonth.java
*Author: Jay Seung Yeon Lee
*Date: February 2, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: to check the days in a month and to see if it is a leap year 
public class DaysInMonth {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
	        // get the year and month from user
		System.out.print("Enter the year : ");
		int year = input.nextInt();
		System.out.print("Enter the month (lower case) : ");
		String month = input.next();
		//by using switch method, this program will determine what will be displayed depending on user input
		switch (month){
			//these months will return 31 days 
			case "january" :
				System.out.println("There is 31 days in month of " + month);
			break;
			case "march":
				System.out.println("There is 31 days in month of " + month);
			break;
			case "may":
				System.out.println("There is 31 days in month of " + month);
			break;
			case "july":
				System.out.println("There is 31 days in month of " + month);
			break;
			case "august":
				System.out.println("There is 31 days in month of " + month);
			break;
			case "october":
				System.out.println("There is 31 days in month of " + month);
			break;
			case "december":
				System.out.println("There is 31 days in month of " + month);
			break;
			
			//these months will return 30 days
			case "april":
				System.out.println("There is 30 days in month of " + month);
			break;
			case "june":
				System.out.println("There is 30 days in month of " + month);
			break;
			case "september":
				System.out.println("There is 30 days in month of " + month);
			break;
			case "november":
				System.out.println("There is 30 days in month of " + month);
			break;
			
			//for february, another calculation is used to check if it is a leap year
			case "february" :
				// if year is divided by 4 without remainder. If not, this year is not a leap year
				if((year % 4) == 0){
					//if year is divided evenly by 100. if not, it is a leap year.
					if(year % 100 == 0){
						//if the year is divisable evenly by 400, it is a leap year. if not it isn't
						if(year % 400 == 0){
							System.out.println(year + " is a leap year. Month of february has 29 days in this year.");
						}
						else{
							System.out.println(year + " is not a leap year. Month of february has 28 days in this year.");
						}
						break;
					}
					else{
						System.out.println(year + " is a leap year. Month of february has 29 days in this year.");
					}
					break;
				}
				else {
					System.out.println(year + " is not a leap year. Month of february has 28 days in this year.");
				}
			break;
			//if input is not valid
			default: 
				System.out.println("not a valid input");
		}
		
	}
}