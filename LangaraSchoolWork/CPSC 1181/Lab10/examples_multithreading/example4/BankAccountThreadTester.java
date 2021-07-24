/**
*   This program runs four threads that deposit and withdraw
*   money from the same bank account. 
*/
public class BankAccountThreadTester
{
   public static void main(String[] args)
   {
      BankAccount account = new BankAccount();
      final double AMOUNT = 100;
      final int REPETITIONS = 100;

      DepositRunnable d1 = new DepositRunnable(
            account, AMOUNT, REPETITIONS);
      WithdrawRunnable w1 = new WithdrawRunnable(
            account, AMOUNT, REPETITIONS);

       DepositRunnable x1 = new DepositRunnable(
            account, AMOUNT, REPETITIONS);
      WithdrawRunnable y1 = new WithdrawRunnable(
            account, AMOUNT, REPETITIONS);
   
      Thread t1 = new Thread(d1);
      Thread t2 = new Thread(w1);
      Thread t3 = new Thread(x1);
      Thread t4 = new Thread(y1);
   
      t1.start();
      t2.start();
      t3.start();
      t4.start();
     }
}

