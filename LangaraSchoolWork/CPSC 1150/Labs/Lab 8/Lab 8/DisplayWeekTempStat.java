/*
*Program Name: DisplayWeekTempStat.java
*Author: Jay Seung Yeon Lee
*Date: March 09, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: display weekly temperature stats
public class DisplayWeekTempStat{
	
	public static double average(int[] array){
		//method showing average temp of the week
		int sum = 0;
		for(int i = 0; i < array.length; i++){
		//loops through the array and get the sum of all days
			sum += array[i];
			
		}
		
		double average = sum / array.length;
		//divide into days to get the average temp
		return average;
		
	}
	
	public static int hottest(int[] array){
		//method finding the hottest day of the week
		int temp = 0;
		
		for(int i = 0; i < array.length; i++){
		//compare the hottest temp to the rest of the array 
			if(i == 0){
				temp = array[i];
			}else{
				if(array[i] > temp){
					temp = array[i];
				}
			}
			
		}
		
		return temp;
		
	}
	
	public static int coldest(int[] array){
		//method finding the coldest day of the week
		int temp = 0;
		
		for(int i = 0; i < array.length; i++){
			
			if(i == 0){
				temp = array[i];
			}else{
				if(array[i] < temp){
					temp = array[i];
				}
			}
			
		}
		
		return temp;
	}
	
	public static int[] searchTemp(int[] temp, int key){
		//look for index of an array that matches the coldest / hottest days
		int dimensionCounter = 0;
		
		for(int i = 0; i <temp.length; i++){
			
			if(temp[i] == key){
				dimensionCounter++;
			}
			
		}
		
		
		int[] newTemp = new int[dimensionCounter];
		int m = 0;
		for(int i = 0; i <temp.length; i++){
			
			if(temp[i] == key){
				newTemp[m] = i;
				m++;
			}
			
		}
		
		return newTemp;
		
	}
	
	public static void main(String[] args){
		// main method
		Scanner input = new Scanner(System.in);
		
		System.out.print("What is the daily highest temperature in a week? ");
		
		int[] array = new int[7];
		
		for(int i = 0; i < array.length; i++){
			array[i] = input.nextInt();
		}
		
		int coldestTemp = coldest(array);
		int hottestTemp = hottest(array);
		double average = average(array);
		
		int[] hottestDays = searchTemp(array, hottestTemp);
		int[] coldestDays = searchTemp(array, coldestTemp);
		
		String coldestDayString = "";
		String hottestDayString = "";
		
		for(int j = 0; j < coldestDays.length; j++){
			// printing days of the week according to switch statement for coldest days
			int p = coldestDays[j];
			
			switch(p){
				
				case 1:
						coldestDayString += "Monday ";
					break;
				case 2:
						coldestDayString += "Tuesday ";
					break;
				case 3:
						coldestDayString += "Wednesday ";
					
					break;
				case 4:
					
						coldestDayString += "Thursday ";
					
					break;
				case 5:
					
						coldestDayString += "Friday ";
					
					break;
				case 6:
					
						coldestDayString += "Saturday ";
					
					break;
				case 0:
					
						coldestDayString += "Sunday ";
					
					break;
			}
			
		}
		
			for(int q = 0; q < hottestDays.length; q++){
			
			int p = hottestDays[q];
			// printing days of the week according to switch statement for hottest days
			switch(p){
				
				case 1:
					
						hottestDayString += "Monday ";
					
					break;
				case 2:
					
						hottestDayString += "Tuesday ";
					
					break;
				case 3:
					
						hottestDayString += "Wednesday ";
					
					break;
				case 4:
					
						hottestDayString += "Thursday ";
					
					break;
				case 5:
					
						hottestDayString += "Friday ";
					
					break;
				case 6:
					
						hottestDayString += "Saturday, ";
					
					break;
				case 0:
					
						hottestDayString += "Sunday ";
					
					break;
			}
			
		}
		// display result
		System.out.println("The average temperature of the week is: " + average + " degree");
		System.out.println("The hottest temperature is " + hottestTemp + " degree");
		System.out.println("The coldest temperature is " + coldestTemp+ " degree");
		System.out.println("The hottest days are: " + hottestDayString);
		System.out.println("The coldest days are: " + coldestDayString);
		
	}
	
}