
import ISpeakable.Speakable;

import java.util.*;

public class Lab5_1_1
{
    public static void main(String[] args)
    {
        ArrayList <Speakable> dogcatList = new ArrayList <Speakable>();
        dogcatList.add(new Dog("Fred"));
        dogcatList.add(new Cat("Wanda"));
        for (Speakable obj  : dogcatList)
        {
             obj.speak();
        }

    }
}

class Dog implements Speakable
{
    private String name;

    public Dog(String name)
    {
        this.name = name;
    }

    public void speak()
    {
        System.out.println("Woof! Woof!");
    }

    public String toString()
    {
        return "Dog:  " + name;
    }
}

class Cat implements Speakable
{
    private String name;

    public Cat(String name)
    {
        this.name = name;
    }

    public void speak()
    {
        System.out.println("Meow! Meow!");
    }

    public String toString()
    {
        return "Cat:  " + name;
    }
}
