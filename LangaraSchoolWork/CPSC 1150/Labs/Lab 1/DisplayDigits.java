import java.util.Scanner;
public class CalculateBmi {
	
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("Please enter a number between 0 and 999: \n");
		double threeDigits = input.nextDouble();
		
		while (threeDigits > 0) {
			
			System.out.println( threeDigits % 10);
			
			num = num/10;
			
		}
		
		
	}