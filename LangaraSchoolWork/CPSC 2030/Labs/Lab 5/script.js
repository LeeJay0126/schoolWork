const infoButton = document.getElementById('info');
const infoCloseButton = document.getElementById("close");
const aside = document.querySelector("aside");
let flag = false;

function handleInfoToggle(){
    flag = !flag;
    if(flag){
        console.log(flag);
        aside.style.display = "block";
    }
    if(!flag){
        aside.style.display = "none";
    }
}

console.log(infoButton);

infoButton.addEventListener("click",handleInfoToggle);
infoCloseButton.addEventListener("click",handleInfoToggle);
