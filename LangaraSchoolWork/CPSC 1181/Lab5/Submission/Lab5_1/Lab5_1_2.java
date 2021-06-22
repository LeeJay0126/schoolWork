import ISpeakable.Speakable;

import java.util.*;

public class Lab5_1_2
{
    public static void main(String[] args)
    {
        Dog d1 = new Dog("Fred");
        d1.speak();
        Object obj = new Dog("connie");
        Dog d2 = obj;
        d2.speak();
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

