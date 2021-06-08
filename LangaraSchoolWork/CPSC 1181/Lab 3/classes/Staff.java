public class Staff extends Employee{
	
	private String position;
	
	public Staff(){
		Staff("name","email","phone number");
	}
	
	public Staff(String name, String email, String phoneNumber){
		Staff(name,email,phoneNumber,"office",0,"position");
	}
	
	public Staff(String name, String email, String phoneNumber, String office, double salary){
		super(name,email,phoneNumber,office, salary);
		
	}
	
	public void setPosition(String position){
		this.position = position;
	}
	
	public String getPosition(){
		return position;
	}
	
	@Override
	String toString(){
		super();
	}
	
}