function calculate() {

   let amt1Input = document.querySelector("#item1");
   let amt1 = Number(amt1Input.value);
   let price1 = 5;
   let total1 = amt1 * price1;
   if (amt1 > 5 && amt1 <= 10) {
      total1 = total1 * 0.9; //10% off

   } else if (amt1 > 10) {
      total1 = total1 * 0.8
   }
   let output1 = document.querySelector("#price1");
   output1.innerHTML = total1;


   let amt2Input = document.querySelector("#item2");
   let amt2 = Number(amt2Input.value);
   let price2 = 6;
   let total2 = amt2 * price2;
   if (amt2 > 5 && amt2 <= 10) {
      total2 = total2 * 0.9; //10% off

   } else if (amt2 > 10) {
      total2 = total2 * 0.8
   }
   let output2 = document.querySelector("#price2");
   output2.innerHTML = total2;


   let amt3Input = document.querySelector("#item3");
   let amt3 = Number(amt3Input.value);
   let price3 = 7;
   let total3 = amt3 * price3;
   if (amt3 > 5 && amt3 <= 10) {
      total3 = total3 * 0.9; //10% off

   } else if (amt3 > 10) {
      total3 = total3 * 0.8
   }
   let output3 = document.querySelector("#price3");   
   output3.innerHTML = total3;




   let total = total1 + total2 + total3;
   let output = document.querySelector("#total");
   output.innerHTML = total;



}