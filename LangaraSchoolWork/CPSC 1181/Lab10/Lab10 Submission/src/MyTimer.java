/**
 * class Timer
 */
class MyTimer extends Thread{

    private int seconds;
    private Thread producer;
    private Thread consumer;

    /**
     * constructor
     * @param producer
     * @param consumer
     */
    public MyTimer(Thread producer, Thread consumer){
        this.seconds = 0;
        this.producer = producer;
        this.consumer = consumer;
    }

    /**
     * set seconds for the timer
     * @param second
     */
    public void setSeconds(int second){
        this.seconds = second;
    }

    /**
     * gets seconds for the timer
     * @return
     */
    public int getSeconds(){
        return seconds;
    }

    /**
     * This method takes a second break after every iteration.
     * after wards, seconds increase by 1 until seconds is equal to 10.
     * after, it interrupts producer and consumer thread.
     */
    public void run(){
        try{
            while(this.getSeconds() <= 10){
                System.out.println(seconds);
                Thread.sleep(1000);
                this.setSeconds(this.getSeconds()+1);
            }
        } catch (InterruptedException exception) {

        }finally{
            System.out.println("done");
            producer.interrupt();
            consumer.interrupt();
        }
    }

}
