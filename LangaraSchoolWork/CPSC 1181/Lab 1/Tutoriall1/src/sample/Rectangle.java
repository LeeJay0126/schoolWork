package sample;

/**
 class Rectangle defines a rectangle with width and height
 */
public class Rectangle{
    // instance fields
    private double height;
    private double width;

    // constructors
    //----------------

    /**
     default constructor
     Constructs a new Rectangle with height and width equal to 0
     */
    public Rectangle(){

    }
    /**
     Constructs a new Rectangle with height and width equal to given width and height

     @param w width of the rectangle
     @param h height of the rectangle
     */
    public Rectangle(double h, double w){
        height = h;
        width = w;

    }

    // accessor methods
    //----------------

    /**
     @return  returns the width of the rectangle
     */
    public double getWidth(){

        return width;

    }
    /**
     @return  returns the height of the rectangle
     */
    public double getHeight(){

        return height;

    }
    /**
     @return  returns the area of the rectangle
     */
    public double getArea(){

        return width * height;

    }
    /**
     @return  returns the circumference of the rectangle
     */
    public double getCircumference(){

        return width * 2 + height * 2;
    }


    // mutator methods
    //----------------

    /**
     @param w sets the width of the rectangle
     */
    public void setWidth(int w){
        width = w;
    }
    /**
     @param h sets the height of the rectangle
     */
    public void setHeight(int h){
        height = h;
    }

}