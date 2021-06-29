import java.sql.SQLOutput;

public class Parent
{
    public void doSomething(){int x=5;}

    public static void main(String args[]){
        Parent kid = new Child();
        kid.doSomething(); // line 1
        kid.doAnotherThing(); // line 2
    }

}

class Child extends Parent
{
    public void doAnotherThing(){int y=6;}
}


