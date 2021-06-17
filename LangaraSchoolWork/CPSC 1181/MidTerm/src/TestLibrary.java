import java.util.ArrayList;
import java.util.Locale;
import java.lang.*;
import java.util.*;

public class TestLibrary{
  public static void main(String[] args){
    Library library = new Library();
    library.addReservedBook("Calculus","Math");
    library.addReservedBook("physics 12","physics");
    library.addReservedBook("Big Java: Early Objects","java");
    library.addReservedBook("Clean code","java");
    library.addReservedBook("English 12","Language");
    library.changeSubject(4,"algorithm");
    System.out.println(library);
  }
}

//----
class Book{
  // Add instance variables, methods, and override toString() method
    private String title;
    private String subject;
 
  //constructor
  public Book(String title, String subject){
    this.title = title;
    this.subject = subject;
  }

  public String getTitle(){
      return title;
  }

  public void setSubject(String subject){
      this.subject = subject;
  }
  @Override
  public String toString(){
      return "[title: " + title + " subject: " + subject;
  }
  



}

//----
class ReservedBook extends Book{
  // Add instance variables, methods, and override toString() method
    private static int id = 1;

  //constructor
  public ReservedBook(String title, String subject){
      super(title,subject);
      id++;
  }

  public int getId(){
      return id;
  }

  @Override
  public String toString() {
    return super.toString() + " id: " + id;
  }
}

//----
class Library{
  private ArrayList<ReservedBook> reserved;
  // Add instance variables, methods, and override toString() method
  
  //constructor
	public Library(){
      this.reserved = new ArrayList<>();
  }

	public void addReservedBook(String title, String subject){
      String rem = title.substring(1);
      String titleFirstLetter = title.substring(0,1);
      titleFirstLetter = titleFirstLetter.toUpperCase();
      rem = rem.toLowerCase();
      title = titleFirstLetter + rem;

      subject = subject.toLowerCase();

	  ReservedBook book = new ReservedBook(title,subject);
	  int current = 0;
	  for(int i = 0; i < reserved.size(); i++){
	    if(book.getTitle().compareTo(reserved.get(i).getTitle()) >= 0){
	      current = i;
        }
      }
	  for(int k = current; k < reserved.size() - current +1; k++){
          if(k == current){
            ReservedBook temp = reserved.get(k);
            reserved.set(k,book);
          }
      }
	}

  
	public boolean changeSubject(int id, String subject){

	  reserved.forEach((ReservedBook) -> if(ReservedBook.getId() == id){
	    ReservedBook.setSubject(subject);
      });

	}



}