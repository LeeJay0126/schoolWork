
//Comparing this file with storeExample.js
//see how much shorter it is.
  
function totalFromAmt(amt, price){
   let total = amt * price;
   if (amt > 5 && amt <= 10) {
      total = total * 0.9; //10% off

   } else if (amt > 10) {
      total = total * 0.8
   }
   return total;

}
function totalFromId(itemID, price, outputID){
   //Input from page
   let amtInput = document.querySelector("#"+itemID);
   let amt = Number(amtInput.value);   
   
   //Calculation of total
   let total = totalFromAmt(amt, price);

   //Output to page
   let output = document.querySelector("#"+outputID);
   output.innerHTML = total;
   //output to others parts of the program
   return total;
}

function calculate() {

   //Think of about how much easier this is to read, that the version in 
   //storeExample.js
   //With less code, and more easily read code. 
   //You are less likely to make mistakes, and it is easier to find mistakes
   let subtotal1 = totalFromId("item1", 5, "price1");
   let subtotal2 = totalFromId("item2", 6, "price2");
   let subtotal3 = totalFromId("item3", 7, "price3");

   total = subtotal1 + subtotal2 + subtotal3;
   let output = document.querySelector("#total");
   output.innerHTML = total;
}