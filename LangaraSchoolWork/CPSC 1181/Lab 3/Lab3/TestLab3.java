public class TestLab3{
	public static void main(String[] args){
		
		/**
		*main method testing all classes
		*/
		
		System.out.println("Test Faculty:");
		Faculty f1 = new Faculty("jack palace","jpalace@gmail.com","804 123 5888","A101",68000.00, Status.PART_TIME);
		System.out.println(f1);
		
		Faculty f2 = new Faculty("jack palace","jpalace@gmail.com","804 123 5888");
		System.out.println(f2);

		f2.setStatus(Status.FULL_TIME);
		f2.getStatus().toString();
		f2.setOffice("C102");
		f2.setSalary(65000);
		System.out.println(f2);
		System.out.println(f2.getStatus());
		f2.setStatus(Status.PART_TIME);
		System.out.println(f2);

		System.out.println("------------");
		System.out.println("Test Person:");
		Person p1 = new Person("Mary Poppins","mpoppins@gmail.com", "604 123 4567");
		System.out.println(p1);
		Person p2 = new Person();
		System.out.println(p2);
		p2.modifyInfo("Jay Lee", "email@email.com","604 123 1234");
		System.out.println(p2);
		Person p3 = new Person("Jacob Jake","jacob@jake.com", "604 333 4444");
		System.out.println(p3.getName());
		System.out.println(p3.getEmail());
		System.out.println(p3.getPhoneNumber());
		System.out.println(p3);
		// add more test cases as required


		System.out.println("------------");
		System.out.println("Test Employee:");
		Employee e1 = new Employee("Bill Gates","bgates@gmail.com","641 888 7766","B303",45000.99);
		System.out.println(e1);
		Employee e2 = new Employee();
		System.out.println(e2);
		e2.setSalary(60000);
		System.out.println(e2.getSalary());
		e2.setOffice("F111");
		System.out.println(e2.getOffice());
		System.out.println(e2);
		e2.modifyInfo("Steve Jobs", "samsung@galaxy.com", "010 3501 3950");
		System.out.println(e2.getName());
		System.out.println(e2);
		
		// add more test cases as required


		System.out.println("------------");
		System.out.println("Test Staff:");
		Staff s1 = new Staff("Clark Gable","cgable@gmail.com","1 800 888 8888","XB02",85600);
		System.out.println(s1);
		Staff s2 = new Staff();
		System.out.println(s2);
		s2.setPosition("boss");
		s2.modifyInfo("Peter Pan", "wonder@land.com","604 111 2222");
		System.out.println(s2.getPosition());
		System.out.println(s2);
		
		// add more test cases as required


		


	}
	
}

enum Status{
	/**
	*enum Status
	*/
		TEMPORARY,
		PART_TIME,
		FULL_TIME
	}

class Person{
	/**
	*Class persons. super class for class employee.
	*@param name
	*@param email
	*@param phoneNumber
	*/
	private String name;
	private String email;
	private String phoneNumber;
	
	/**
	*empty constructor for Person class
	*takes no parameter
	*/
	public Person(){
		
		this("name", "email","phoneNumber");
		
	}
	/**
	*constructor for Person class that takes 3 parameters
	*@param name
	*@param email
	*@param phoneNumber
	*/
	public Person(String name, String email, String phoneNumber){
		
		this.name = name;
		this.email = email;
		this.phoneNumber = phoneNumber;
		
	}
	/**
	*method that modifies name, email, phonenumber parameters for the Person constructor
	*for Person class and all its sub classes
	*@param name
	*@param email
	@param phoneNumber
	*/
	public void modifyInfo(String name, String email, String phoneNumber){
		
		this.name = name;
		this.email = email;
		this.phoneNumber = phoneNumber;
		
	}
	/**
	gets name for class Persons and all sub classes
	*/
	public String getName(){
		
		return this.name;
		
	}
	/**
	get email forclass Persons and all sub classes
	*/
	public String getEmail(){
		return this.email;
	}
	/**
	get phoneNumer for class Persons and all sub classes
	*/
	public String getPhoneNumber(){
		return this.phoneNumber;
	}
	/**
	String toString() that will be used or will be based on for all its sub classes
	*/
	@Override
	public String toString(){
		return "name : " + name + ", email: " + email + ", phoneNumber: " + phoneNumber;
	}
	
}
/**
class Employee is a subclass of class Persons
and super class of class faculty and employee
*/
class Employee extends Person{
	
