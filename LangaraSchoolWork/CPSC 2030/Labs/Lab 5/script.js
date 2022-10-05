
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
    photoDiv.innerHTML = "";

    for(let i = 0; i < 13; i++){
        const height = Math.ceil(500 + Math.random()*200);
        photoDiv.innerHTML += `<img src="https://source.unsplash.com/440x${height}/?${subject}" alt ="${subject}"></img>`;
    }

}

function subjectButtonClickHandler(e){
    const target = e.currentTarget.textContent;
    populateImages(target);
}

const buttonContainer = document.querySelector("#subjects");
const buttons = buttonContainer.querySelectorAll('button');

for(let i = 0; i < buttons.length; i++){
    buttons[i].addEventListener("click",subjectButtonClickHandler);
}
