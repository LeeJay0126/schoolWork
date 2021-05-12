//Please write the event listener and two helper functions here
//helper function 1: determines the next color based on the current color
//helper function 2: determines if all the colors are identical
//use the helper functions in the event listener



    
function helperFunction(circle){


    if (circle.getAttribute("fill") == "red"){
        
        circle.setAttribute("fill", "blue");

    }else if (circle.getAttribute("fill") == "blue"){

        circle.setAttribute("fill","orange");

    }else if (circle.getAttribute("fill") == "orange"){

        circle.setAttribute("fill","green");

    }else {

        circle.setAttribute("fill","red");

    }
    
}

function identicalChecker(circle1,circle2,circle3){
   
    if (circle1.getAttribute("fill")==circle2.getAttribute("fill")&&circle3.getAttribute("fill")==circle2.getAttribute("fill")&&circle2.getAttribute("fill")=="red"){
        document.getElementById("messageOutput").innerHTML = "All the same color";
    }else if(circle1.getAttribute("fill")==circle2.getAttribute("fill")&&circle3.getAttribute("fill")==circle2.getAttribute("fill")&&circle2.getAttribute("fill")=="blue"){
        document.getElementById("messageOutput").innerHTML = "All the same color";
    }else if(circle1.getAttribute("fill")==circle2.getAttribute("fill")&&circle3.getAttribute("fill")==circle2.getAttribute("fill")&&circle2.getAttribute("fill")=="green"){
        document.getElementById("messageOutput").innerHTML = "All the same color";
    }else if(circle1.getAttribute("fill")==circle2.getAttribute("fill")&&circle3.getAttribute("fill")==circle2.getAttribute("fill")&&circle2.getAttribute("fill")=="orange"){
        document.getElementById("messageOutput").innerHTML = "All the same color";
    }
}

function colorChange(event){
    
    let element = event.target;

   helperFunction(element);
   helperFunction(element);
   helperFunction(element);

   identicalChecker(document.getElementById("circle1"),document.getElementById("circle2"),document.getElementById("circle3"));

    
}