//CPSC 1045-006, assignment 4, Part 1

//Part A
function traverseMountain(){
    let mountainX = document.querySelector("#circleA");
    let sliderMountain = document.querySelector("#inputA");
    mountainX.setAttribute("cx",sliderMountain.value);
    if ( 2 * sliderMountain.value > 201){
        mountainX.setAttribute("cy", sliderMountain.value);
    } else {
        mountainX.setAttribute("cy", 200 - sliderMountain.value);
    }
    

}

//Part B
function moveCircle(){
    let flagX = document.querySelector("#circleB");
    let sliderFlag = document.querySelector("#inputB");
    flagX.setAttribute("cx", sliderFlag.value);
    if (sliderFlag.value < 66){
        flagX.setAttribute("fill","red");
    }else if (sliderFlag.value > 133){
        flagX.setAttribute("fill","red");
    }
    else {
        flagX.setAttribute("fill","blue");
    }
}