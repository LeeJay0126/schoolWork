package sample;

import java.util.ArrayList;

public class Course {

    private ArrayList<Student> students;

    /**
     * constructor
     */
    public Course() {
        this.students = new ArrayList<>();
    }

    /**
     * method adds new student to students array
     * @param name
     * @param familyName
     * @return null or reference of added student
     */
    Student addStudent(String name, String familyName) {
        try {
            Student newStudent = new Student(name, familyName);
            students.add(newStudent);
            return students.get(students.size() -1);
        } catch(Exception e){
            return null;
        }
    }

    // Return a reference of the student. In case student is not found it return null

    /**
     * method finds student from students array list and returns student
     * @param studentId
     * @return null or reference of found student
     */
    Student findStudent(long studentId) {
        for(int i = 0; i < students.size(); i++){
            if(students.get(i).getStudentNumber() == studentId ){
                return students.get(i);
            }

        }

        final Student o = null;
        return o;
    }

    /**
     * method finds and delete student with the paramater student id
     * @param studentId
     * @return null if not found and reference of deleted student if found
     */
    Student deleteStudent(long studentId) {
        Student foundStudent = findStudent(studentId);
        if(!(findStudent(studentId) == null)){
            students.remove(foundStudent);
            return foundStudent;
        }
        students.remove(foundStudent);
        final Student o = null;
        return o;
    }

    /**
     * adds quiz to quiz array list under student with given student id
     * if student is found adds quiz into its quiz arraylist and returns true/false
     * @param StudentId
     * @param scale
     * @param studentGrade
     * @return true or false
     */
    boolean addQuiz(String StudentId, double scale, double studentGrade) {
        int intStudentId = Integer.parseInt(StudentId);
        if(!(findStudent(intStudentId) == null)){
            Student foundStudent = findStudent(intStudentId);
            foundStudent.addQuiz(scale,studentGrade);
            return true;
        }
        return false;
    }

    /**
     * finds the student with highest average grade
     * @return reference of the top student
     */
    Student findTopStudent() {

        Student bestStudent = students.get(0);

        double temp = 0;
        double studentAverage;
        for(int i = 0; i < students.size(); i++){
            studentAverage = students.get(i).getAverage();
            if(studentAverage > temp){
                temp = students.get(i).getAverage();
            }
        }

        for(int j = 0; j < students.size(); j++){
            studentAverage = students.get(j).getAverage();
            if(studentAverage == temp){
                bestStudent = students.get(j);
            }
        }

        return bestStudent;
    }

    /**
     * gets average of all the students in the course
     * @return average of all students
     */
    double getAverage() {
        double totalGrade = 0;
        double averageGrade;
        for(int i = 0; i < students.size(); i++){
            totalGrade += students.get(i).getAverage();
        }
        averageGrade = totalGrade / students.size();
        return averageGrade;
    }

    /**
     * returns student number of a student
     * @param number
     * @return studentnumber
     */
    long getStudentNumber(int number){
        long studentNumber = students.get(number).getStudentNumber();
        return studentNumber;

    }

    /**
     * gets login id
     * @param number
     * @return login id
     */
    String getLoginID(int number){
        String loginID = students.get(number).getLoginId(students.get(number).getName(), students.get(number).getLastName());
        return loginID;
    }

    /**
     * counts the number of students in the course
     * @return
     */
    int studentCounter(){
        return students.size();
    }

}
