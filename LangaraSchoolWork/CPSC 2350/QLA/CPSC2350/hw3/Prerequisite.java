package cpsc2350.hw3;

public class Prerequisite {
    Course course;
    Grade minimumGrade;

    public Prerequisite(Course course, Grade minimumGrade) {
        this.course = course;
        this.minimumGrade = minimumGrade;
    }
}