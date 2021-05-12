
//Check if option is check, return value if checked
//otherwise return zero. This allow us to use the 
//function inside an string of additions.
function optionValueById(optionid,value){
    let optionInput = document.querySelector("#"+optionid);
    if(optionInput.checked){
       return value;
    } else {
       return 0;
    }

}

function calculate(){
   
   let total = 5 + optionValueById("cheese",1)
               +optionValueById("tomatoe",0.75)
               +optionValueById("lettuce",2.00)
               +optionValueById("mushrooms",1.50);

   let element = document.querySelector("#total");
   element.innerHTML = total.toFixed(2);
}