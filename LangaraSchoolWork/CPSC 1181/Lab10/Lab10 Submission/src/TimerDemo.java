import java.util.Timer;
import java.util.TimerTask;

public class TimerDemo {
   private Timer timer;
   public static void main(String[] args) {
      
      new TimerDemo().schedule();
     
   }
   
   void schedule(){
      TimerTask  task = new MySchedule();
      timer = new Timer();

      // scheduling the task at interval 1000 ms
      timer.schedule(task,1000);      

   }

   private class MySchedule extends TimerTask{
      // this method performs the task
      public void run() {
         System.out.println("timer working");  
         // You can invoke cancel() method of the timer to stop it.
         timer.cancel(); 
      }   
   } 

}