/*
*Program Name: KilogramsAndPounds.java
*Author: Jay Seung Yeon Lee
*Date: February 8, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: to find a person's middle name
public class KilogramsAndPounds {
	//main method
	public static void main(String[] args){
	
		final double KILOGRAM_TO_POUND = 2.200;
		//formula for pounds > kilo = pounds / 2.2
		int i = 0;
		int kg = 1;
		
		//print heading for the first column
		System.out.println("kilograms		pounds		|		pounds		kilograms");
		System.out.println("-------------------------------------------------------------------------------------------------");

		
		while(i < 10){
		//loop will be executed 10 times
			double kiloInLoop = 1+(i*2);
			double poundInLoop = 20 + (i*5);
			double kilToPound = (kiloInLoop * KILOGRAM_TO_POUND);
			double poundToKg = (poundInLoop/2.2);
			//formula for increasing variables within the loop
			System.out.printf("	%.0f		%.3f		|		%.0f		%.3f", kiloInLoop,kilToPound,poundInLoop,poundToKg);
			System.out.println(" ");
			//print each columns and space after each loop execution
			i++;
			//+1 i every end of loop execution
		}
		
		
	}
	
}