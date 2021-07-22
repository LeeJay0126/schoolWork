import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;


public class SortTest{
	private Point[] arr;
	public static void main(String[] args){
		new SortTest().startIt();

	}
	public void startIt(){
		initialize();
		sortArray(arr);

		for(int i = 0; i < arr.length; i++){
			System.out.println(arr[i].returnDistance());
		}

	}
	private void initialize(){
		Random rand = new Random();
		int m = rand.nextInt(20);
		arr = new Point[m];
		for(int i=0; i<m; i++){
			arr[i]= new Point(rand.nextInt(100),rand.nextInt(100));
		}

	}
	private void sortArray(Point[] array){

		Arrays.sort(array);

	}
}

class sortByDistance implements Comparator<Point>{

    public int compare(Point a, Point b){
        return a.returnDistance().compareTo(b.returnDistance());
    }

}



class Point implements{
	private double x;
	private double y;
	private double distance;
	public Point(double x, double y){
		this.x = x;
		this.y = y;
	}
	public double returnDistance(){
		distance = Math.sqrt(Math.pow(this.getX(),2) + Math.pow(this.getY(),2));
		return distance;
	}
	public double getX(){
		return x;
	}
	public double getY(){
		return y;
	}
	public String toString(){
		return "[x= "+ x + ", y= "+ y +"]";
	}

}