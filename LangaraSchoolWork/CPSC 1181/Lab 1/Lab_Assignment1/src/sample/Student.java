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
    public Student(String firstName, String surName, int studentNum){
        name = firstName;
        surname = surName;
        studentNumber = studentNum;

    }

    public void setName(String firstName, String surName){
        name = firstName + "," + surName;
    }

    public String getName(){
        return name;
    }

    public long getStudentNumber(){
        return studentNumber;
    }

    void setAddress(String number, String street, String city, String province, String postalCode){
        address = number + street + ", " + city + ", " + province + ", " + postalCode;
    }

    public String getAddress(){
        return address;
    }

    public String getLoginId(String firstName, String surname, int studentNumber){

        firstName = firstName.toLowerCase();
        char FirstLetter = firstName.charAt(0);

        String middlePart = surname.toLowerCase();
        if(surname.length() < 4){
            middlePart = surname.toLowerCase();
        }else{
            middlePart = middlePart.substring(0,4);
        }

        String number = Integer.toString(studentNumber);
        String lastPart = ""+number.charAt((number.length())-2) + number.charAt((number.length())-1);

        loginID = FirstLetter + middlePart + lastPart;
        return loginID;

    }

    public String getInfo(){
        return name + "(" + loginID + ", " + studentNumber + ")";
    }

    public void addQuiz(double quiz){
        quizGrade += quiz;
        quizCounter++;
    }

    public double getQuizAverage(){
        quizAverage = quizGrade / quizCounter;
        return quizAverage;
    }

    public String toString(){
        String login = loginID;
        double quizScore = quizAverage;

        return "Student information is : " + login + " and quiz average score is : " + quizScore;
    }


}
