public class Question8{
	
	public static void main(String[] args){
		
		int[][] array1 = new int[5][5];
		int count = 0;
		int maxCount = 0;
		int mostColum = 0;
		int mostRow = 0;
		
		for(int i = 0; i < 5; i++){
			
			for(int j = 0; j < 5; j++){
				
				array1[i][j] =(int)(Math.random()*2);
				System.out.print(array1[i][j]);
			}
			System.out.println("");
		}
		
		for(int k = 0; k < 5; k++){
			count = 0;
			for(int p = 0; p < 5; p++){
				
				if(array1[k][p] == 0){
					count++;
				}
				
			}
			if(k == 0){
				maxCount = count;
			}else{
				if(maxCount < count){
					maxCount = count;
					mostRow = k;
				}
				
			}
			
		}
		
		for(int d = 0; d < 5; d++){
			count = 0;
			for(int f = 0; f< 5; f++){
				
				if(array1[d][f] == 0){
					count++;
				}
				
			}
			if(d==0){
				maxCount = count;
			}else{
				if(maxCount < count){
					maxCount = count;
					mostColum = d;
				}
			}
			
		}
		
		System.out.print("The smallest row index: " + mostRow);
		System.out.println("");
		System.out.print("The smallest column index: " + mostColum);
		
	}
	
}