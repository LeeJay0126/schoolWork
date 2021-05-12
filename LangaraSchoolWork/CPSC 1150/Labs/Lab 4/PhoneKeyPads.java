/*
*Program Name: PhoneKeyPads.java
*Author: Jay Seung Yeon Lee
*Date: February 2, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
public class PhoneKeyPads{
	//main method
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		//get a alphabet letter (uppercases or lowercase)
		System.out.print("Enter a letter(Uppercase or Lowercase) : " );
		String letterString = input.next();
		char letter = letterString.charAt(0);
		
		switch(letter){
			//Using switch method, depending on user input, results will be displayed
			case 'a':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'A':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'b':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'B':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'c':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'C':
				System.out.println(letter + " is on number key 2");
			break;
			
			case 'd':
				System.out.println(letter + " is on number key 3");
			break;
			
			case 'D':
				System.out.println(letter + " is on number key 3");
			break;
			
			case 'e':
				System.out.println(letter + " is on number key 3");
			break;
			
			case 'E':
				System.out.println(letter + " is on number key 3");
			break;
			
			case 'f':
				System.out.println(letter + " is on number key 3");
			break;
			
			case 'F':
				System.out.println(letter + " is on number key 3");
			break;
			
			
			case 'g':
				System.out.println(letter + " is on number key 4");
			
			break;
			
			case 'G':
				System.out.println(letter + " is on number key 4");
			
			break;
			
			case 'h':
				System.out.println(letter + " is on number key 4");
			break;
			
			case 'H':
				System.out.println(letter + " is on number key 4");
			break;
			
			case 'i':
				System.out.println(letter + " is on number key 4");
			break;
			
			case 'I':
				System.out.println(letter + " is on number key 4");
			break;
			
			case 'j':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'J':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'k':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'K':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'l':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'L':
				System.out.println(letter + " is on number key 5");
			break;
			
			case 'm':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'M':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'n':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'N':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'o':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'O':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'p':
				System.out.println(letter + " is on number key 6");
			break;
			
			case 'P':
				System.out.println(letter + " is on number key 7");
			break;
			
			case 'q':
				System.out.println(letter + " is on number key 7");
			break;
			
			case 'Q':
				System.out.println(letter + " is on number key 7");
			break;
			case 'r':
				System.out.println(letter + " is on number key 7");
			break;
			case 'R':
				System.out.println(letter + " is on number key 7");
			break;
			case 's':
				System.out.println(letter + " is on number key 7");
			break;
			case 'S':
				System.out.println(letter + " is on number key 7");
			break;
			case 't':
				System.out.println(letter + " is on number key 8");
			break;
			case 'T':
				System.out.println(letter + " is on number key 8");
			break;
			case 'u':
				System.out.println(letter + " is on number key 8");
			break;
			case 'U':
				System.out.println(letter + " is on number key 8");
			break;
			case 'v':
				System.out.println(letter + " is on number key 8");
			break;
			case 'V':
				System.out.println(letter + " is on number key 8");
			break;
			case 'w':
				System.out.println(letter + " is on number key 9");
			break;
			case 'W':
				System.out.println(letter + " is on number key 9");
			break;
			case 'x':
				System.out.println(letter + " is on number key 9");
			break;
			case 'X':
				System.out.println(letter + " is on number key 9");
			break;
			case 'y':
				System.out.println(letter + " is on number key 9");
			break;
			case 'Y':
				System.out.println(letter + " is on number key 9");
			break;
			case 'z':
				System.out.println(letter + " is on number key 9");
			break;
			case 'Z':
				System.out.println(letter + " is on number key 9");
			break;
			//if invalid input is entered, it will display input + "is an invalid input"
			default:
				System.out.println(letter + " is an invalid input");
			
			break;
		}
		
		
	}
	
}