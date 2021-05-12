
function change(event) {

    let circleArray = document.querySelectorAll("#tiles > .tile");
    var x = event.target;
    x.setAttribute("fill","orange");

    for (circle of circleArray){

        let circleCy = circle.getAttribute("cy");
        let circleCx = circle.getAttribute("cx");
        let targetCx = x.getAttribute("cx");
        let targetCy = x.getAttribute("cy");

        if(circleCx == targetCx && circleCy == targetCy){
            circle.setAttribute("fill","orange");
        }else if(circleCy == targetCy){
            circle.setAttribute("fill","blue");
        }else if(circleCx == targetCx){
            circle.setAttribute("fill","red");
        }


    }
        
    

}