	private String office;
	private double salary;
	
	/**
	empty constructor
	*/
	public Employee(){
		
		this("name","email","phoneNumber");
		
	}
	/**
	constructor that takes name, email and phone number
	@param name
	@param email
	@param phonenumber
	*/
	public Employee(String name, String email, String phoneNumber){
		
		this(name,email,phoneNumber,"office",0);
		
	}
	/**
	constructor that takes name, email, phoneNumber, office and salary as a parameter
	@param name
	@param email
	@param phoneNumber
	@param office
	@param salary
	*/
	public Employee(String name, String email, String phoneNumber, String office, double salary){
		
		super(name,email,phoneNumber);
		this.office = office;
		this.salary = salary;
		
	}
	/**
	sets office for class employee and its sub classes
	*/
	public void setOffice(String office){
		
		this.office = office;
		
	}
	/**
	sets salary for class employee and its sub classes
	*/
	public void setSalary(double salary){
		
		this.salary = salary;
		
	}
	/**
	returns office for class employee and its sub classes
	*/
	public String getOffice(){
		return office;
		
	}
	/**
	returns salary for class employee and its sub classes
	*/
	public double getSalary(){
		return salary;
	}
	/**
	method String toString() that carries over from its super class + extra
	this will be carried on to its sub classes as well
	*/
	@Override
	public String toString(){
		
		return super.toString()+ ", office: " + office + ", salary : " + salary;
		
	}
	
}
/**
sub class of class employee
*/
class Faculty extends Employee{
	
	private Status status;
	
	/**
	empty constructor for class Faculty
	*/
	public Faculty(){
		
		this("name","email","phone number");
	}
	/**
	constructor that takes name, email, phone number
	@param name
	@param email
	@param phoneNumber
	*/
	public Faculty(String name, String email, String phoneNumber){
		
		this(name,email,phoneNumber,"office",0,Status.TEMPORARY);
	}
	/**
	constructor that takes name, email, phone number, office, salary, status
	@param name
	@param email
	@param phoneNumber
	@param office
	@param salary
	@param status
	*/
	public Faculty(String name, String email, String phoneNumber, String office, double salary, Status status){
		
		super(name,email,phoneNumber,office, salary);
		this.status = status;
		
	}
	/**
	sets status for the class
	*/
	public void setStatus(Status status){
		this.status = status;
		
	}
		/**
	returns status for the class
	*/
	public Status getStatus(){
		return this.status;
	}
	
	@Override
	public String toString(){
		
		return super.toString() + ", Status: " + status;
		
	}
	
}
/**
sub class of class employee
*/
class Staff extends Employee{
	
	private String position;
	/**
	empty constructor for class Staff
	*/
	public Staff(){
		this("name","email","phone number");
	}
	/**
	constructor for staff that takes name, email, phonenumber as a parameter
	@param name
	@param email
	@param phonenumber
	*/
	public Staff(String name, String email, String phoneNumber){
		this(name,email,phoneNumber,"office",0);
	}
	/**
	constructor for staff that takes name, email, phonenumber, office, and salary as a parameter
	@param name
	@param email
	@param phonenumber
	@param office
	@param salary
	*/
	public Staff(String name, String email, String phoneNumber, String office, double salary){
		super(name,email,phoneNumber,office, salary);
		
	}
	/**
	sets position for class Staff
	*/
	public void setPosition(String position){
		this.position = position;
	}
	/**
	returns position for class Staff
	*/
	public String getPosition(){
		return position;
	}
	
	@Override
	public String toString(){
		return super.toString();
	}
	
}