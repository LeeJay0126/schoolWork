import java.time.DateTimeException;
import java.time.LocalDate;

/**
 * Class DateVerifier that will verify my days for it's validity
 */
public class DateVerifier {
    /**
     * Pivate variables
     */
    private static final String LongestFormat = "DD/MM/YYYY";
    private static final String ShortestFormat = "D/M/YY";
    private static final int totalFields = 3;
    private static final int lowYear = 1000;
    private static final int highYear = 3000;
    private static final int[] daysInMonths = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int NumberOfMonths = 12;

    /**
     * Empty constructor
     */
    public DateVerifier(){

    }

    /**
     * Method check.
     *
     * Takes string from the text field with dates as a parameter and int to determine which start string will be used.
     * With int 1 as a parameter, it will use "Start Date :" as a start string and other numbers it will use "End Date: ".
     * It first confirms if the length of the date qualifies for the least or most characters of the string
     * and then Checks the number of the fields. Up to this part is just validating date string's format
     * (it's length or it's number of fields). Number of fields should be 3, because there should be days, months, years
     *
     * Next, we splitted the string by / character when we were validating numbers of the fields and store them in indexes
     * of an array. We will try to parse the elements to integer, and if not succeeded, we will try to catch and throw an
     * exception.
     *
     * Next step is we validate each days, months, and years if they are in the correct range. Number of days per month is stored
     * in an array in an order, so by passing in days and month as a parameter, it will check if days <= daysInMonthArray[month-1]
     * to see if days are valid.
     *
     * For months, its just going to be month <= 12 && month >= 1. Years will be years >= 1000 && years <= 3000.
     * If all the validators passes, it will return total days, months and years
     *
     * @param date
     * @param number
     * @return LocalDate
     * @throws DateTimeException
     * @throws CPSC1181Exception
     */
    public LocalDate check(String date, int number) throws DateTimeException, CPSC1181Exception{
        if(date.length() >= ShortestFormat.length() && date.length() <= LongestFormat.length()){
            String[] array = date.split("/");
            if(array.length != totalFields){
                if(number == 1){
                    throw new CPSC1181Exception("Start Date : missing or too many fields \n the correct format is " + LongestFormat);
                }else{
                    throw new CPSC1181Exception("Start Date : missing or too many fields \n the correct format is " + LongestFormat);
                }
            }else{

                int day;
                int month;
                int year;

                try {
                    day = Integer.parseInt(array[0]);
                    month = Integer.parseInt(array[1]);
                    year = Integer.parseInt(array[2]);
                }catch(NumberFormatException e){
                    if(number == 1){
                        throw new DateTimeException("Start Date : Only digits are allowed \n D, M and Y are digits in " + LongestFormat);
                    }else{
                        throw new DateTimeException("End Date : Only digits are allowed \n D, M and Y are digits in " + LongestFormat);
                    }
                }

                if(!daysValidator(day,month)){
                    if(number == 1){
                        throw new DateTimeException("Start Date : incorrect \" day digits \"" + day);
                    }else{
                        throw new DateTimeException("End Date :  incorrect \" day digits \"" + day);
                    }
                }else if(!monthValidator(month)){
                    if(number == 1){
                        throw new DateTimeException("Start Date : incorrect \" month digits \"" + month);
                    }else{
                        throw new DateTimeException("End Date :  incorrect \" month digits \"" + month);
                    }
                }else if(!yearValidator(year)){
                    if(number == 1){
                        throw new DateTimeException("Start Date : incorrect \" year digits \"" + year);
                    }else{
                        throw new DateTimeException("End Date :  incorrect \" year digits \"" + year);
                    }
                }else{
                    //Seems like LocalDate.of() is in year/month/day format. Stuck on this for quite a bit
                    return LocalDate.of(year,month,day);
                }
            }
        }else{
            if(number == 1){
                throw new CPSC1181Exception("Start Date not the right number of characters \n user the following format" + LongestFormat);
            }else{
                throw new CPSC1181Exception("End Date not the right number of characters \n user the following format" + LongestFormat);
            }
        }
    }

    /**
     * Method Year Validator
     * takes year as a parameter
     * if year is >= 1000 (low year) and <= 3000 (high year)
     * will return true, otherwise false
     * @param year
     * @return true or false
     */
    private boolean yearValidator(int year){
        if(year >= lowYear && year <= highYear){
            return true;
        }
        return false;
    }

    /**
     * method monthValidator
     * if month is between 1 and 12, return true. otherwise false
     * @param month
     * @return true or false
     */
    private boolean monthValidator(int month){
        if(month >= 1 && month <= NumberOfMonths){
            return true;
        }
        return false;
    }

    /**
     * method daysValidator
     * Takes in parameter day and month.
     * if day is within the range of 1 and number of days in daysInMonths array index of month - 1
     * it will return true, otherwise false.
     *
     * We are comparing days to the number of days in daysInMonth[month -1 ] because days of the month in the array
     * is in order, but it's index starts from 0. Therefore In order to properly access the value we want, we need days In Month [month -1]
     *
     * @param day
     * @param month
     * @return
     */
    private boolean daysValidator(int day, int month){
        if(day >= 1 && day <= daysInMonths[month -1]){
            return true;
        }
        return false;
    }

}
