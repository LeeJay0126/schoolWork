import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Lab5_3{
    public static void main(String[] args)
    {
        Rectangle rect1 = new Rectangle(5, 10, 20, 30);
        Rectangle rect2 = new Rectangle(10, 20, 30, 15);
        Rectangle rect3 = new Rectangle(20, 30, 45, 10);

        // Put the rectangles into a list
        ArrayList<Rectangle> list = new ArrayList<Rectangle>();
        list.add(rect1);
        list.add(rect2);
        list.add(rect3);

        Comparator<Rectangle> comp = (o1,o2) -> {
            double area1 = o1.getHeight() * o1.getWidth();
            double area2 = o2.getHeight() * o2.getWidth();

            if(area1 > area2){
                return 1;
            }else if(area2 > area1) {
                return -1;
            }

            return 0;
        };

        // Call the library sort method
        Collections.sort(list,comp);

        // Print out the sorted list
        for (int i = 0; i < list.size(); i++)
        {
            Rectangle r = list.get(i);
            System.out.println(r.getWidth() + " " + r.getHeight());
            System.out.println("Area is : " + list.get(i).getWidth()*list.get(i).getHeight());
        }

    }

}







