/*
*Program Name: DisplayCalendar.java
*Author: Jay Seung Yeon Lee
*Date: February 27, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: displaying a calander
public class DisplayCalendar {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter a year: ");
		int year = input.nextInt();
		System.out.print("Enter the first day of the year: ");
		int firstDayYear = input.nextInt();
		int monthCount = 1;
		int daysInMonths = 0;
		String Months = "";
		int firstDay;
		
		
		for (monthCount = 1; monthCount <= 12; monthCount ++){
			//loop that repeats it self 12 times (once per month)
			switch(monthCount){
				case 1:
					Months = "January";
					daysInMonths = 31;
					break;
				case 2:
					Months = "February";
					daysInMonths = 28;
					break;
				case 3:
					Months = "March";
					daysInMonths = 31;
					break;
				case 4:
					Months = "April";
					daysInMonths = 30;
					break;
				case 5:
					Months = "May";
					daysInMonths = 31;
					break;
				case 6:
					Months = "June";
					daysInMonths = 30;
					break;
				case 7:
					Months = "July";
					daysInMonths = 31;
					break;
				case 8:
					Months = "August";
					daysInMonths = 31;
					break;
				case 9:
					Months = "September";
					daysInMonths = 30;
					break;
				case 10:
					Months = "October";
					daysInMonths = 31;
					break;
				case 11:
					Months = "November";
					daysInMonths = 30;
					break;
				case 12:
					Months = "December";
					daysInMonths = 31;
					break;
			}	
			//display the month and year
			System.out.println("");
			System.out.println("		"+Months+"	"+year);
			System.out.println("____________________________________________________");
			
			//display the days
			System.out.println("Sun	Mon	Tue	Wed	Thu	Fri	Sat");
			
			//Pinting spaces between the days
			
			if(monthCount > 1){
				firstDayYear = (firstDayYear + daysInMonths)%7;
			}else{
				firstDayYear = firstDayYear;
			}
			
			for(int j = 1; j <= firstDayYear; j++){
				
				System.out.print("	");
			}
			//printing the days (in a month)
			for (int k = 1; k <= daysInMonths; k++){
				
				if(firstDayYear % 7 ==0){
					
					System.out.println();
				}
				System.out.printf("%3d	", k);
				firstDayYear +=1;
				}
			}
		}
		
	}
