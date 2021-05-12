/*
*Program Name: PlayLottery.java
*Author: Jay Seung Yeon Lee
*Date: March 15, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: Play lottery
public class PlayLottery{
	
	public static void main(String[] args){
		//main method
		Scanner input = new Scanner(System.in);
		//get integers from user
		int[] array = new int[6];
		//initialize array 
		System.out.print("Enter 6 distinct numbers between 1 and 49 : ");
		array = getUserNumbers(input);
		//use getUserNumbers method to get array for user numbers and assign the array to array1
		int[] array2 = new int[6];
		//initialize second array for randomnumbers
		array2 = getRandomNumbers(1, 49);
		// use getRandomNumbers method and assign it to array 2
		int match = TotalMatchedNumbers(array,array2);
		//use TotalMatchedNumbers method to check how many matches user made
		System.out.print("You got "+ match + " matches!");
		//display result
		
	}
	
	public static int[] getUserNumbers(Scanner input){
		//method to make an array of user input integers
		int[] array = new int[6];
		//initializing array
		int number = 0;
		int i = 0;
		do{
			//do-while loop that runs until there are 6 integers in the array
			number = input.nextInt();
			//gets number from user input
			if(number >= 1 && number <= 49){
				//validates if user input is 1 to 49
				if(i == 0){
					//if array index is 0, array[0] is number
					array[i] = number;
				}else{
					int count = 0;
					// count is increased if there is already the same number in the array
					for(int j = 0; j < i; j++){
					
						if(number == array[j]){
						
							count++;
							
						}
					}
					if(count == 0){
						// if count is 0, it means there are no repeating number in the array. put number into according index
						array[i] = number;
					}else{
						continue;
						//if count is not 0, there is a repeating number in the array. continue and start from beginning of do-while loop
					}
				}
			}else{
				// if input is not between 1 and 49, print the following and send the code back to the beginning
				System.out.print("Input must be 1 - 49");
				System.out.println("");
				continue;
			}
			//System.out.println(array[i]);
			i++;
			// increase i by 1 after successful round of loop
		}while(i <= 5);
			
		
		return array;
		//return user input array
	}
	
	public static int TotalMatchedNumbers(int[] array, int[] array2){
		//method for matched numbers
		int match = 0;
		//start from 0
		for(int i = 0; i < array.length; i++){
			//outer loop 
			for(int j = 0; j < array2.length; j++){
				//inner loop. use bubble sort to compare two arrays
				if (array2[j] == array[i]){
					//array 2 will loop through and see if it has any matching value to array 1
					match++;
					// if there is a match, match + 1
				}
				
			}
			
		}
		
		return match;
		//return result
	}
	
	public static int[] getRandomNumbers(int min, int max){
		//method for random number array
		int random = 0;
		int[] array = new int[6];
		//initialize random and array
		int i = 0;
		do{
			//do-while loop that loops until array has 6 integers
			random = (int)(Math.random()*(max - min+1));
			//System.out.println(random);
			//create random integer from min to max
			if(i == 0){
				// if index is 0, assign random number to index
				array[i] = random;
			}else{
				//if index is not 0
				int count = 0;
				for(int j = 0; j < i; j++){
					//loop that compares random number to numbers in the array
					if(random == array[j]){
						//if random number already exists within the array, add 1 to count
						count++;
					}
				}
				if(count == 0){
					//if count is 0, means no repetition, assign random to array[i]
					array[i] = random;
					
				}else{
					//if there is random number already in the array, send the loop back to the beginning
					continue;
				}
				
			}
			i++;
			//System.out.println(array[i]);
		}while(i <= 5);
		
		return array;
		//return result
		
	}
	
}