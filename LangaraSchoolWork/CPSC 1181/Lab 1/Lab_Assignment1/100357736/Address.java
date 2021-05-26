package sample;

public class Address {
    /**
     * private variables for class Address
     */
    private String number;
    private String street;
    private String city;
    private String province;
    private String postalCode;

    /**
     * constructor for class Address
     * @param aptNumber
     * @param streetName
     * @param cityName
     * @param provinceName
     * @param postalCodeName
     */
    public Address(String aptNumber, String streetName, String cityName, String provinceName, String postalCodeName){

        number = aptNumber;
        street = streetName;
        city = cityName;
        province = provinceName;
        postalCode = postalCodeName;

    }

    /**
     * returns building number
     * @return
     */
    public String getNumber(){
        return number;
    }

    /**
     * returns street name
     * @return
     */
    public String getStreet(){
        return street;
    }

    /**
     * returns city name
     * @return
     */
    public String getCity(){
        return city;
    }

    /**
     * returns province name
     * @return
     */
    public String getProvince(){
        return province;
    }

    /**
     * returns postal code
     * @return
     */
    public String getPostalCode(){
        return postalCode;
    }

    /**
     * returns string for the constructor
     * @return
     */
     public String toString(){
         return number + ", " + street + ", " + city + ", " + province + ", " + postalCode;
     }

}
