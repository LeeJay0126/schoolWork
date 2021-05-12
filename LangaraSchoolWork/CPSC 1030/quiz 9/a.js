function bmiCalculator(){

    let height = Number(document.getElementById("height").value)/100;
    let weight = Number(document.getElementById("weight").value);

    let display = weight / (height * height);

    document.getElementById("display").innerHTML = "Your BMI is " + display;


}