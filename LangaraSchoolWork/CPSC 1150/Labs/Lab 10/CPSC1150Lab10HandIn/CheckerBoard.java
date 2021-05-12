/*
*Program Name: CheckerBoard.java
*Author: Jay Seung Yeon Lee
*Date: March 22, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: Generating checker board
public class CheckerBoard{
	
	public static void main(String[] args){
		//main method
		int[][] array1 = new int[8][8];
		//declare 2d array
		for(int i = 0; i < 8; i++){
			//loop that initiate and print element of the array
			for(int j = 0; j < 8; j++){
				
				array1[i][j] =(int)(Math.random()*2);
				System.out.print(array1[i][j]);
				
			}
			System.out.println("");
		}
		//calling functions to check which row/ column/ diagonals have all 0
		rowChecker(array1);
		columnChecker(array1);
		minor(array1);
		major(array1);
	}
	
	public static void rowChecker(int[][] array){
		//method that checks rows
		int count;
		
		for(int i = 0; i < 8; i++){
			//loop for each row
			count = 0;
			//resets count to 0 after every row
			for(int j = 0; j < 8; j++){
				//if the element is 0, count ++
				if(array[i][j] == 0){
					
					count++;
					
				}
				
			}
			
			if(count > 7){
				//if count for that row is more than 7, it means all elements are 0 in that row and print result
				System.out.println("All 0's on row " + i);
				
			}
			
		}
		
	}
	
	public static void columnChecker(int[][] array){
		//main method that checks columns
		int count;
		
		for(int i = 0; i < 8; i++){
			//loop that runs
			count = 0;
			//reset count 
			for(int j = 0; j < 8; j++){
				
				if(array[j][i] == 0){
					//if element in array[j][i] is 0, count++
					count++;
					
				}
				
				if(count  > 7){
				//if entire column is 0, print 
				System.out.println("All 0's on column " + j);
				
			}
				
			}
			
		}
		
	}
	
	public static void minor(int[][] array){
		//method for minor diagonal
		int j = 0;
		int count = 0;
		//declare variable
		for(int i = 7; i >= 0; i--){
			
			if(array[j][i] == 0){
				count ++;
				//if element on array[j][i] is 0, add 1 to the count
			}
			j++;
		}
		if(count == 8){
			// if entire minor diagonal is 0, print
			System.out.println("All 0's on the minor diagonal");
			
		}
		
	}
	
	public static void major(int[][] array){
		//method for major diagonal
		int j = 0;
		int count = 0;
		for(int i = 0; i < 8; i++){
			
			if(array[j][i] == 0){
				//if element on array[j][i] is 0, add 1 to the count
				count ++;
			}
			j++;
		}
		if(count == 8){
			//if entire major diagonal is 0 print
			System.out.println("All 0's on the major diagonal");
			
		}
		
	}
	
}