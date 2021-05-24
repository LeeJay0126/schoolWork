package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.util.Scanner;

public class StudentTester extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        //**import scanner and read input for class student
        Scanner s = new Scanner(System.in);

        //** reading variable information needed for student
        System.out.print("Enter student's first name: ");
        String firstname = s.nextLine();
        System.out.print("Enter student's last name: ");
        String lastname = s.nextLine();
        System.out.print("Enter student's student number: ");
        int studentNo = s.nextInt();

        //** student constructor
        Student student = new Student(firstname,lastname,studentNo);


        // test Student getName, geyStudentNumber(), getLoginId()
        student.setName(firstname,lastname);
        System.out.println(student.getName());
        System.out.println(student.getStudentNumber());
        System.out.println(student.getLoginId(firstname,lastname,studentNo));

        // test Student getInfo()
        System.out.println(student.getInfo());

        // test Student addQuiz and getAverage
        student.addQuiz(6.0);
        student.addQuiz(8.5);
        student.addQuiz(9.8);
        System.out.println(student.getQuizAverage());

        //test String toString
        System.out.println(student);

        // testing address class and set/getAddress method from student class
        // reading variables
        System.out.println();
        System.out.println("We will test address class and address methods from student class now.");
        System.out.println("Enter your building number: ");
        String aptNumber = s.nextLine();
        System.out.println("Enter your streetNumber: ");
        String streetName = s.nextLine();
        System.out.println("Enter your city: ");
        String cityName = s.nextLine();
        System.out.println("Enter your province: ");
        String provinceName = s.nextLine();
        System.out.println("Enter your postal code: ");
        String postalCodeName = s.nextLine();

        //testing address class

    }


    public static void main(String[] args) {
        launch(args);
    }
}
