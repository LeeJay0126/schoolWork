
public class BucketThreadTester {
    /**
     * main method
     * Starts 3 threads (producer, consumer, and MyTime (timer) )
     * @param args
     */
    public static void main(String[] args){

        Bucket bucket = new Bucket();

        Thread producer = new Producer(bucket);
        Thread consumer = new Consumer(bucket);
        Thread MyTimer = new MyTimer(producer, consumer);

        producer.start();
        consumer.start();
        MyTimer.start();


    }



}

