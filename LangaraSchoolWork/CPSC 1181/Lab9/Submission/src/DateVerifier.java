import java.time.DateTimeException;
import java.time.LocalDate;

public class DateVerifier {

    private static final String LongestFormat = "DD/MM/YYYY";
    private static final String ShortestFormat = "D/M/YY"
    private static final int totalFields = 3;
    private static final int lowYear = 1000;
    private static final int highYear = 3000;
    private static final int[] daysInMonths = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int NumberOfMonths = 12;

    public LocalDate check(String date, int number) throws DateTimeException, CPSC1181Exception{
        if(date.length() >= ShortestFormat.length() && date.length() <= LongestFormat.length()){
            String[] array = date.split("/");
            if(array.length == 3){
                int years;
                int month;
                int days;
                try {
                    days = Integer.parseInt(array[0]);
                    month = Integer.parseInt(array[1]);
                    years = Integer.parseInt(array[2]);
                }catch(NumberFormatException){

                }
            }else{
                if(number == 1){
                    throw new CPSC1181Exception("Start Date: missing or too many fields\n The correct format should be " + LongestFormat);
                }else if(number == 2){
                    throw new CPSC1181Exception("End Date: missing or too many fields\n The correct format should be " + LongestFormat);
                }

            }
        }
    }

}
