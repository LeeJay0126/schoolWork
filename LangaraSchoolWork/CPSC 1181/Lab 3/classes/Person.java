public class Person{
	
	enum Status{
	
		TEMPORARY;
		PART_TIME;
		FULL_TIME;
	}
	
	
	private String name;
	private String email;
	private String phoneNumber;
	
	
	public Person(){
		
		this("name", "email","phoneNumber");
		
	}
	
	public Person(String name, String email, String phoneNumber){
		
		this.name = name;
		this.email = email;
		this.phoneNumber = phoneNumber;
		
	}
	
	public void modifyInfo(String name, String email, String phoneNumber){
		
		this.name = name;
		this.email = email;
		this.phoneNumber = phoneNumber;
		
	}
	
	public String getName(){
		
		return this.name;
		
	}
	
	public String getEmail(){
		return this.email;
	}
	
	public String getPhoneNumber(){
		return this.phoneNumber;
	}
	
	@Override
	public String toString(){
		System.out.print("name : " + name + ", email: " + email + ", phoneNumber: " + phoneNumber);
	}
	
}