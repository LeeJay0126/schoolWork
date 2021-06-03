import java.util.ArrayList;
public class TestLibratry{
	public static void main(String[] args){
		Library myLibrary = new Library();
		Book b1 = new Book("Math 11", 79.99);
		myLibrary.add(b1);
		myLibrary.add(new Book("Science 12", 56.50));
		myLibrary.add("Calculus", 38.00);
		System.out.println(myLibrary);

}

class Library{

	private ArrayList<Book> books;
	
	public Library(){
		this.books = new ArrayList<>();
	}
	
	String toString(){
		System.out.print("[");
		for(int i = 0; i < books.size();i++){
			System.out.print(books.get(i));
		}
	}
	
}

class Book{
	private String name;
	private double price;
	
	public Book(String name, double price){
		this.name = name;
		this.price = price;
	}
	
	public String getName(){
		return name;
	}
	
	public double getPrice(){
		return price;
	}
	
	String toString(){
		System.out.println("["+"title:" + this.name + "price:"+this.price+"]");
	}		
	
}
}
