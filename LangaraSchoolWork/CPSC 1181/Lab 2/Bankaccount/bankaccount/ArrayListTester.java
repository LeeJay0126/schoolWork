import java.util.ArrayList;

/**
   This program tests the ArrayList class.
*/
public class ArrayListTester
{
   public static void main(String[] args)
   {
      ArrayList<BankAccount> accounts 
            = new ArrayList<BankAccount>();
      // Account number is assigned by BankAccount
      accounts.add(new BankAccount());
      accounts.add(new BankAccount(1000));
      accounts.add(new BankAccount(1500));
      accounts.add(new BankAccount());
      System.out.println(accounts);
   }
}
