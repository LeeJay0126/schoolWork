package sample;

public class Address {

    private String number;
    private String street;
    private String city;
    private String province;
    private String postalCode;

    //constructor
    public Address(String number, String street, String city, String province, String postalCode){



    }
    public String number(String aptNumber){
        number = aptNumber;
        return number;
    }

    public String street(String streetName){
        street = streetName;
        return street;
    }

    public String city(String cityName){
        city = cityName;
        return city;
    }

    public String province(String provinceName){
        province = provinceName;
        return province;
    }

    public String getPostalCode(String postalCodeName){
        postalCode = postalCodeName;
        return postalCode;
    }

}
