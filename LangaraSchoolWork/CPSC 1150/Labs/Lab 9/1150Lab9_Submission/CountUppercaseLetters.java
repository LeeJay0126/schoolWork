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
		
		int count = 0;
	
		for(int i=0; i < args.length; i++){
			for(int j = 0; j < args[i].length(); j++){
				char index = args[i].charAt(j);
				if(index >= 'A' && index <= 'Z'){
				
					count++;
				
				}
			}
		}
		System.out.print("The total number of uppercase letters is " + count);
	}
	
}