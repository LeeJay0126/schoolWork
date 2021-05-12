/*
*Program Name: TestBubbleSort.java
*Author: Jay Seung Yeon Lee
*Date: March 15, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: testing bubble sort
public class TestBubbleSort{
	
	public static void main(String[] args){
		//main method
		Scanner input = new Scanner(System.in);
		//get number of items
		System.out.print("How many numbers are in your item?: ");
		int index = input.nextInt();
		double[] array = new double[index];
		//initialize array
		System.out.print("Enter Your array: ");
		for(int i = 0; i < index; i++){
			//loop that accepts user input and assign them in to the array
			array[i] = input.nextDouble();
			
		}
		
		sort(array);
		//use sort method
		for(int m = 0; m < array.length; m++){
			
			System.out.println(array[m]);
			//displays items in the array
		}
		
	}
	
	public static void sort(double[] array){
		//method that sorts the array smallest to greatest
		boolean changed = true;
		
		do{
			
			changed = false;
			//set condition to false
			for(int j =0; j < array.length-1; j++){
				//loops through itself until all index are sorted
				if(array[j] > array[j+1]){
					
					double temp = array[j];
					array[j] = array [j+1];
					array[j+1] = temp;
					changed = true;
				}
				
			}
			
		}while(changed);
		
		
	}
	
	/*for(int i =0; i < array.length; i++){
			
			for(int k = 0; k < array.length-1; k++){
				
				if(array[k] > array[k+1]){
					
					double temp = array[k];
					array[k] = array [k+1]
					array[k+1] = temp;
				}
				
			}
			
		}

	*/
	
}