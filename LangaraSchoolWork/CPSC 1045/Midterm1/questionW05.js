let circ1 = document.querySelector("#xl");
let circ2 = document.querySelector("#xr");
let circ3 = document.querySelector("#yt");
let circ4 = document.querySelector("#yb");
let greenZoneX1 = box.getAttribute("x");
let greenZoneY = box.getAttribute("y");
let rectW = box.getAttribute("width");
let rectH = box.getAttribute("height");


function isCircleInRect(circ1,circ2,circ3,circ4, rect){
    
    if(circ1.getAttribute("cx") > greenZoneX1 ){
        let c1 = 1;
    }else {
        let c1= 0;
    }

    if(circ2.getAttribute("cx") < greenZoneX1 + rectW){
        let c2 = 1;
    }else{
        let c2 = 0;
    }

    if (circ3.getAttribute("cy") > greenZoneY){
        let c3 = 1;
    }else {
        let c3 = 0;
    }

    if (circ4.getAttribute("cy") < greenZoneY + rectH){
        let c4 = 1;
    }else {
        let c4 = 0;
    }

    if (c1+c2+c3+c4 == 1){
        circ1.setAttribute("fill","red");
        circ2.setAttribute("fill","red");
        circ3.setAttribute("fill","red");
        circ4.setAttribute("fill","red");
    }else{
        circ1.setAttribute("fill","black");
        circ1.setAttribute("fill","black");
        circ1.setAttribute("fill","black");
        circ1.setAttribute("fill","black");
    }

  
}


function sliderXListener(event) {

    let sliderX = document.querySelector("#xSlider");

    circ1.setAttribute("cx", sliderX.value);
    circ2.setAttribute("cx", 200 - sliderX.value);

    isCircleInRect(circ1, circ2, circ3, circ4);
    





}

function sliderYListener(event) {

    let sliderY = document.querySelector("#ySlider");

    circ3.setAttribute("cy", sliderY.value);
    circ4.setAttribute("cy", 200 - sliderY.value);

    isCircleInRect(circ1, circ2, circ3, circ4);
}
