function returnArray(){

    let inputArray = document.getElementById("arrays").value;
    let splitArray = inputArray.split(",");
    let emptyArray = [];

    for(let i = 0; i < splitArray.length; i++){

        if(splitArray[i] > 5){
            emptyArray.push(splitArray[i]);
        }

    }
    document.getElementById("result").innerHTML = emptyArray;
}