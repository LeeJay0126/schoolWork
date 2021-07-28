import java.util.ArrayList;
import java.util.Collections;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * class Bucket manages an ArrayList of integer numbers
 */
public class Bucket{

    private Lock lock;
    private Condition fifty;

    private ArrayList<Integer> bucket;
    /** Default constructor*/
    public Bucket(){
        bucket = new ArrayList<Integer>();
        lock = new ReentrantLock();
        fifty = lock.newCondition();
    }

    /** add an element to the bucket
     * @param n: an integer number
     */
    public void add(int n) throws InterruptedException{
            lock.lock();
            try {
                while(bucket.size() >= 50)
                    fifty.await();
                bucket.add(n);
            } finally {
                lock.unlock();
            }
    }
    /** Calculates and returns the average of the elements of the bucket  and removes all of the elements from the bucket
     * @return the an array of integers. The first element of the array is the median value of the buckey, and second one is the size of the bucket.
     * post condition: the elements of the bucket are removed
     */
    public int[] median(){

        lock.lock();
        try {
            int[] data = {0, 0};
            if (bucket.size() == 0)
                return data;
            Collections.sort(bucket);
            int median = bucket.get(bucket.size() / 2);
            data[0] = median;
            data[1] = bucket.size();
            fifty.signalAll();
            return data;
        }finally{
            lock.unlock();
        }
    }
    /** Returns size of the bucket
     */
    public int getSize(){
        return bucket.size();
    }
    /** Removes all of elements from the bucket
     */
    private void reset(){
        bucket.clear();
    }
}
