package sample;

public class Address {

    private String number;
    private String street;
    private String city;
    private String province;
    private String postalCode;

    //constructor
    public Address(String aptNumber, String streetName, String cityName, String provinceName, String postalCodeName){

        number = aptNumber;
        street = streetName;
        city = cityName;
        province = provinceName;
        postalCode = postalCodeName;

    }
    public String getNumber(){
        return number;
    }

    public String getStreet(){
        return street;
    }

    public String getCity(){
        return city;
    }

    public String getProvince(){
        return province;
    }

    public String getPostalCode(){
        return postalCode;
    }

     public String toString(){
         return number + ", " + street + ", " + city + ", " + province + ", " + postalCode;
     }

}
