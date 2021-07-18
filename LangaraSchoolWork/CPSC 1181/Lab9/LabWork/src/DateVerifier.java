import java.time.DateTimeException;
import java.time.LocalDate;

public class DateVerifier {
    private static final String DATE_FORMAT = "DD/MM/YYYY";
    private static final String DATE_FORMAT_MIN = "D/M/YY";
    private static final int NUMBER_OF_FIELDS = 3;
    private static final int LOWEST_YEAR = 1000;
    private static final int HIGHEST_YEAR = 3000;
    private static final int[] DAYS_OF_MONTH = new int[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int NUMBER_OF_MONTHS_IN_YEAR = 12;

    public DateVerifier() {
    }

    public LocalDate verify(String var1, String var2) throws DateTimeException, CPSC1181Exception {
        if (var1.length() >= "D/M/YY".length() && var1.length() <= "DD/MM/YYYY".length()) {
            String[] var6 = var1.split("/");
            if (var6.length != 3) {
                throw new CPSC1181Exception(var2 + " missing or too many fields\nthe correct format is " + "DD/MM/YYYY");
            } else {
                int var3;
                int var4;
                int var5;
                try {
                    var3 = Integer.parseInt(var6[0]);
                    var4 = Integer.parseInt(var6[1]);
                    var5 = Integer.parseInt(var6[2]);
                } catch (NumberFormatException var8) {
                    throw new DateTimeException(var2 + " only digits are allowed\nD M and Y are digits in " + "DD/MM/YYYY");
                }

                if (!validYear(var5)) {
                    throw new DateTimeException(var2 + " incorrect \"year digits\" of " + var5);
                } else if (!validMonth(var4)) {
                    throw new DateTimeException(var2 + " incorrect \"month digits\" of " + var4);
                } else if (!validDay(var3, var4)) {
                    throw new DateTimeException(var2 + " incorrect \"day digits\" of " + var3);
                } else {
                    return LocalDate.of(var5, var4, var3);
                }
            }
        } else {
            throw new CPSC1181Exception(var2 + " not the right number of characters\nuse the following format\n" + "DD/MM/YYYY");
        }
    }

    private static boolean validYear(int var0) {
        return 1000 <= var0 && var0 <= 3000;
    }

    private static boolean validMonth(int var0) {
        return 1 <= var0 && var0 <= 12;
    }

    private static boolean validDay(int var0, int var1) {
        return 1 <= var0 && var0 <= DAYS_OF_MONTH[var1 - 1];
    }
}


