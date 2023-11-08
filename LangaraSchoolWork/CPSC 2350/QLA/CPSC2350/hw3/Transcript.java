package cpsc2350.hw3;

import java.util.HashMap;
import java.util.Map;

public class Transcript {
    Student student;
    Map<Course, Grade> courseHistory;

    public Transcript(Student student) {
        this.student = student;
        courseHistory = new HashMap<>();
    }
}