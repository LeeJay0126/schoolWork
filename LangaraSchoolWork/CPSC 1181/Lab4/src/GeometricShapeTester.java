import java.util.Random;

/**
 * Main class method for testing main
 */
public class GeometricShapeTester{

    private GeometricShape[] shapes;

    /**
     * main method that will test all classes
     * @param args
     */
    public static void main(String[] args){
         GeometricShapeTester shapeTester = new GeometricShapeTester();
         System.out.println("\nTest case 1:");
         double average = shapeTester.findAverage();
         System.out.println("average: "+Math.round(average));

         System.out.println("\nTest case 2:");
         GeometricShape s = shapeTester.getMax();
         System.out.println(s);


         GeometricShape[] shapes = shapeTester.getShapes();
         System.out.println("\nTest case 3:");
         System.out.println("list of the shapes:");
         for(GeometricShape e:shapes)
         	System.out.println(e);

         System.out.println("\nTest case 4:");
         shapeTester.sort();
         System.out.println("shapes sorted in ascending order based on their area:");
         for(GeometricShape e:shapes)
         	System.out.println(e);

    }

    /**
     * GeometricShapeTester method
     * this method will initialize arraylist of shapes
     * with random values (parameters) assigned to each shape made
     */
    public GeometricShapeTester(){
        shapes = new GeometricShape[20];
        Random rand = new Random();
        int option;
        final int COORD = 50;
        final int LENGTH1 = 50;
        final int LENGTH2 = 100;
        for(int i=0; i<shapes.length; i++){
            option=rand.nextInt(4);
            switch(option){
                case 0:
                    shapes[i]= new Rectangle(
                            rand.nextInt(COORD),
                            rand.nextInt(COORD),
                            rand.nextInt(LENGTH2),
                            rand.nextInt(LENGTH2));
                    break;
                case 1:
                    shapes[i]= new Square(
                            rand.nextInt(COORD),
                            rand.nextInt(COORD),
                            rand.nextInt(LENGTH2));
                    break;
                case 2:
                    shapes[i]= new Oval(
                            rand.nextInt(COORD),
                            rand.nextInt(COORD),
                            rand.nextInt(LENGTH1),
                            rand.nextInt(LENGTH2));
                    break;
                case 3:
                    shapes[i]= new Circle(
                            rand.nextInt(COORD),
                            rand.nextInt(COORD),
                            rand.nextInt(LENGTH1));
            }
        }
    }

    /**
     * method that finds the average of all shapes in the arraylist
     * @return average area of the shapes
     */
    public double findAverage(){
        double average = 0;
        double total = 0;

        for(int i = 0; i < 20;i++){
            total += shapes[i].getArea();
        }
        average = total/20;
        return average;
    }

    /**
     * method that gets the shape with the greatest area
     * @return shape with the greatest area
     */
    public GeometricShape getMax(){
        double maxArea = 0;
        for(int i = 0; i < 20; i++){
            if(shapes[i].getArea() > maxArea) {
                maxArea = shapes[i].getArea();
            }
        }
        for(int j = 0; j < 20; j++){
            if(shapes[j].getArea() == maxArea){
                return shapes[j];
            }
        }
        return null;
    }

    /**
     * sorts the arraylist to greatest to smallest in ascending order
     * used bubble sort
     */
    public void sort(){
        GeometricShape s;
        for(int i = 0; i < shapes.length; i++){
            for(int j = 0; j < shapes.length-i-1; j++){
                if(shapes[j].getArea() < shapes[j+1].getArea()){
                    s = shapes[j];
                    shapes[j] = shapes[j+1];
                    shapes[j+1] = s;
                }
            }
        }
    }

    /**
     * returns shape that is stored in the current index of arraylist
     * @return shapes
     */
    public GeometricShape[] getShapes(){
        return shapes;
    }


}

/**
 * abstract class GeometricShape
 * works somewhat like a template for all other following classes
 */
abstract class GeometricShape{
    private int x;
    private int y;

    /**
     * constructor for GeometricShape class
     * @param int x
     * @param int y
     */
    public GeometricShape(int x, int y) {
        this.x = x;
        this.y = y;
    }

    /**
     * getter function for private variable X
     * @return x
     */
    public int getX(){
        return x;
    }
    /**
     * getter function for private variable Y
     * @return y
     */
    public int getY(){
        return y;
    }

    /**
     * abstract functions that returns area and toString for shapes
     * @return area
     * @return toString
     */
    abstract public double getArea();
    abstract public String toString();

}

/**
 * class Rectangle
 */
class Rectangle extends GeometricShape{
    /**
     * private variable height and width
     */
    int height;
    int width;

    /**
     * constructor for class Rectangle
     * @param x
     * @param y
     * @param height
     * @param width
     */
    public Rectangle(int x, int y,int height, int width){
        super(x,y);
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
    public String toString(){
        return "[ x: " + this.getX() + ", y: " + this.getY() + ", height: " + this.getHeight() + ", width: " + this.getWidth() + ", area: " + this.getArea() + "]";
    }

    /**
     * function that returns area of the shape
     * @return area
     */
    public double getArea() {
        return width*height;
    }
}

/**
 * class square
 */
class Square extends Rectangle{
    /**
     * constructor for class square
     * @param x
     * @param y
     * @param length
     */
    public Square(int x, int y, int length){
        super(x, y, length, length);
    }

    /**
     * String toString method that will set what string will be returned when a shape is called
     * @return string that contains x, y , length, and area
     */
    public String toString(){

        return "[ x: " + this.getX() + ", y: " + this.getY() + ", length: " + this.getHeight() + ", area: " + this.getArea() + "]";
    }

}

/**
 * class oval
 */
class Oval extends GeometricShape{
    /**
     * private variable
     * int horizontalRadius
     * int verticalRadius
     */
    int horizontalRadius;
    int verticalRadius;

    /**
     * constructor for class Oval
     * @param x
     * @param y
     * @param horizontalRadius
     * @param verticalRadius
     */
    public Oval(int x, int y, int horizontalRadius, int verticalRadius){
        super(x,y);
        this.horizontalRadius = horizontalRadius;
        this.verticalRadius = verticalRadius;
    }

    /**
     * getter function for horizontal radius for class Oval
     * @return horizontalRadius
     */
    public int getHorizontalRadius(){
        return horizontalRadius;
    }

    /**
     * getter function for vertical radius for class Oval
     * @return veriticalRadius
     */
    public int getVerticalRadius(){
        return verticalRadius;
    }

    /**
     * String toString method that will set what string will be returned when a shape is called
     * @return string that contains x, y , horizontalRadius, verticalRadius and area
     */
    public String toString(){
        return "[ x: " + this.getX() + ", y: " + this.getY() + ", h_radius: " + this.getHorizontalRadius() + ", v_radius: " + this.getVerticalRadius() + ", area: " + this.getArea() + "]";
    }
    /**
     * get Area function that returns area of the shape
     * @return area
     */
    public double getArea(){
        return horizontalRadius * verticalRadius * Math.PI;
    }

}

/**
 * class circle
 */
class Circle extends Oval{
    /**
     * constructor for class circle
     * @param x
     * @param y
     * @param radius
     */
    public Circle(int x, int y, int radius){
        super(x,y,radius,radius);
    }


    /**
     * String toString method that will set what string will be returned when a shape is called
     * @return string that contains x, y , radius, and area
     */
    public String toString(){
        return "[ x: " + this.getX() + ", y: " + this.getY() + ", radius: " + this.getHorizontalRadius() + ", area: " + this.getArea() + "]";
    }
}


