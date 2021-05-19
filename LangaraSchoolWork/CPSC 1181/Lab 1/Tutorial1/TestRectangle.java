public class TestRectangle{
	public static void main(String[] args){
		//Test case 1:
		System.out.println("Test case 1:");
		Rectangle rec1= new Rectangle();
		rec1.setWidth(10);
		rec1.setHeight(12);
		System.out.println(rec1.getWidth());
		System.out.println(rec1.getHeight());
		System.out.println(rec1.getArea());
		System.out.println(rec1.getCircumference());

		// Test case 2:
		System.out.println("Test case 2:");
		Rectangle rec2= new Rectangle(8,5);
		System.out.println(rec2.getWidth());
		System.out.println(rec2.getHeight());
		System.out.println(rec2.getArea());
		System.out.println(rec2.getCircumference());


	}
}