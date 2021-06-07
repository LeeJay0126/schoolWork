public class Faculty extends Employee{
	
	private Status status;
	
	public Faculty(){
		
		Faculty("name","email","phone number",0,status.TEMPORARY);
	}
	
	public Faculty(String name, String email, String phoneNumber){
		
		Faculty(name,email,phoneNumber,0,status.TEMPORARY);
	}
	
	public Faculty(String name, String email, String phoneNumber, String office, double salary, Status status){
		
		super(name,email,phoneNumber,office, salary);
		this.status = status;
		
	}
	
	public void setStatus(Status status){
		this.status = status;
		
	}
	
	public void getStatus(Status status){
		return status;
	}
	
	@Override
	public String toString(){
		
	}
	
}