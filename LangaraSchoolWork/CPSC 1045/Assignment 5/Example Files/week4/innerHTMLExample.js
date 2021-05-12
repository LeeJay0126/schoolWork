function insertText(){
    let divElement = document.querySelector("#textLocation");
    divElement.innerHTML = "This text was inserted after you clicked the button."
}



function multiplyValue(parameter1, parameter2){

    return Number(parameter1)*Number(parameter2);
}

let total = multiplyValue(5,6)+55+234;