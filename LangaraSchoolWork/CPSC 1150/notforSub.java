
import java.util.Scanner;
//purpose: Count Uppercase Letter
public class notforSub{
	
	public static void main(String[] args){
		String[] array = new String[7];
		
		for(int j = 0; j < array.length; j++){
			
			array[j]  = "" + j + "		";
			
		}
		
		
		int tempI = 0;
		
		String temp = "";

		for(int i = 0; i < array.length-1; i+=2){
			if(array.length % 2 == 0){
				if(i == array.length-1){
					break;
				}
			}
			temp = array[i+1];
			array[i+1] = array[i];
			array[i] = temp;

		}
		
		for (int k = 0; k < array.length; k++){
			
			System.out.println(array[k]);
			
		}
	}
	
}


