/*
*Program Name: TestAddMatrix.java
*Author: Jay Seung Yeon Lee
*Date: March 22, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: Count Uppercase Letter
public class TestAddMatrix{
	
	public static void main(String[] args){
		//main method
		int[][] firstMatrix = new int[3][3];
		int[][] secondMatrix = new int[3][3];
		
		int[][] resultMat = new int [3][3];
		
		//call methods
		randomNum(0,9,firstMatrix);
		randomNum(0,9,secondMatrix);
		
		resultMat = addMatrix(firstMatrix, secondMatrix);
		
		//printing result array
		for(int i = 0 ; i < 3; i++){
			
			for(int j = 0; j < 3; j++){
				
				System.out.print(resultMat[i][j]);
				System.out.print("	");
			}
			System.out.println("");
			
		}
		
		
	}
	
	public static void randomNum(int min, int max, int[][] array){
		// method for generating random number/ assigning them to 2d array
		int random = 0;
		
		for(int i = 0; i < 3; i++){
			//nested loop that runs 3 times (length of the array) 
			for(int j = 0; j < 3; j++){
				//geberate random number with min and max as a parameter
				random = (int)(min + Math.random()*(max + 1));
				//assign random number to each element of 2d array
				array[i][j] = random;
				
			}
			
		}
		
	}
	
	public static int[][] addMatrix(int[][] m1, int [][] m2){
		//method for adding the sum of 2d arrays
		int[][] resultMatrix = new int[3][3];
		//declare new 2d array 
		for(int i = 0 ; i < 3; i++){
			
			for(int j = 0; j < 3; j++){
				//adds int from array 1 and array 2 and assign it to result array
				resultMatrix[i][j] = m1[i][j] + m2[i][j];
				
			}
			
		}
		
		return resultMatrix;
	}
}