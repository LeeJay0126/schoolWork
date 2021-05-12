/*
*Program Name: CountVowels.java
*Author: Jay Seung Yeon Lee
*Date: March 01, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
//purpose: printing 4 random vowels
public class CountVowels {
	//main method
	
	public static int vowelsCounter(String sentenceValue){
		// method that counts vowels
		
		int count = 0;
		char Selector;
		
		for(int i = 0; i < sentenceValue.length(); i++){
				//loop that goes through the string
				Selector = sentenceValue.charAt(i);
				switch(Selector){
					// if a character has a vowel, use switch and add 1 to the counter
					case 'a':
						count++;
						break;
					case 'e':
						count++;
						break;
					case 'i':
						count++;
						break;
					case 'o':
						count++;
						break;
					case 'u':
						count++;
						break;
					case 'A':
						count++;
						break;
					case 'E':
						count++;
						break;
					case 'I':
						count++;
						break;
					case 'O':
						count++;
						break;
					case 'U':
						count++;
						break;
					default:
						continue;
				}
				
				
			}
		
		return count;
	}
	
	public static void main(String[] args){
		//main method
		Scanner input = new Scanner(System.in);
		//gets string input
		System.out.print("Enter a sentence : ");
		String sentence = input.nextLine();
		
		int count = vowelsCounter(sentence);
		//call vowel counting method
		
		
		System.out.print("There are " + count + " number of vowels");
		//print result
	}
	
}