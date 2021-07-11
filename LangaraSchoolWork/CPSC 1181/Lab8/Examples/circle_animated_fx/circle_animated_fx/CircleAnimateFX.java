import javafx.scene.shape.Ellipse;

class CircleAnimateFX extends CircleFX{

	public CircleAnimateFX(){
		super();
	}
	public CircleAnimateFX(double x, double y, double radius){
		super(x,y,radius);
	}

	public void changeRadius(double pix){
		Ellipse c = (Ellipse)getAllNodes()[0];
		c.setRadiusX(c.getRadiusX()+pix);
		c.setRadiusY(c.getRadiusY()+pix);
	}
	
}