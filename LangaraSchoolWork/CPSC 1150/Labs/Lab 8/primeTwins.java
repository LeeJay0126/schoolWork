public class primeTwins{
	
	public static void main(String[] args){
		
		int prime = 0;
		
		int primeAmount = 0;
		for(int i = 2; i <= 1000; i++){
			int primeCounter = 0;
			for(int j = 1; j <= i; j++){
				
				if(i%j==0){
					
					primeCounter++;
					
				}
			}
			
			if(primeCounter == 2){
				primeAmount++;
			}
		}
		
		int[] primeArray = new int[primeAmount];
		
		int l = 0;
		for(int i = 2; i <= 1000; i++){
			int primeCounter = 0;
			for(int j = 1; j <= i; j++){
				
				if(i%j==0){
					
					primeCounter++;
					
				}
			}
			
			if(primeCounter == 2){
				primeArray[l] = i;
				l++;
			}
		}
		
		for(int k = 0; k < primeArray.length-1; k++){
			
			if((primeArray[k+1] - primeArray[k]) == 2){
	
				System.out.println("("+primeArray[k]+","+primeArray[k+1]+")");
				
			}
			
		}
		
	}
	
}