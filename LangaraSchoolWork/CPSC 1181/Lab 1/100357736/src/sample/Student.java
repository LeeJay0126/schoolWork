package sample;

import java.util.ArrayList;

public class Student {

    private String name;
    private String surname;
    private static int count = 10000001;
    private double quizAverage;
    private long studentNumber;
    private String loginID;
    private double quizGrade;


    private ArrayList<Quiz> quiz;

    /**
     * Student constructor
     * @param firstName
     * @param lastName
     */
    public Student(String firstName, String lastName){
        name = firstName;
        surname = lastName;
        studentNumber = count;
        this.quiz = new ArrayList<>();
        count++;
    }

    /**
     * method to set name for class student
     * @param firstName
     * @param lastName
     */
    public void setName(String firstName, String lastName){
        name = firstName;
        surname = lastName;
    }
    /**
     * method that adds quiz grade to the total sum of quiz grades
     * for the student and according to the scale
     * @param scale
     * @param studentGrade
     */
    public void addQuiz(double scale, double studentGrade){
        Quiz newQuiz = new Quiz(scale, studentGrade);
        quiz.add(newQuiz);
    }

    /**
     * returns average grade for the student
     * @return quizAverage
     */
    public double getAverage(){

        for(int i = 0; i < quiz.size()-1; i++){
            quizAverage += quiz.get(i).getGrade();
        }
        quizAverage /= quiz.size();
        return quizAverage;
    }

    /**
     * returns name for the student
     * @return
     */
    public String getName(){
        return name + ", " + surname;
    }

    /**
     * returns studentNumber
     * @return studentNumber
     */
    public long getStudentNumber(){
        return studentNumber;
    }

    /**
     * generates login id for the student and returns it
     * @param firstName
     * @param surname
     * @return
     */
    public String getLoginId(String firstName, String surname){

        firstName = firstName.toLowerCase();
        char FirstLetter = firstName.charAt(0);

        String middlePart = surname.toLowerCase();
        if(surname.length() < 4){
            middlePart = surname.toLowerCase();
        }else{
            middlePart = middlePart.substring(0,4);
        }

        String number = Long.toString(studentNumber);
        String lastPart = ""+number.charAt((number.length())-2) + number.charAt((number.length())-1);

        loginID = FirstLetter + middlePart + lastPart;
        return loginID;

    }

    /**
     * returns student info with name , last name, student number, loginId
     * @return student info
     */
    public String getInfo(){
        return name + "," + surname + "(" +studentNumber+" , " + loginID +")";
    }

    /**
     * String toString to return constructor
     * @return
     */
    public String toString(){
        return "[name: " + name + ", surname : " + surname+ "(StudentId: " + studentNumber + " loginId: " + loginID + ")]";
    }

}
