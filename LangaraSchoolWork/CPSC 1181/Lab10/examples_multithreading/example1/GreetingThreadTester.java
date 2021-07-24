import java.util.Date;

/**
*   This program tests the greeting thread by running two
*   threads in parallel.
*/
public class GreetingThreadTester
{
   public static void main(String[] args)
   {
      GreetingRunnable r1 = new GreetingRunnable("Hello, World!");
      Thread t1 = new Thread(r1);
      t1.start();
   }
}

