package sample;

import java.util.ArrayList;

public class Quiz {

    private double scale;
    private double studentGrade;

    public Quiz(double scale, double studentGrade){
        this.scale = scale;
        this.studentGrade = studentGrade;

    }

    public double getGrade(){
        return studentGrade;
    }

}
