package sample;

import java.util.ArrayList;

public class Quiz {
    /**
     * private variables
     */
    private double scale;
    private double studentGrade;

    /**
     * quiz constructor
     * takes scale and student grade as a parameter
     * @param scale
     * @param studentGrade
     */
    public Quiz(double scale, double studentGrade){
        this.scale = scale;
        this.studentGrade = studentGrade;
    }

    /**
     * calculates grade of the quiz based on scale and student grade
     * @return grade of the quiz
     */
    public double getGrade(){
        double grade = (studentGrade/scale)*100;
        return grade;
    }
}


