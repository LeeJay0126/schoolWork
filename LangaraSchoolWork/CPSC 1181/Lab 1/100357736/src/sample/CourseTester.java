package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.Scanner;

public class CourseTester extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{

        Scanner input = new Scanner(System.in);

        System.out.println("Enter the course name: ");
        String courseName = input.nextLine();
        Course newCourse = new Course(courseName);

        int validator = 0;

        while(validator == 0) {

            System.out.println("Enter 0 when you want to stop adding students.");

            System.out.println("Enter student name in the course: ");
            String studentName = input.nextLine();
            System.out.println("Enter Student's name name: ");
            String studentLastName = input.nextLine();

            newCourse.addStudent(studentName, studentLastName);
        }

        System.out.println("Enter a student number of the student you want to find: ");
        long findStudentNumber = input.nextLong();
        Course foundStudent = Course.findStudent(findStudentNumber);

    }


    public static void main(String[] args) {
        launch(args);
    }
}
