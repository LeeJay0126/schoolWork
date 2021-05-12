function distance(centerTargetX, centerTargetY) {


   let pyth = Math.sqrt(Math.pow(150 - centerTargetX, 2) + Math.pow(150 - centerTargetY, 2));


   return pyth;




   //cx of the circle = 150
   //Using pythagoras equation
   //write the function to return the distance between two points

}


function calculateScore(dist) {


   if (dist <= 25) {
      return 20;
   } else if (dist > 25 && dist < 50) {
      return 15;
   } else if (dist >= 50 && dist < 75) {
      return 10;
   } else if (dist >= 75 && dist < 125) {
      return 5;
   } else {
      return 0;
   }
   //use this function to help determine the score 
   //of the arrow. The function should return either 0,5,10,15,20 based on dist input value.
   //dist represents the distance.

}



//optional
function createArrowTag(x, y) {



   let arrowTag = `<use href="#arrow" transform="translate(${x},${y})"/>`;
   return arrowTag;
   //You can optionally make a createArrowTag function
   //to simplify your code, or if you want to make fancier arrows.

}

//Helper function for generating random numbers.
function randomNumber(minNum, maxNum) {
   return minNum + (maxNum - minNum) * Math.random();
}

//Because we haven't introduced objects yet, all the work will go into
//The event listener for now. But there are better ways to structure this code.
function fireArrows(event) {
   let n = document.querySelector("#numArrows").value;
   let outputHTML = ""
   let scoreTotal = 0;
   //when exactly do you use .value??
   //Dont understand how to redraw SVG
   //seems like im using randomnumber only once in so that
   //it displays multiple arrows in same x and y value



   for (let i = 0; i < n; i++) {

      let x = randomNumber(1, 300);
      let y = randomNumber(1, 300);
      let dist = distance(x, y);
      outputHTML += createArrowTag(x, y);
      scoreTotal += Number(calculateScore(dist));

   }



   document.querySelector("#ammunition").innerHTML = outputHTML;
   document.querySelector("#score").innerHTML = Number(scoreTotal);
   //Hint: You will can to generate arrows, and calculate the score within the same loop
   //As with the previous part, it is better to generate the tags for multipe arrows as a string
   //and then insert the string into #ammunition group after the loop.
   //Use your calculateScore function to help with the scoring

}
