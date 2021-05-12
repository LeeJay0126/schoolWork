/*
*Program Name: FindMiddleName.java
*Author: Jay Seung Yeon Lee
*Date: February 8, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: to find a person's middle name
public class FindMiddleName {
	//main method
	public static void main(String[] args){
	
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter your first, middle, and last name seperated by single space: ");
		//Get user first, middle, last name
		String fullName =  input.nextLine();
		String[] nameArray = fullName.split(" ");
		//make an array of strings
		System.out.print(nameArray[1]);
		//print first index of the array
	}
	
}