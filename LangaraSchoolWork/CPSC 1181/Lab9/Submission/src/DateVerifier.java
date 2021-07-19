import java.time.DateTimeException;
import java.time.LocalDate;

public class DateVerifier {

    private static final String LongestFormat = "DD/MM/YYYY";
    private static final String ShortestFormat = "D/M/YY";
    private static final int totalFields = 3;
    private static final int lowYear = 1000;
    private static final int highYear = 3000;
    private static final int[] daysInMonths = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int NumberOfMonths = 12;

    public DateVerifier(){

    }

    public LocalDate verify(String date, String startString) throws DateTimeException, CPSC1181Exception {
        if (date.length() >= "D/M/YY".length() && startString.length() <= LongestFormat.length()) {
            String[] var6 = date.split("/");
            if (var6.length != 3) {
                throw new CPSC1181Exception(startString + " missing or too many fields\nthe correct format is " + LongestFormat);
            } else {
                int day;
                int month;
                int year;
                try {
                    day = Integer.parseInt(var6[0]);
                    month = Integer.parseInt(var6[1]);
                    year = Integer.parseInt(var6[2]);
                } catch (NumberFormatException var8) {
                    throw new DateTimeException(startString + " only digits are allowed\nD M and Y are digits in " + LongestFormat);
                }

                if (!daysValidator(day,month)) {
                    throw new DateTimeException(startString + " incorrect \"days digits\" of " + day);
                } else if (!monthValidator(month)) {
                    throw new DateTimeException(startString + " incorrect \"month digits\" of " + month);
                } else if (!yearValidator(year)) {
                    throw new DateTimeException(startString + " incorrect \"year digits\" of " + year);
                } else {
                    return LocalDate.of(day, month, year);
                }
            }
        } else {
            throw new CPSC1181Exception(startString + " not the right number of characters\nuse the following format\n" + LongestFormat);
        }
    }



//    public LocalDate check(String date, int number) throws DateTimeException, CPSC1181Exception{
//        if(date.length() >= ShortestFormat.length() && date.length() <= LongestFormat.length()){
//            String[] array = date.split("/");
//            if(array.length != totalFields){
//                if(number == 1){
//                    throw new CPSC1181Exception("Start Date : missing or too many fields \n the correct format is " + LongestFormat);
//                }else if(number ==2){
//                    throw new CPSC1181Exception("Start Date : missing or too many fields \n the correct format is " + LongestFormat);
//                }
//            }else{
//
//                int day;
//                int month;
//                int year;
//
//                try {
//                    day = Integer.parseInt(array[0]);
//                    month = Integer.parseInt(array[1]);
//                    year = Integer.parseInt(array[2]);
//                }catch(NumberFormatException e){
//                    if(number == 1){
//                        throw new DateTimeException("Start Date : Only digits are allowed \n D, M and Y are digits in " + LongestFormat);
//                    }else{
//                        throw new DateTimeException("End Date : Only digits are allowed \n D, M and Y are digits in " + LongestFormat);
//                    }
//                }
//
//                if(!daysValidator(day,month)){
//                    if(number == 1){
//                        throw new DateTimeException("Start Date : incorrect \" day digits \"" + day);
//                    }else{
//                        throw new DateTimeException("End Date :  incorrect \" day digits \"" + day);
//                    }
//                }else if(!monthValidator(month)){
//                    if(number == 1){
//                        throw new DateTimeException("Start Date : incorrect \" month digits \"" + month);
//                    }else{
//                        throw new DateTimeException("End Date :  incorrect \" month digits \"" + month);
//                    }
//                }else if(!yearValidator(year)){
//                    if(number == 1){
//                        throw new DateTimeException("Start Date : incorrect \" year digits \"" + year);
//                    }else{
//                        throw new DateTimeException("End Date :  incorrect \" year digits \"" + year);
//                    }
//                }else{
//                    return LocalDate.of(day,month,year);
//                }
//            }
//        }else{
//            if(number == 1){
//                throw new CPSC1181Exception("Start Date not the right number of characters \n user the following format" + LongestFormat);
//            }else if(number == 2){
//                throw new CPSC1181Exception("End Date not the right number of characters \n user the following format" + LongestFormat);
//            }
//        }
//    }

    private boolean yearValidator(int year){
        if(year >= lowYear && year <= highYear){
            return true;
        }
        return false;
    }

    private boolean monthValidator(int month){
        if(month >= 1 && month <= NumberOfMonths){
            return true;
        }
        return false;
    }

    private boolean daysValidator(int day, int month){
        if(day >= 1 && day <= daysInMonths[month -1]){
            return true;
        }
        return false;
    }

}
