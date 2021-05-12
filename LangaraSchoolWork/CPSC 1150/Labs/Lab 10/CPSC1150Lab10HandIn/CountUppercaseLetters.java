/*
*Program Name: CountUppercaseLetters.java
*Author: Jay Seung Yeon Lee
*Date: March 22, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: Count Uppercase Letter
public class CountUppercaseLetters{
	
	public static void main(String[] args){
		//main method
		int count = 0;
	
		for(int i=0; i < args.length; i++){
			for(int j = 0; j < args[i].length(); j++){
				//checks each character in the string if it's betwee A and Z
				char index = args[i].charAt(j);
				if(index >= 'A' && index <= 'Z'){
					//if character is between A and Z count ++
					count++;
				
				}
			}
		}
		//display result (count)
		System.out.print("The total number of uppercase letters is " + count);
	}
	
}