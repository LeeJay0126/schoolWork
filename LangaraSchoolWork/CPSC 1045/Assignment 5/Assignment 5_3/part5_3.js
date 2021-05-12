
//This function will tell you if the check box is checked or not
function checker(idName) {

    let optionInput = document.querySelector(idName);
    if (optionInput.checked) {
        return 1;
    } else {
        return 0;
    }

}

//This function will tell you if the item you are bringing meets the maximum requirement for its' length, width, height
function eligibilityTest(required, item) {

    if (item >= required) {
        return 0;
    } else{
        return 1;
    }
}




//Main program
//Question is, can we store values from if/else statements to later add them up
function check() {

    let isValid1 = false;
    let isValid2 = false;
    let isValid3 = false;
    let isValid4 = false;
    let isValid5 = false;
    let isValid6 = false;
    let isValid7 = false;
    let isValid8 = false;

    //For Personal Items
    if (checker("#check1") == 1) {

        let length1 = eligibilityTest(+33, +document.getElementById("text1").value);
        let width1 = eligibilityTest(+16, +document.getElementById("text2").value);
        let height1 = eligibilityTest(+43, +document.getElementById("text3").value);
        console.log(length1 + width1 + height1);
        if ((length1 + width1 + height1) < 3) {

            document.getElementById("showEligibility1").innerHTML = "Your Personal Item is too big ."
            isValid1 = false;
            
        } else  {
            isValid1 = true;
         }

    } else {
        isValid1 = true;
    }


    //For Standard Items

    if (checker("#check2") == 1) {

        let length2 = eligibilityTest(55, +document.getElementById("text4").value);
        let width2 = eligibilityTest(23, document.getElementById("text5").value);
        let height2 = eligibilityTest(40, document.getElementById("text6").value);
        if ((length2 + width2 + height2) >= 1) {

            document.getElementById("showEligibility2").innerHTML = "Your Standard Item is too big .";
            isValid2 = false;
        } else {
            isValid2 = true;
        }


    }else {
        isValid2 = true;
    }

    // Gel/Liquid Items
    let yourLiquid = +document.querySelector("#text7").value;
    if (yourLiquid >= 100) {

        document.getElementById("showEligibility3").innerHTML = "You can not bring liquid or gel over 100grams or ml";
        isValid3 = false;
        
    } else {
        
        isValid3 = true;
    }



    //Check boxes for other things

    if (checker("#check3") == 1) {

        document.getElementById("showEligibility4").innerHTML = "You can not bring fuel tablets";
        isValid4 = false;
    } else {
        isValid4 = true;
    }




    if (checker("#check4") == 1) {

        document.getElementById("showEligibility5").innerHTML = "You can not bring gas cartridges";
        isValid5 = false;
    }else {
        isValid5 = true;
    }



    if (checker("#check5") == 1) {

        document.getElementById("showEligibility6").innerHTML = "You can not bring paints";
        isValid6 = false;
    } else {
        isValid6 = true;
    }




    if (checker("#check6") == 1) {

        document.getElementById("showEligibility7").innerHTML = "You can not bring blades exceeding 3cm";
        isValid7 = false;
    } else {
        isValid7 = true;
    }


    if (checker("#check7") == 1) {

        document.getElementById("showEligibility8").innerHTML = "You can not bring explosives";
        isValid8 = false;
    } else {
        isValid8 = true;
    }

    
    if (isValid1 && isValid2 && isValid3 && isValid4 && isValid5 && isValid6 && isValid7 && isValid8 ){

        document.getElementById("showEligibility9").innerHTML = "You are eligible";

    } else {
        document.getElementById("showEligibility9").innerHTML = "You are not eligible";
    }

    
    //Now i need to figure out how to add return values.


}











