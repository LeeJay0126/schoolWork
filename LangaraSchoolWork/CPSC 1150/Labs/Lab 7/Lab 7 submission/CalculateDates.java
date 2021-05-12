/*
*Program Name: CountVowels.java
*Author: Jay Seung Yeon Lee
*Date: March 01, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: printing 4 random vowels
public class CalculateDates{
	
	public static int isInputValid(int day,int month,int year){
		//method validating if input is valid
		if(day > 0 && month <= 12 && month >= 1 && year > 0){
			// if these requirements are met, return 1, else return 0
			return 1;
		}else{
			return 0;
		}
		
	}
	
	public static String monthName(int month){
		//method returning month name using switch method
		switch (month){
			
			case 1: 
				return "January";
			case 2:
				return "February";
			case 3:
				return "March";
			case 4: 
				return "April";
			case 5:
				return "May";
			case 6:
				return "June";
			case 7:
				return "July";
			case 8:
				return "August";
			case 9:
				return "September";
			case 10:
				return "October";
			case 11:
				return "November";
			case 12:
				return "December";
			default:
				return "";
			
		}
		
		
	}
	
	public static int isLeapYear(int Year){
			//method calculating if year is a leap year
			if(Year % 4 == 0){
				if(Year % 100==0){
					if(Year%400==0){
						return 1;
					}else{
						return 0;
					}
				}else{
					return 1;
				}
			}else{
				return 0;
			}
			
		}
		
	public static int getDaysInMonth(int Month,int Year,int leap){
			// method getting days in a month 
		int days = 0;
		switch(Month){
				
			case 1:
				days = 31;
				break;
			case 2: 
				//calculates the day differently if its a leap year
				if(leap == 0){
					days = 28;
				}else if(leap == 1){
					days = 29;
				}
				break;
			case 3: 
				days = 31;
				break;
			case 4:
				days = 30;
				break;
			case 5: 
				days =  31;
				break;
			case 6:
				days = 30;
				break;
			case 7:
				days = 31;
				break;
			case 8: 
				days = 31;
				break;
			case 9:
				days = 30;
				break;
			case 10:
				days = 31;
				break;
			case 11: 
				days = 30;
				break;
			case 12:
				days = 31;
				break;
			default: 
				return 0;
				
		}
		return days;
			
	}
	
	public static int calculateTotalDaysPassed(int Month,int Day,int Year,int Leap){
		// calculate total days passed since first day of the year
		Leap = isLeapYear(Year);
		int totalDaysPassed = 0;
		int remainderDays;
		for (int i = 1; i <Month; i++){
			//Calculating all the days in the previous months
			totalDaysPassed += getDaysInMonth(i, Year, Leap);
		}
		totalDaysPassed += Day;
		//adds the day to the days in the previous months
		return totalDaysPassed;
		
	}
	
	public static void printNextDay(int Month,int Day,int Year,int Leap){
		//printing next day
		Leap = isLeapYear(Year);
		int daysOfMonth = getDaysInMonth(Month,Year,Leap); 
		if(Month == 12 && Day == 31){
			//if it's the end of the the year prints the next year and set month and day to 1
			Year++;
			Month = 1;
			Day = 1;
		}else{
			if(Day == daysOfMonth){
				//if it's end of the month month moves on and day sets to 1
				Month++;
				Day = 1;
			}else{
				//otherwise day just goes up by 1
				Day++;
			}
		}
		String currentMonth = monthName(Month);
		//prints result
		System.out.printf("%s %s %d , %d", "The next day is ", currentMonth, Day, Year); 
	}
	
	public static void main(String[] args){
		//main method
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the month in integer (ex. January is 1): ");
		int month = input.nextInt();
		System.out.print("Enter the year: ");
		int year = input.nextInt();
		System.out.print("Enter the days: ");
		int days = input.nextInt();
		
		int validator = isInputValid(days,month,year);
		if(validator == 1){
			
			int leap = isLeapYear(year);
			int totalDays = calculateTotalDaysPassed(month,days,year,leap);
			
			System.out.println(totalDays + " have passed since the beginning of the year.");
			printNextDay(month, days, year, leap);
		}else{
			System.out.print("The input is invalid");
		}
		
	}
}