
/**
 *
 * @author jmadar
 */
public class WordsDefinitionTester {
    
    private String testGetDefinition(String msg) {
	
		WordsDefinition translator = new WordsDefinition();
		return translator.getDefinition(msg);     
		
    }
    
    
    public static void main(String[] args) {
        WordsDefinitionTester tester = new WordsDefinitionTester();
        String str1="apple";
        String str2="I want to eat an apple";

        // test for one word
        System.out.println("Test case: single word");
        System.out.println("Test get definition: "+str1+" \n\t"+tester.testGetDefinition("apple"));
        // Add more test cases
        String testWord1 = "macdonald";
        String testWord2 = "kimchi";
        String testWord3 = "bottle";
        System.out.println("Testing more get definition (word): ");
        System.out.println(testWord1 +" \n\t " + tester.testGetDefinition(testWord1));
        System.out.println(testWord2 +" \n\t" + tester.testGetDefinition(testWord2));
        System.out.println(testWord3 + "\n\t"+ tester.testGetDefinition(testWord3));



        // test for a line of text
        System.out.println("Test case: line");
        System.out.println("Test get definition: "+str2+" \n\t"+tester.testGetDefinition("I want to eat an apple"));
        // Add more test cases

        String testLine1 = "I don't know what to eat for dinner today";
        String testLine2 = "Maybe some macdonald's, or cook something for myself";
        String testLine3 = "Feel a little sick today";

        System.out.println("Testing more get definition (line)");
        System.out.println(testLine1+" \n\t"+tester.testGetDefinition(testLine1));
        System.out.println(testLine2+" \n\t"+tester.testGetDefinition(testLine2));
        System.out.println(testLine3+" \n\t"+tester.testGetDefinition(testLine3));

    }
}
