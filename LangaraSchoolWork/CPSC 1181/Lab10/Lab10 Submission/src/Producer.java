/**
 * public class producer
 */
public class Producer extends Thread{
    private Bucket bucket;;

    /**
     * constructor
     * @param bucket
     */
    public Producer(Bucket bucket){
        this.bucket = bucket;
    }

    /**
     * This method adds random integer range from 1 - 255 to the bucket.
     * after that, it sleeps for 1 milliseconds.
     */
    public void run(){
        while(!Thread.interrupted()) {
            try {
                int random = (int) (Math.random() * 256);
                System.out.println(random);
                bucket.add(random);
                Thread.sleep(1);
            } catch (InterruptedException exception) {

            }
        }

    }
}
