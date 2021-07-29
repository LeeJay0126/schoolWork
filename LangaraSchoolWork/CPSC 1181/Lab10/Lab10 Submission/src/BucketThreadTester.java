
import java.util.Timer;
import java.util.TimerTask;


public class BucketThreadTester {
    /**
     * main method
     * Starts 3 threads (producer, consumer, and MyTime (timer) )
     * @param args
     */

    private Timer timer;
    private static Thread producer;
    private static Thread consumer;

    public static void main(String[] args){

        Bucket bucket = new Bucket();
        producer = new Producer(bucket);
        consumer = new Consumer(bucket);

        producer.start();
        consumer.start();

        new BucketThreadTester().schedule();

    }

    void schedule(){
        TimerTask task = new MySchedule();
        timer = new Timer();

        timer.schedule(task, 10000);
    }

    private class MySchedule extends TimerTask{
        public void run(){
            System.out.println("Time up!");
            System.out.println("working");

            producer.interrupt();
            consumer.interrupt();
        }
    }

}

