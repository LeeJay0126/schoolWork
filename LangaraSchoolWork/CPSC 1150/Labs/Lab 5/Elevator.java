/*
*Program Name: Elevator.java
*Author: Jay Seung Yeon Lee
*Date: February 8, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: to find a person's middle name
public class Elevator{
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		
		int floorFirst = 1;
		//set first floor you start to 1
		int floorSecond = 0;
		do{
			//do while loop so loop will be executed until user inputs 0
			System.out.println("The elevator is at Floor " + floorFirst + " now");
			System.out.print("Enter a floor number between 1 and 9, or enter 0 to quit :");
			//get floor user wants to go
			floorSecond =input.nextInt();
			//set floor second to user input
		
		
			
			if(floorSecond >=0 && floorSecond < 10){
				//making sure user input is between 0 and 9
				
				if(floorSecond > floorFirst){
					//if elevator is moving up
					for(int i = floorSecond; i >= 1; i--){
					//loop determining how many elevators will be displaying highest to lowest.
						System.out.println("o------o     //\\\\");
						System.out.println("|   " + i + "  |    //  \\\\");
						System.out.println("o------o   //    \\\\");
						//predesigned elevator image with up arrow
					}
					System.out.println("The elevator is moving up from Floor " + floorFirst + "  to " + floorSecond);
					//printing where elevator came from and current floor					
				}
				else if(floorSecond < floorFirst){
					//if elevator is moving down
					for(int i = floorFirst; i >= floorSecond; i--){
					//loop determining how many elevators will be displaying highest to lowest.
						System.out.println("o------o   \\\\    //");
						System.out.println("|   " + i + "  |    \\\\  //");
						System.out.println("o------o     \\\\//");
						//predesigned elevator image with down arrow
					}
					System.out.println("The elevator is moving down from Floor " + floorFirst + "  to " + floorSecond);
					//printing where elevator came from and current floor
				}
			
			}	
			floorFirst = floorSecond;
			//sets floor first to floor second for the beginning of the loop
		}while(floorSecond != 0);	
			
		
		
		
	}
}