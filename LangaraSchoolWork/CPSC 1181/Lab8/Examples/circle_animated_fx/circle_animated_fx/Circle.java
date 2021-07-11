// A cricle is defined by its
// center (x,y)
// and radius
public class Circle{
	private Point2D center;
	private double radius;

	public Circle(){
		center = new Point2D();
		radius = 1;
	}

	public Circle(double x, double y, double radius){
		center = new Point2D(x,y);
		this.radius = radius;
	}

	public Point2D getCenter(){
		return center;
	}

	public void move(double x, double y){
		center.move(x,y);

	}

	public void setRadius(double radius){
		this.radius = radius;

	}

	public double getRadius(){
		return radius;
	}

	public double getArea(){
		return Math.pow(radius,2)*Math.PI;
	}
		
	public double getCircumference(){
		return 2* radius * Math.PI;
	}

	@Override
	public String toString(){
		return "["+center.toString()+", radius: "+radius +"]";

	}

	
}

