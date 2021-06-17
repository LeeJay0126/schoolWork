public class TestSphere{
	public static void main(String[] args){
		Sphere s1 = new Sphere(10, 20, 30, 100);
		Sphere s2 = new Sphere(10, 20, 30, 100);
		if(s1.equals(s2))
			System.out.println("the spheres are equal");
	}
}

class Circle{
	private int xc, yc, radius;
	public Circle(int x, int y, int r){
		xc =x;
		yc=y;
		radius=r;
	}

	public int getXc(){
		return xc;
	}

	public int getYc(){
		return yc;
	}

	public int getRadius(){
		return radius;
	}

	public boolean equals(Circle otherCircle) {
		if (this.getXc() == otherCircle.getXc() && this.getYc() == otherCircle.getYc() && this.getRadius() == otherCircle.getRadius()) {
			return true;
		}
		return false;
	}
}

class Sphere extends Circle{
	private int z;

	/** Constructor
	@param x : x coordinate of the center of the shpere
	@param y : y coordinate of the center of the shpere
	@param z : z coordinate of the center of the shpere
	@param r : radius of the sphere
	*/
	public Sphere(int x, int y, int z, int r){
		super(x,y,r);
		this.z = z;

	}


	public int getZ(){
		return z;
	}


	public boolean equals(Sphere otherSphere){
		if(this.getXc() == otherSphere.getXc() && this.getYc() == otherSphere.getYc() && this.getRadius() == otherSphere.getRadius() && this.getZ() == otherSphere.getZ()){
			return true;
		}
		return false;

	}
}
