public class Employee extends Person{
	
	private String office;
	private double salary;
	
	public Employee(){
		
		this("name","email","phoneNumber");
		
	}
	
	public Employee(String name, String email, String phoneNumber){
		
		this(name,email,phoneNumber,"office","0");
		
	}
	
	public Employee(String name, String email, String phoneNumber, String office, double salary){
		
		super(name,email,phoneNumber);
		this.office = office;
		this.salary = salary;
		
	}
	
	public void setOffice(String office){
		
		this.office = office;
		
	}
	
	public void setSalary(double salary){
		
		this.salary = salary;
		
	}
	
	public String getOffice(){
		return office;
		
	}
	
	public double getSalary(){
		return salary;
	}
	
	@Override
	public String toString(){
		
		super();
		System.out.print(", office: " + office + ", salary : " + salary);
		
	}
	
}