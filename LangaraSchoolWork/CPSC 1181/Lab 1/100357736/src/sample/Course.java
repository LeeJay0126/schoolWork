package sample;

import java.io.IOException;
import java.util.ArrayList;

public class Course {

    private int studentNumber;
    private String name;
    private String surName;
    private String courseName;

    private ArrayList<Student> students;

    public Course(String courseName) {
        this.courseName = courseName;
        this.students = new ArrayList<>();
    }

    // Add a new student to the list of the students, and return reference of the
    // newly created student. In case of failure it return null
    Student addStudent(String name, String familyName) {
        try {
            Student newStudent = new Student(name, familyName);
            students.add(newStudent);
            return students.get(students.size() - 1);
        } catch(Exception e){
            return null;
        }
    }

    // Return a reference of the student. In case student is not found it return null
    Student findStudent(long studentId) {
        for(int i = 0; i < students.size()-1; i++){
            if(students.get(i).getStudentNumber() == studentId ){
                return students.get(i);
            }
        }
        final Student o = null;
        return o;
    }

    // Remove the student from the list and return reference of the student
    // being removed. In case student is not found it returns null
    Student deleteStudent(long studentId) {
        for(int i = 0; i < students.size()-1; i++){
            if(students.get(i).getStudentNumber() == studentId){
                Student removedStudent = students.get(i);
                students.remove(i);
                return removedStudent;
            }
        }
        final Student o = null;
        return o;
    }

    // adds a quiz to a student given studentId


    // scale: the scale of the quiz
    // studenGrade: the grade student achieved
    // return true is case succeed, or false in case of failure
    //gotta ask if making addQuiz a static will solve the problem **
    boolean addQuiz(long StudentId, double scale, double studentGrade) {
        for(int i = 0; i < students.size()-1; i++){
            if(students.get(i).getStudentNumber() == StudentId){
                students.get(i).addQuiz(scale,studentGrade);
                return true;
            }
        }
        return false;
    }

    // Return reference of the student with the highest average quiz
    Student findTopStudent() {

        Student bestStudent = students.get(0);

        double temp = 0;
        for(int i = 0; i < students.size()-1; i++){
            if(students.get(i).getAverage() > temp){
                temp = students.get(i).getAverage();
            }
        }

        for(int j = 0; j < students.size()-1; j++){
            if(students.get(j).getAverage() == temp){
                bestStudent = students.get(j);
            }
        }
        return bestStudent;
    }

    // Return the average of the course. (average of the average of the student grades)
    double getAverage() {
        double totalGrade = 0;
        double averageGrade = 0;
        for(int i = 0; i < students.size()-1; i++){
            totalGrade += students.get(i).getAverage();
        }
        averageGrade = totalGrade / students.size()-1;
        return averageGrade;
    }


}
