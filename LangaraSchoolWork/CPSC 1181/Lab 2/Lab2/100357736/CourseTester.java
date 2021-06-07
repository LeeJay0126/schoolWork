package sample;

import java.util.Scanner;

public class CourseTester{

    @Override
    public void start(Stage primaryStage) throws Exception{
        /**
         * scanner and course constructor
         */
        Scanner input = new Scanner(System.in);
        Course newCourse = new Course();

        /**
         * This part adds / construct Student with user inputs
         * as long as user inputs 0 as validator value.
         */
        String validator = "0";
        int count = 0;
        while(validator.equals("0")) {
            System.out.println("Enter student name in the course: ");
            String studentName = input.nextLine();
            System.out.println("Enter Student's name Last name: ");
            String studentLastName = input.nextLine();
            newCourse.addStudent(studentName, studentLastName);
            newCourse.getLoginID(count);
            count++;
            System.out.println("Enter 0 when you want to adding students, otherwise enter any integer: ");
            validator = input.nextLine();
        }

        /**
         * This part is for findStudent method
         * user inputs student number of the student to find
         * code returns reference  of the found student
         */
        System.out.println("Enter a student number of the student you want to find: ");
        String newStudentNumber = input.nextLine();
        Student foundStudent = newCourse.findStudent(Integer.parseInt(newStudentNumber));
        System.out.println("Student Found: "+foundStudent);


        /**
         * This part adds, and calculate average grade for each student and course
         * also help execute delete student function (only if there are more than 1 student)
         * after deleting a student, will calculate new top student and course average
         *
         * Part1.
         * part 1 will take in student number and quiz scale and grade for each student
         * and add it to quiz arraylist.
         * if successfully added, will print a string that will say so
         * if not, will print a string that will say it failed.
         * code will accept these parameters and add more quizzes to quiz arraylist
         * under Student with the given student name until validator reads -1
         */
        String valid2 = "0";
        String quizScale;
        String quizScore;
        while(!(valid2.equals("-1"))){

            System.out.println("Enter student number you want to add quiz grade to: ");
            newStudentNumber = input.nextLine();
            System.out.println("Enter scale of the quiz: ");
            quizScale = input.nextLine();
            System.out.println("Enter score of the quiz: ");
            quizScore = input.nextLine();
            newCourse.addQuiz(newStudentNumber,Double.parseDouble(quizScale),Double.parseDouble(quizScore));
            if(newCourse.addQuiz(newStudentNumber,Double.parseDouble(quizScale),Double.parseDouble(quizScore))){
                System.out.println("Quiz has been added");
            }else{
                System.out.println("Quiz not added. Check your student number");
            }

            System.out.println("Enter -1 if you want to exit. Enter other integer if you want to add quiz: ");
            valid2 = input.nextLine();
        }

        /**
         * part 2
         *
         * this part calculates top student in the course and course average grade
         * delete student will be available if(number of students > 1)
         * will calculate new top student and course average if a student is deleted
         */
        Student bestStudent = newCourse.findTopStudent();
        System.out.println("Top student in the course is the student :" + bestStudent);
        System.out.println("Top student's average grade is : " + bestStudent.getAverage());
        System.out.println("Average grade of the students for the course is: " + newCourse.getAverage());
        if(newCourse.studentCounter() > 1){
            System.out.println("Enter student number of the student you want to remove: ");
            long studentRemoved = input.nextLong();
            newCourse.deleteStudent(studentRemoved);
            System.out.println("New average grade after student has been removed is : "+ newCourse.getAverage());
            bestStudent = newCourse.findTopStudent();
            System.out.println("New Top student in the course is : " + bestStudent);
        }else{
            System.out.println("If you have more than 1 students in the course, you can test delete students!");
        }


    }


    public static void main(String[] args) {
        launch(args);
    }
}
