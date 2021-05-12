


// I could do it with parameters, but to test my code more conveniently, I decided not to

function startButton(){

    let string = document.getElementById("stringValue").value;
    let stringArray = string.split("");
    points = 0;

    if(stringArray.includes("a")|| stringArray.includes("A")){
        points += 1;
    } if(stringArray.includes("b")|| stringArray.includes("B")){
        points += 1;
    } if(stringArray.includes("c")|| stringArray.includes("C")){
        points += 1;
    } if(stringArray.includes("d")|| stringArray.includes("D")){
        points += 1;
    } if(stringArray.includes("e")|| stringArray.includes("E")){
        points += 1;
    } if(stringArray.includes("f")|| stringArray.includes("F")){
        points += 1;
    }
    if(stringArray.includes("g")|| stringArray.includes("G")){
        points += 1;
    } if(stringArray.includes("h")|| stringArray.includes("H")){
        points += 1;
    } if(stringArray.includes("i")|| stringArray.includes("I")){
        points += 1;
    } if(stringArray.includes("j")|| stringArray.includes("J")){
        points += 1;
    } if(stringArray.includes("k")|| stringArray.includes("K")){
        points += 1;
    } if(stringArray.includes("l")|| stringArray.includes("L")){
        points += 1;
    } if(stringArray.includes("m")|| stringArray.includes("M")){
        points += 1;
    } if(stringArray.includes("n")|| stringArray.includes("N")){
        points += 1;
    } if(stringArray.includes("o")|| stringArray.includes("O")){
        points += 1;
    } if(stringArray.includes("p")|| stringArray.includes("P")){
        points += 1;
    } if(stringArray.includes("q")|| stringArray.includes("Q")){
        points += 1;
    } if(stringArray.includes("r")|| stringArray.includes("R")){
        points += 1;
    } if(stringArray.includes("s")|| stringArray.includes("S")){
        points += 1;
    } if(stringArray.includes("t")|| stringArray.includes("T")){
        points += 1;
    } if(stringArray.includes("u")|| stringArray.includes("U")){
        points += 1;
    } if(stringArray.includes("v")|| stringArray.includes("V")){
        points += 1;
    } if(stringArray.includes("w")|| stringArray.includes("W")){
        points += 1;
    } if(stringArray.includes("x")|| stringArray.includes("X")){
        points += 1;
    } if(stringArray.includes("y")|| stringArray.includes("Y")){
        points += 1;
    } if(stringArray.includes("z")|| stringArray.includes("Z")){
        points += 1;
    }

    if(points > 13){
        document.getElementById("result").innerHTML = "Includes more than 50% of the alphabets";
    }else{
        document.getElementById("result").innerHTML = "false";
    }
}