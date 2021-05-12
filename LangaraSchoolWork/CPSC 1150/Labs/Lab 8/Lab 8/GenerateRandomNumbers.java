/*
*Program Name: GenerateRandomNumbers.java
*Author: Jay Seung Yeon Lee
*Date: March 09, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/

public class GenerateRandomNumbers{
	//purpose: generating 6 distinct random numbers
	
	public static int randomNumber(int min, int max){
		//method generating random numbers with parameters
		int result = min + (int)(Math.random()*(max - min + 1));
		return result;
	}
	
	public static int validator(int[] array, int number,int j){
		//validator method for boolean expression for do while loop condition
		for(int i = 0; i < j-1; i++){
			//loops through for the length of current input array (parameter)
			if(array[i] == number){
				//if array[i] == number return 0
				return 0;
			}
		}
		return 1;
	}
	
	public static void main(String args[]){
		// main method
		int[] array = new int[6];
		//initialize array
		for(int i = 0; i < array.length; i++){
			int random;
			do{
				//loop exits if generated random number is not included in the current array
				random = randomNumber(1, 49);
				array[i] = random;
			}while(validator(array, random, i)!=1);
			
			
		}
		
		for(int k = 0; k < array.length; k++){
			// Just checking what's in the array
			System.out.println(array[k]);
		}
		
	}
	
}