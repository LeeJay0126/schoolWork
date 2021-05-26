package sample;

/**
 *Class student
 *constructor includes name, surname, and studentNumber
 */
public class Student {
    /**
     * private variables for the class
     */
    private String name;
    private String surname;
    private String address;
    private double quizAverage;
    private int studentNumber;
    private String loginID;
    private double quizGrade;
    private int quizCounter;

    /**
     * Student constructor
     * @param firstName
     * @param surName
     * @param studentNum
     */
    public Student(String firstName, String surName, int studentNum){
        name = firstName;
        surname = surName;
        studentNumber = studentNum;

    }

    /**
     * setName function that combines first and last name together with a comma between them
     * @param firstName
     * @param surName
     */
    public void setName(String firstName, String surName){
        name = firstName + "," + surName;
    }

    /**
     * method which returns name variable set up with setName method
     * @return
     */
    public String getName(){
        return name;
    }

    /**
     * returns studentNumber
     * @return
     */
    public long getStudentNumber(){
        return studentNumber;
    }

    /**
     * Method that sets variable address as a string
     * address is now a string that combines all parameter as one
     * @param number
     * @param street
     * @param city
     * @param province
     * @param postalCode
     */
    void setAddress(String number, String street, String city, String province, String postalCode){
        address = number +" "+ street + ", " + city + ", " + province + ", " + postalCode;
    }

    /**
     * return variable address
     * @return
     */
    public String getAddress(){
        return address;
    }

    /**
     * Method that generates login id with given parameters
     * first letter of the login id is first letter of the firstname
     * middle part of the login id is:
     * 1.if last name is longer than 4 letters, first 4 letters of the lastname
     * 2.if not, last name becomes the middle part of the login id
     * last part of the id is last 2 digits of student number
     * @param firstName
     * @param surname
     * @param studentNumber
     * @return
     */
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

    /**
     * returns name, loginId, and student number in 1 string
     * @return
     */
    public String getInfo(){
        return name + "(" + loginID + ", " + studentNumber + ")";
    }

    /**
     * method that adds quiz score to the total quiz score
     * ++ also adds 1 to the quiz counter which will be used to calculate average quiz score
     * @param quiz
     */
    public void addQuiz(double quiz){
        quizGrade += quiz;
        quizCounter++;
    }

    /**
     * method used to calculate average of the quiz scores
     * total quiz score / quiz counter
     * returns quiz average
     * @return
     */
    public double getQuizAverage(){
        quizAverage = quizGrade / quizCounter;
        return quizAverage;
    }

    /**
     * returns string for the constructor
     * @return
     */
    public String toString(){
        String login = loginID;
        double quizScore = quizAverage;

        return "Student information is : " + login + " and quiz average score is : " + quizScore;
    }


}
