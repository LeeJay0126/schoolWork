function createUseString(id, x, y) {

   let useTag = `<use href="#${id}" transform="translate(${x},${y})"/>`;
   return useTag;




   //create a function that generates a use tag
   //that uses the id, and transform the tag by x and y
   //remember to return the string

}


//Use this function to generate numbers between
//the minimum and maximum values, in the createMultipleTags 
//function.
function randomNumber(minNum, maxNum) {
   return minNum + (maxNum - minNum) * Math.random();
}

function createMultipleTags(id, n, minX, maxX, minY, maxY) {
   
   let multiTags = "";

   for (let i = 0; i < n; i++) {
      
      let x = randomNumber(minX, maxX);
      let y = randomNumber(minY, maxY);
      multiTags += createUseString(id, x, y);
     

   }

   return multiTags;
   //create a function the generates as string
   //That represents n use tags for the id, and at
   //random locations, between the bounding box
   //defined by minX, maxX, minY, maxY
   //use the randomNumber function to generate a single 
   //number between a given range.

   //remember to return the string

}


function generateFish(event) {

   

   let fishOutPutHTML = createMultipleTags("fish", document.getElementById("numFishes").value, 0, 400, 100, 400);

   document.querySelector("#animals").innerHTML = fishOutPutHTML;





   //Using the #numFishes input from the html page
   //generate that many Fishes  within the blue area
   //of the drawing.  
   //Use the functions you've written above to create the tags.
   //Then insert them into the #animals group.

}


function generatePlant(event) {


   htmlOutPut1 = createMultipleTags("seaweed", document.getElementById("numPlants").value, 0, 400, 100, 200);
   
   document.querySelector("#plants").innerHTML = htmlOutPut1;


   //Using the #numPlants input from the html page
   //generate that many Plant  within the blue area
   //of the drawing.  
   //Use the functions you've written above to create the tags.
   //Then insert them into the #plants group.

}

