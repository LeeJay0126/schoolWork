import java.util.*;

class Person extends Memory
{
    private String name;
    private int age;

    public Person(String name, int age)
    {
        super(name,age);
    }

    public String toString()
    {
        return "Name:  " + name + '\n' +
                "Age:  " + age + '\n';
    }

    public String getName()
    {
        return name;
    }

    public int getAge()
    {
        return age;
    }

    public void tellAll()
    {
        dumpMemory();
    }

    public void rememberAnEvent(String s)
    {
        addLifeData(s);
    }

}
class Memory{

    private ArrayList<String> lifeData;

    public Memory(String name, int age){
        lifeData = new ArrayList<>();
        lifeData.add("Name: " + name);
        lifeData.add("Age: " + age);
    }

    public void addLifeData(String datum){
        lifeData.add(datum);
    }

    public void dumpMemory(){
        for(String s: lifeData){
            System.out.println(s);
        }
    }

}


public class PersonRunner
{
    public static void main(String[] args)
    {
        Person aperson = new Person("Bob", 33);
        aperson.tellAll();
        aperson.rememberAnEvent("I was born in 1970.");
        aperson.rememberAnEvent("I finished school in 2003.");
        aperson.tellAll();
    }
}

