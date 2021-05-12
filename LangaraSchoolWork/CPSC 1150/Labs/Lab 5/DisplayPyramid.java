/*
*Program Name: DisplayPyramid.java
*Author: Jay Seung Yeon Lee
*Date: February 8, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: to find a person's middle name
public class DisplayPyramid{
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//get an integer between 1 and 15
		System.out.print("Enter a number between 1 and 15: ");
		int inputNum = input.nextInt();
		int rowCount =1;
		//loop determining how many rows will be in the pyramid using user input
		for(int i = 0; i < inputNum+1; i++){
			if(i > 0){
			//if input is greater than 0
				for(int j = inputNum; j >=  2; j--){
					if(j > i){
						System.out.print("  ");
						//adds a space if current number in the row is smaller than the total number of rows
					}else{
						System.out.print(j + " ");
						//prints j and space
					}
				}
				for(int l = i; l <= i; l++){
					System.out.print(1);
					//prints 1 every row
				}
			
				for(int k = 2; k <= i; k++){
					System.out.print(" " + k);
					// prints a space and prints from 2
				}
				
			}
			
		
			
			System.out.println("");
			//For line break
			rowCount++;
			//adds 1 to rowcount
		}
	}
}