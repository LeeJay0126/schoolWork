public class IllegalAmountException extends RuntimeException{
    public IllegalAmountException(){};
    public IllegalAmountException(String msg){
        super(msg);
    }
}
