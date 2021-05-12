/*
*Program Name: AllVowels.java
*Author: Jay Seung Yeon Lee
*Date: February 27, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: printing 4 random vowels
public class AllVowels {
	//main method
	public static void main(String[] args){
	
		String output = "";
		int randomNumber;
		int vowelCount = 0;
		// declare variables and set vowel count to 0
		while(vowelCount < 4){
		// when there are 4 vowels, loop stops
			randomNumber = (int)(Math.random()*(24-1+1)+1);
			
			switch(randomNumber){
			//if out of 24 characters, characters match vowel case, it adds to the output and adds 1 to the vowel count
				case 0: 
					output += "a ";
					vowelCount++;
				break;
				case 1:
					output += "e ";
					vowelCount++;
				break;
				case 2:
					output += "i ";
					vowelCount++;
				break;
				case 3:
					output += "o ";
					vowelCount++;
				break;
				case 4:
					output += "u ";
					vowelCount++;
				break;
				default:
					//defines all other letters
				continue;	
				
			}
			
		}
		
		System.out.print(output);
		//display result
	}
}