/*
*Program Name: CaculateBmi.java
*Author: Jay Seung Yeon Lee
*Date: January 25, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/

import java.util.Scanner;
public class ComputeTriangleArea {
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//Get three points for a triangle
		System.out.print("Enter three points for a triangle: \n");
		//Get each points of a triangle seperately
		double x1 = input.nextDouble();
		double y1 = input.nextDouble();
		double x2 = input.nextDouble();
		double y2 = input.nextDouble();
		double x3 = input.nextDouble();
		double y3 = input.nextDouble();
		//calculating sides of a triangle
		double side1 = Math.sqrt(Math.pow(x1 -x2, 2) + Math.pow(y1 - y2, 2));
		double side2 = Math.sqrt(Math.pow(x1 -x3, 2) + Math.pow(y1 - y3, 2));
		double side3 = Math.sqrt(Math.pow(x2 -x3, 2) + Math.pow(y2 - y3, 2));
		double s = (side1 + side2 + side3)/2;
		//calculating area
		double area = Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
		//display the result
		System.out.printf("The area of the triangle is: " +"%.2f", area);
		
	}
}