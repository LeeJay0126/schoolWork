public class Lab4 {

    public void main(String[] args){

    }

}

abstract class GeometricShape{
    private int x;
    private int y;

    public GeometricShape(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }

    abstract public double getArea();
    abstract public String toString();

}

abstract class Rectangle extends GeometricShape{

    int height;
    int width;

    public Rectangle(int height, int width){
        if(height >= 0 && width >= 0) {
            this.height = height;
            this.width = width;
        }else {
            System.out.println("Height and width has to be positive! it's width and heigh is set to 0.");
            this.height = 0;
            this.width = 0;
        }
    }

    public int getHeight(){
        return height;
    }

    public int getWidth(){
        return width;
    }

    public void setHeight(int height){
        this.height = height;
    }

    public void setWidth(int width){
        this.width = width;
    }

    public String toString(){
        return "Rectangle";
    }

    public double getArea() {
        return width*height;
    }
}

class Square extends Rectangle{

    public Square(int height, int width){
        super(height,width);
    }

    public String toString(){
        return "Square";
    }

}


