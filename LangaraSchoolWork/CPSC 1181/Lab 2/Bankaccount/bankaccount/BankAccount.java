
/**
   BackAccount assigns a unique number to each accountNumber
   starting from 1000
*/
public class BankAccount
{  
   private int accountNumber;
   private double balance;
   // static instance variables belong to the class not the object.
   // It means all instance of BankAccount objects share the 
   // same static variable.
   private static int count=1000; 
  
   public BankAccount()
   {   
      accountNumber = count;
      count++;
      balance = 0;
   }

 
   public BankAccount(double initialBalance)
   {   
      accountNumber = count;
      count++;
      balance = initialBalance;
   }

  
   public int getAccountNumber()
   {   
      return accountNumber;
   }

  
   public void deposit(double amount)
   {  
      double newBalance = balance + amount;
      balance = newBalance;
   }

  
   public void withdraw(double amount)
   {   
      double newBalance = balance - amount;
      balance = newBalance;
   }

   
   public double getBalance()
   {   
      return balance;
   }

   @Override
   public String toString(){
      return "[balance:"+balance+", account#"+accountNumber+"]";
   }
}
