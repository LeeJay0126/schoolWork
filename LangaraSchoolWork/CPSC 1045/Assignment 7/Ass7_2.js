function count() {
   
    let countCircle = 0;
    let countRed = 0;
    let countPurp = 0;
    let circleArray = document.querySelectorAll("#cluster > circle");

    for (let i = 0; i < circleArray.length; i++ ){

        countCircle += 1;

    }

    for (circle of circleArray) {

        if (circle.getAttribute("fill") == "red"){

            countRed += 1;

        }

    }
    
    for (circle of circleArray) {

        if (circle.getAttribute("fill") == "purple"){

            countPurp += 1;

        }

    }
    
    document.getElementById("numCircles").innerHTML = ": " + countCircle;
    document.getElementById("numRedCircles").innerHTML = ": " + countRed;
    document.getElementById("numPurpleCircles").innerHTML = ": " + countPurp;

    console.log(circleArray);
}

