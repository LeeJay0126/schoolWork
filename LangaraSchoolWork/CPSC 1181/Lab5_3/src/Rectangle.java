import java.util.ArrayList;
import java.util.Collections;

public class Rectangle
{
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

        // Call the library sort method
        Collections.sort(list);

        // Print out the sorted list
        for (int i = 0; i < list.size(); i++)
        {
            Rectangle r = list.get(i);
            System.out.println(r.getWidth() + " " + r.getHeight());
        }
    }
    int height;
    int width;
    int x;
    int y;

    /**
     * constructor for class Rectangle
     * @param x
     * @param y
     * @param height
     * @param width
     */
    public Rectangle(int x, int y,int height, int width){
        this.x = x;
        this.y = y;
        this.height = height;
        this.width = width;
    }

    /**
     * getter function for private variable height
     * @return height
     */
    public int getHeight(){
        return height;
    }
    /**
     * getter function for private variable width
     * @return width
     */
    public int getWidth(){
        return width;
    }

    /**
     * String toString method that will set what string will be returned
     * @return string that contains x, y, height , width, and area of the rectangle
     */
//    public String toString(){
//        return "[ x: " + this.getX() + ", y: " + this.getY() + ", height: " + this.getHeight() + ", width: " + this.getWidth() + ", area: " + this.getArea() + "]";
//    }

    /**
     * function that returns area of the shape
     * @return area
     */
    public double getArea() {
        return width*height;
    }
}


