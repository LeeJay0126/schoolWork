
public class CountEachVowel{
	
	public static void main(String[] args){
		
		String input = "I hope I do well on today's final exam";
		int aCount =0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
		for(int i = 0; i < input.length(); i++){
			
			char letter = input.charAt(i);
			
			switch (letter){
				
				case 'a':
				case 'A':
					aCount++;
					break;
				case 'e':
				case 'E':
					eCount++;
					break;
				case 'i':
				case 'I':
					iCount++;
					break;
				case 'o':
				case 'O':
					oCount++;
					break;
				case 'u':
				case 'U':
					uCount++;
					break;
				default:
					break;
				
			}
			
		}
		System.out.println("Sentence : " + input);
		System.out.println("a: " + aCount);
		System.out.println("e: " + eCount);
		System.out.println("i: " + iCount);
		System.out.println("o: " + oCount);
		System.out.println("u: " + uCount);
	}
	
}