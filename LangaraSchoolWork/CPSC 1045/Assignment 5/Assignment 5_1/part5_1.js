const udefString = "undefined";
function question1(num, n) {
   return !(n == num.toString().length);
}

function question2(greenOnion, chilliJam, rice, oliveOil,
   egg, tofu, salt, water) {

   return greenOnion <= 1/2 || chilliJam <= 1 || rice <= 2 || oliveOil <= 2 || water <= 1 || tofu <= 1/2 || egg <= 2 || salt <= 1;
}

function question3(chicken, lemonJuice, limeJuice, onionPowder, parsley, cilantro, salt, pepper) {
   //Becuase it's a long expression, you may want to have intermediate values stored in variables


   return chicken >= 4 && lemonJuice >= 1/2 && limeJuice >= 1/2 && onionPowder >= 1/2 && parsley >= 2 && cilantro > 1 && salt >= 1 && pepper >= 1;

}

//Tests: You don't need to examine this section of code, focus on the above lines
//This sections will contain functions to test the answer with some concrete values.
//It will print results to the console, and inform you if it thinks your boolean expressions are correct.
//No Guarantee they are right
function testQuestion1() {
   if (typeof (question1(0, 0)) == udefString) {
      console.log("function question1 returning undefined, check the return statement.")
      return;
   }

   //test 1, for 1 digit
   if (!question1(0, 1)) {
      console.log("Testing Question1, okay. Checking for 1 digit")
   }
   else {
      console.log("One of the test for question one failed, please check your expression");
   }
   //Test 1 for 1 digit
   if (!question1(5, 1)) {
      console.log("Testing Question1, okay. Checking for 1 digit")
   }
   else {
      console.log("One of the test for question one failed, please check your expression");
   }

   //test 2, test for 2 digits
   if (!question1(99, 2)) {
      console.log("Testing Question1, okay. Checking for 2 digit")
   }
   else {
      console.log("One of the test for question one failed, please check your expression");
   }

   //test 2, test for 2 digits
   if (!question1(563, 3)) {
      console.log("Testing Question1, okay. Checking for 2 digit")
   }
   else {
      console.log("One of the test for question one failed, please check your expression");
   }

   //test 2, test for 13 digits
   if (!question1(1000000000234, 13)) {
      console.log("Testing Question1, okay. Checking for 2 digit")
   }
   else {
      console.log("One of the test for question one failed, please check your expression");
   }
}
function testQuestion2() {
   if (typeof (question2(0, 0, 0, 0)) == udefString) {
      console.log("function question2 returning undefined, check the return statement.")
      return;
   }

   let ing = {
      greenOnion: 8,
      chilliJam: 10,
      rice: 5,
      oliveOil: 2,
      egg: 3,
      tofu: 1,
      salt: 5,
      water: 10
   }
   let keys = Object.keys(ing);
   if (question2(ing.greenOnion, ing.chilliJam, ing.rice, ing.oliveOil,
      ing.egg, ing.tofu, ing.salt, ing.water) == false) {
      console.log("Passed case you dont' need to go shopping")
   } else {
      console.log("failed case you dont' need to go shopping")
   }

   for (let i = 0; i < keys.length; i++) {
      let tmpIng = JSON.parse(JSON.stringify(ing)); //deep copy object
      tmpIng[keys[i]] = 0;
      if (question2(tmpIng.greenOnion, tmpIng.chilliJam, tmpIng.rice, tmpIng.oliveOil,
         tmpIng.egg, tmpIng.tofu, tmpIng.salt, tmpIng.water) == true) {
         console.log("Question 2:Passed case where you need to go shopping for" + keys[i])
      } else {
         console.log("Question 2:failed case where you need to go shopping for" + keys[i])
      }
   }

}
function testQuestion3() {
   if (typeof (question3(0, 0, 0, 0, 0, 0, 0, 0)) == udefString) {
      console.log("function question 3 returning undefined, check the return statement.")
      return;
   }
   let keys = ["breasts", "lemonJuice", "onionPowder", "parsley", "salt", "pepper"]
   let ingredients = {
      breasts: 5,
      lemonJuice: 1,
      limeJuice: 0,
      onionPowder: 1,
      parsley: 3,
      cilantro: 0,
      salt: 5,
      pepper: 5
   }

   if (question3(ingredients.breasts, ingredients.lemonJuice, ingredients.limeJuice, ingredients.onionPowder, ingredients.parsley, ingredients.cilantro, ingredients.salt, ingredients.pepper) == true) {
      console.log("Question 3: Case of having the ingredients passed");
   } else {
      console.log("Question 3: Case of having the ingredients failed");
   }
   for (let i = 0; i < keys.length; i++) {
      let tempIng = JSON.parse(JSON.stringify(ingredients));
      tempIng[keys[i]] = 0;
      if (question3(tempIng.breasts, tempIng.lemonJuice, tempIng.limeJuice, tempIng.onionPowder, tempIng.parsley, tempIng.cilantro, tempIng.salt, tempIng.pepper) == false) {
         console.log("Question 3: Passed case where you need to go shopping for" + keys[i])
      } else {
         console.log("Question 3: failed case where you need to go shopping for" + keys[i])
      }

   }

   keys = ["breasts", "limeJuice", "onionPowder", "cilantro", "salt", "pepper"]
   ingredients = {
      breasts: 5,
      lemonJuice: 0,
      limeJuice: 2,
      onionPowder: 0.5,
      parsley: 0,
      cilantro: 3,
      salt: 5,
      pepper: 0
   }
   for (let i = 0; i < keys.length; i++) {
      let tempIng = JSON.parse(JSON.stringify(ingredients));
      tempIng[keys[i]] = 0;
      if (question3(tempIng.breasts, tempIng.lemonJuice, tempIng.limeJuice, tempIng.onionPowder, tempIng.parsley, tempIng.cilantro, tempIng.salt, tempIng.pepper) == false) {
         console.log("Question 3: Passed case where you need to go shopping for" + keys[i])
      } else {
         console.log("Question 3: failed case where you need to go shopping for" + keys[i])
      }

   }
}
//Invoke tests
testQuestion1();
testQuestion2();
testQuestion3();