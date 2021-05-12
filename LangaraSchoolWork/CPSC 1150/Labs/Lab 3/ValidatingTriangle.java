/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 28, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//Purpose: Validating triangle length
public class ValidatingTriangle {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get the length of sides of a triangle
		System.out.print("Enter the first edge length: ");
		int firstEdge = input.nextInt();
		System.out.print("Enter the second edge length: ");
		int secondEdge = input.nextInt();
		System.out.print("Enter the third edge length: ");
		int thirdEdge = input.nextInt();
		
		// displaying string + true/false according to boolean
		System.out.print("Can edges " + firstEdge + "," + secondEdge + " and  " + thirdEdge + " form a triangle? " + ((firstEdge + secondEdge) > thirdEdge));
		
		
		
		
	}
}