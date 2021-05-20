package sample;

public class Student {

    private String name;
    private String surname;
    private String address;
    private double quizAverage;
    private int studentNumber;
    private String loginID;
    private double quizGrade;
    private int quizCounter;

    // Constructor
    Student(String firstName, String surName, int studentNum){
        name = firstName;
        surname = surName;
        studentNumber = studentNum;

    }

    void setName(String firstName, String surName){
        name = firstName + "," + surName;
    }

    String getName(){
        return name;
    }

    long getStudentNumber(){
        return studentNumber;
    }

    String getInfo(){
        return name + "(" + loginID + ", " + studentNumber + ")";
    }

    void setAddress(String number, String street, String city, String province, String postalCode){
        address = number + street + ", " + city + ", " + province + ", " + postalCode;
    }

    String getAddress(){
        return address;
    }

    String getLoginId(String firstName, String surname, int studentNumber){

        firstName = firstName.toLowerCase();
        char FirstLetter = firstName.charAt(0);

        String middlePart = surname.toLowerCase();
        if(surname.length() < 4){
            middlePart = surname.toLowerCase();
        }else{
            middlePart = middlePart.substring(0,3);
        }

        String number = Integer.toString(studentNumber);
        String lastPart = ""+number.charAt((number.length())-2) + number.charAt((number.length())-1);

        String loginID = FirstLetter + middlePart + lastPart;
        return loginID;

    }

    void addQuiz(double quiz){
        quizGrade += quiz;
        quizCounter++;
    }

    double getQuizAverage(){
        quizAverage = quizGrade / quizCounter;
        return quizAverage;
    }

}
