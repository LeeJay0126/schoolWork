
//Do not need to use the event object
//but we could.
//Either use event.target
//or document.querySelector
//to retrieve the element


function sliderListener() {

    let sliderX = document.querySelector("#rangeX");
    let circle1 = document.querySelector("#circle1");
    let circle2 = document.querySelector("#circle2")
    circle1.setAttribute("r", sliderX.value);
    circle2.setAttribute("r", 99 - sliderX.value);
    console.log();

}




//circle.setAttribute("cx", sliderX.value); << setting cx
//console.log(circle); << printing attributes of the circle