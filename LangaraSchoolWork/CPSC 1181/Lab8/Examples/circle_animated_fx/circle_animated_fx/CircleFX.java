import javafx.scene.shape.Ellipse;
import javafx.scene.Node;
import javafx.scene.paint.Paint;

public class CircleFX extends Circle{
	private Ellipse c;
	public CircleFX(){
		super();
		createCircle();
	}
	public CircleFX(double x, double y, double radius){
		super(x,y,radius);
		createCircle();
	}
	private void createCircle(){
		c = new Ellipse(getCenter().getX(), getCenter().getY(), getRadius(), getRadius());
	}

	public Node[] getAllNodes(){
		return new Node[] {c}; 
	}
	public void setFill(Paint p){
		c.setFill(p);
	}
	public void setStroke(Paint p){
		c.setStroke(p);
	}

	public void move(double x, double y){
		super.move(x,y);
		c.setCenterX(x);
		c.setCenterY(y);
	}


	
}