import java.util.concurrent.locks.Lock;

public class Consumer extends Thread{

    private Bucket bucket;

    /**
     * parameter forconsumer class
     * @param bucket
     */
    public Consumer(Bucket bucket){
        this.bucket = bucket;
    }

    /**
     * stores data from bucket median()
     * displays median and size of the bucket
     * sleeps for 5 milliseconds
     */
    public void run(){
        int[] data;
        while(!isInterrupted()) {
            try {
                data = bucket.median();
                System.out.println("median : " + data[0] + ", size: " + data[1]);
                Thread.sleep(5);
            } catch (InterruptedException exception) {
                break;
            }
        }
    }

}
