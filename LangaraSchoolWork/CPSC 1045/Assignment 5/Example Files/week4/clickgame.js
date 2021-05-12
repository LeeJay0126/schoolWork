//global variables
//need globals to persist data beyond lifetime of 
//the function
let score = 0;

function gameListener(event){
   let element = event.target;
   let color = element.getAttribute("fill")
   
   if(color == "red"){
      score += 1;
   }else {
      score -= 1;
   }

   element.setAttribute("x", Math.random()*90);
   element.setAttribute("y", Math.random()*90);

   let scoreElement = document.querySelector("#score");
   scoreElement.innerHTML = score;
}