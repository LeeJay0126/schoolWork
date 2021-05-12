//Starter file for Assignment3_2
let mass = 10;
let originalVelocityX = 10; 
let originalVelocityY = 15;

function calcAcceleration(force, mass) {
   //**You code goes here. 

   // The function should calculate and return the acceleration.
   //Parameters already provided.

   let acceleration = force / mass;
   return acceleration;
}

//Simple function to check if the calcAcceleation function is 
//working correctly, automating test saves repetive work of manual testing.
function testAcceleration() {
   let testForce = 5;
   let testMass = 2;
   let expectedAnswer = 2.5;
   //The if statement is the test, we'll cover later in the course
   if (calcAcceleration(testForce, testMass) == expectedAnswer) {
      console.log("The calcAcceleration function is producing the correct result for one test case");
   } else {
      console.log("The calcAcceleration function either not implemented or producing the wrong result");
   }
   testAcceleration(); //invoke testAcceleration so it runs at beginning of the program

   //Velcocity calculation for a single direction
}

function calcVelocity(originalVelocity, time, acceleration) {
   //**Your code goes here and modify the parameter list to take the correct inputs
   let velocity = originalVelocity + time * acceleration;
   return velocity;
}



//Position calculation for a single direction
function calcPosition(originalPosition, velocity, time) {
   //**Your code goes here and modify the parameter list to take the correct inputs

   let newPositionX = originalPosition + velocity * time;
   return newPositionX;


}


//The getInformation is provided, it gets the information from the page
function getInformation() {
   let ball = document.querySelector("#ball");
   let px = Number(ball.getAttribute("cx"));
   let py = Number(ball.getAttribute("cy"));
   let vx = Number(ball.getAttribute("vx"));
   let vy = Number(ball.getAttribute("vy"));
   let mass = Number(ball.getAttribute("mass"));
   //Return an object, we'll discuss this later in the course.
   //But it allows me to group the information together.
   return {
      px: px,
      py: py,
      vx: vx,
      vy: vy,
      mass: mass
   }

}

//This function should update the information for the
//ball.  You will use setAttribute, to change the attribute
// of the ball.
function setInformation(pxnew, pynew, vxnew, vynew) {
   //Your code goes 

   let ballnew = document.getElementById("ball");
   ballnew.setAttribute("cx", pxnew);
   ballnew.setAttribute("cy", pynew);
   ballnew.setAttribute("vx", vxnew);
   ballnew.setAttribute("vy", vynew);

}



function mainProgram(px, py, vx, vy, mass, Fx, Fy, timestep) {
   //**Your code goes here
   //You will use your calc functions, and setInformation function
   //here to implement the program
   
   let axnew = calcAcceleration(Fx, mass);
   let aynew = calcAcceleration(Fy, mass);
   let vxnew = calcVelocity(vx, timestep, axnew);
   let vynew = calcVelocity(vy, timestep, aynew);
   let pxnew = calcPosition(px, vx, timestep);
   let pynew = calcPosition(py, vy, timestep);
   setInformation(pxnew, pynew, vxnew,vynew);

}

//Code to start the timer, when the user hits the start button.
let timer = false;
const max = 200; //simulation will run for 20s.
const step = 100;
let current = 0;
function start(event) {
   const timeStep = 1;
   if (!timer) {
      timer = setInterval(() => {
         let info = getInformation();
         let Fx = 1;
         let Fy = -9.5;
         mainProgram(info.px, info.py, info.vx, info.vy, info.mass, Fx, Fy, timeStep);
         current = current + 1;
         if (current >= max) {
            //Code to sto the timer
            clearInterval(timer);
            timer = false;
            current = 0;
            return;
         }
      }, step)
   }
}

function display(px,py,vx,vy) {
   let iv = 10;
   let iy = 15;
   let ipx = 0;
   let ipy = 0;
   let textToShow = "Initial velocity x is: " + iv + ", and initial velocity for y is: "
   + iy + "." + " Initial position for x is: " + ipx + ", and initial position for y is: " + ipy + ".";

   document.getElementById("textbox").setAttribute("value",textToShow);
}
display();