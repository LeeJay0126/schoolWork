
const infoButton = document.getElementById('info');
const infoCloseButton = document.getElementById("close");
const aside = document.querySelector("aside");
const photoDiv = document.getElementById("photos");

infoButton.addEventListener("click", handleInfoToggle);
infoCloseButton.addEventListener("click", handleInfoToggle);


function handleInfoToggle() {
    aside.classList.toggle("visible");
}

function populateImages(subject){
    
}
