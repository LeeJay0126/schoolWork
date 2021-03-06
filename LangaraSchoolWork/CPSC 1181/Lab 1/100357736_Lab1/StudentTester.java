import java.util.Scanner;

public class StudentTester{

    //@Override
    public static void main(String[] args){
        //**import scanner and read input for class student
        Scanner s = new Scanner(System.in);

        //** reading variable information needed for student
        System.out.print("Enter student's first name: ");
        String firstname = s.nextLine();
        System.out.print("Enter student's last name: ");
        String lastname = s.nextLine();
        System.out.print("Enter student's student number: ");
        int studentNo = s.nextInt();

        //** student constructor
        Student student = new Student(firstname,lastname,studentNo);


        //** test Student getName, geyStudentNumber(), getLoginId()
        student.setName(firstname,lastname);
        System.out.println(student.getName());
        System.out.println(student.getStudentNumber());
        System.out.println(student.getLoginId(firstname,lastname,studentNo));

        //** test Student getInfo()
        System.out.println(student.getInfo());

        //** test Student addQuiz and getAverage
        student.addQuiz(6.0);
        student.addQuiz(8.5);
        student.addQuiz(9.8);
        System.out.println(student.getQuizAverage());

        //**test String toString
        System.out.println(student);

        //** testing address class and set/getAddress method from student class
        //** reading variables
        System.out.println();
        System.out.println("We will test address class and address methods from student class now.");
        String aptNumber = "5989";
        String streetName = "Iona Dr";
        String cityName = "Vancouver";
        String provinceName = "BC";
        String postalCodeName = "V6T2Q2";

        //**testing address class
        Address myAddress = new Address(aptNumber, streetName, cityName, provinceName, postalCodeName);
        System.out.println(myAddress);

        //**testing address method in student class
        student.setAddress(myAddress.getNumber(), myAddress.getStreet(), myAddress.getCity(), myAddress.getProvince(),myAddress.getPostalCode());
        String studentAddress = student.getAddress();
        System.out.println(studentAddress);

    }

}
