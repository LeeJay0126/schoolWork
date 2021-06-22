import java.util.ArrayList;
import java.util.Collections;
public class BankAccount implements Comparable<BankAccount>
{
    private int accountNumber;
    private double balance;
    // static instance variables belong to the class not the object.
    // It means all instance of BankAccount objects share the
    // same static variable.
    private static int count=1000;

    public static void main(String[] args){
        ArrayList<BankAccount> list = new ArrayList<BankAccount>();
        BankAccount ba1 = new BankAccount(2400);
        BankAccount ba2 = new BankAccount(3400);
        BankAccount ba3 = new BankAccount(3400);
        BankAccount ba4 = new BankAccount(5700);
        BankAccount ba5 = new BankAccount(3250);

        list.add(ba1);
        list.add(ba2);
        list.add(ba3);
        list.add(ba4);
        list.add(ba5);

        Collections.sort(list);

        for(int i = 0; i < list.size(); i++){
            BankAccount b = list.get(i);
            System.out.println(b.getBalance());
        }

    }

    public BankAccount()
    {
        accountNumber = count;
        count++;
        balance = 0;
    }


    public BankAccount(double initialBalance)
    {
        accountNumber = count;
        count++;
        balance = initialBalance;
    }


    public int getAccountNumber()
    {
        return accountNumber;
    }


    public void deposit(double amount)
    {
        double newBalance = balance + amount;
        balance = newBalance;
    }


    public void withdraw(double amount)
    {
        double newBalance = balance - amount;
        balance = newBalance;
    }


    public double getBalance()
    {
        return balance;
    }

    @Override
    public String toString(){
        return "[balance:"+balance+", account#"+accountNumber+"]";
    }

    @Override
    public int compareTo(BankAccount o) {
        if(this.getBalance() > o.getBalance()){
            return -1;
        }else if(this.getBalance() < o.getBalance()){
            return 1;
        }
        return 0;
    }
}

