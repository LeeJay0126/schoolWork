import java.util.ArrayList;

public class midterm {
    public static void main(String[] args){
        ArrayList<Integer> a= new ArrayList<Integer>();
        ArrayList<Integer> b= new ArrayList<Integer>();
        initialize(a);
        initialize(b);

// initialise both a and b to random values.
        add(a,b);
    }

    public static void initialize(ArrayList<Integer> x){
        for(int i = 0; i < 10; i++){
            x.add((int)(Math.random()*20));
        }
    }

    public static void add(ArrayList<Integer> a, ArrayList<Integer> b){
        int temp = 0;
        for(int i = 0; i < 10; i++){
            temp = a.get(i) + b.get(i);
            a.set(i,temp);
        }
    }

}



