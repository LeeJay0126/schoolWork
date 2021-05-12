
public class MostPopularTutors{
	
	public static void main(String[] args){
		
		int[][] countOfStudents = {
			{13,15,12,12,2,12,2}, 
			{8,5,14,8,8,4,8},
			{3,11,1,2,6,13,9},
			{3,12,4,9,15,15,10},
			{6,3,12,14,2,2,15}
		};
	
		int numberOfTutors = 7;
		int numberOfDays = 5;
	
		String result = returnArray(countOfStudents, numberOfDays, numberOfTutors);
		
		System.out.print("The most popular tutor(s): " + result);
	}
	
	public static String returnArray(int[][] array,int numberOfDays,int numberOfTutors){
		
		int[] newArray = new int[7];
		int count = 0;
	
		for(int i = 0; i < numberOfDays; i++){
			//for loop that calculates the total number of students tutor taught in a week
			count = 0;
			for(int j = 0; j < numberOfTutors; j++){
			
				count += array[i][j];
			
			}
			newArray[i] = count;
		}
		
		int MostStudents = 0;
		for(int k = 0; k < numberOfTutors; k++){
			//Getting the number of students most popular tutor(s) taught
			if(k == 0){
				MostStudents = newArray[k];
			}else{
				
				if(newArray[k] > MostStudents){
					
					MostStudents = newArray[k];
					
				}
			}
		}
		
		String popularTutorList = "";
		for(int m = 0; m < numberOfTutors; m++){
			
			if(newArray[m] == MostStudents){
				
				switch(m){
					
					case 0:
						popularTutorList += "Bob" + "	";
						break;
					case 1:
						popularTutorList += "Alice" + "	";
						break;
					case 2:
						popularTutorList += "Mike" + "	";
						break;
					case 3:
						popularTutorList += "Jane" + "	";
						break;
					case 4:
						popularTutorList += "Justin" + "	";
						break;
					case 5:
						popularTutorList += "Paul" + "	";
						break;
					case 6:
						popularTutorList += "Dan" + "	";
						break;
					
					default:
						break;
				}
				
			}
			
		}
		
		return popularTutorList;
		
	}
	
	
}

