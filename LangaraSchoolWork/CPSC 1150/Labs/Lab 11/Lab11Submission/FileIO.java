/*
*Program Name: FileIO.java
*Author: Jay Seung Yeon Lee
*Date: March 31, 2021
*Course: CPSC 1150 - W05
*Instructor: Leon Pan
*/
import java.util.Scanner;
import java.io.*;

//purpose: use and manipulate arrays
public class FileIO{
	
	public static void main(String[] args) throws FileNotFoundException{
		//main method
		File myFile = new File("releasedates.txt");
		//declare new file
		String[] array = input("releasedates.txt");
		//use input method to put file information into an array
		for (int i = 0; i < array.length; i++){
				
			System.out.println(array[i]);
			//print array
		}
		
		output("newFile.txt", array);
		//use output method to make a copy of the array
		
		String[] monthSorted = sortByMonth(array);
		//sort original array by using sortByMonth method
		File monthSortedFile = new File("sortedByDate.txt");
		//create a new file
		if(monthSortedFile.exists()){
			System.out.println("File already exists");
			System.exit(0);
			// if file already exists, print and exit
		}
		PrintWriter msf = new PrintWriter(monthSortedFile);
		//put the sorted array into a new file using printwriter
		for(int j = 0; j < monthSorted.length; j++){
			msf.print(monthSorted[j]);
			msf.println("");
		}
		msf.close();
		
		String[] nameSorted = sortByName(array);
		//sort original array and assign it to a new array
		File nameSortedFile = new File("SortedByName.txt");
		//create new file
		if(nameSortedFile.exists()){
			System.out.println("File already exists");
			System.exit(0);
			//if exist, print and exit
		}
		PrintWriter nsf = new PrintWriter(nameSortedFile);
		//declare a printwriter
		for(int k = 0; k < nameSorted.length; k++){
			nsf.print(nameSorted[k]);
			nsf.println("");
		}
		nsf.close();
		//use printwriter to put the info on the array to a new file
		
		
	}
	
	public static String[] input(String filename) throws FileNotFoundException{
		//method for taking in information from a file
		Scanner input = new Scanner(new File(filename));
		input.useDelimiter("\n");
		//scanner takes filename and takes information from it
		String[] line = new String[13];
		// declare array and its size
		int i = 0;
		while(input.hasNext()){
			line[i] = input.nextLine();
			i++;
			//assign info from file to an array
		}
		
		
		
		input.close();
		return line;
		//return array
	}

	
	public static void output(String filename, String[] info)  throws FileNotFoundException{
		//method for original array to a new file
		File result = new File(filename);
		if(result.exists()){
			System.out.println("File already exists");
			System.exit(0);
		}
		PrintWriter pw = new PrintWriter(result);
		for(int i = 0; i < info.length; i++){
			
			pw.print(info[i]);
			pw.println("");
			
		}
		//use printwriter to assign array info to a new file
		pw.close();
	}
	
	public static String[] sortByMonth(String[] info) throws FileNotFoundException{
		//method for sorting by month
		String temp = " ";
		for(int i = 0; i < info.length; i++){
			for(int j = 0; j < i-1; j++){
				
				sort(info[j], info[j+1], 8);
			}
			
		}
		//use sort method to sort them by months
		return info;
		//return the array after sorting
	}
	
	public static String[] sortByName(String[] info) throws FileNotFoundException{
		//method for sorting by name
		String temp = " ";
		for(int i = 0; i < info.length; i++){
			for(int j = 0; j < i-1; j++){
				
				sort(info[j], info[j+1], 20);
			}
			
		}
		//use sort method to sort by name
		return info;
		//return array
		
	}
	
	public static void sort(String string1, String string2, int number)  throws FileNotFoundException{
		//method used for sorting 
		int i = 0;
		String temp = "";
		while(i < number){
			//number is for up to how many characters you want to compare if characters for both strings are equal
			if(string1.charAt(i) > string2.charAt(i)){
				temp = string1;
				string1 = string2;
				string2 = temp;
				break;
				//if string1 is greater, swap it with string 2 and break
			}else if(string1.charAt(i) == string2.charAt(i)){
				i++;
				//if characters are equal, i++ so the loop will compare next character in string
			}else{
				break;
				//if there is no need for swap, break
			}
			
		}
		
	}
	
	
}