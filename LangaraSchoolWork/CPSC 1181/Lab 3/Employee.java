public class Employee extends Person{
	
	private String office;
	private double salary;
	
	public Employee(){
		
		Employee("name","email","phoneNumber");
		
	}
	
	public Employee(String name, String email, String phoneNumber){
		
		Employee(name,email,phoneNumber,"office","0");
		
	}
	
	public Employee(String name, String email, String phoneNumber, String office, double salary){
		
		super(name,email,phoneNumber);
		this.office = office;
		this.salary = salary;
		
	}
	
	
}