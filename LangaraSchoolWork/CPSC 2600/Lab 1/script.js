const polarBear = {
    name: "Polar Bear",
    location: "Arctic",
    numberOfLegs: 4
};

const brownBear = {
    name: "Brown Bear",
    location: "Woods",
    numberOfLegs: 4
};

const grizzlyBear = {
    name: "Grizzly Bear",
    location: "Woods",
    numberOfLegs: 4
};

const winnieThePoo = {
    name: "Winnie the Poo",
    location: "TV",
    numberOfLegs: 2
};

const data = {
    animals: [polarBear, brownBear, grizzlyBear]
};

data.animals.push(winnieThePoo);

const names = data.animals.map(animal => animal.name);

const renderButtons = () => {
    let buttons = document.getElementById("buttons");
    names.forEach((name) => {
        let button = document.createElement("button");
        button.innerHTML = name;
        button.setAttribute("onclick", `showDetails("${name}")`)
        buttons.appendChild(button);
    });
};

const showDetails = () => {
    let displayDetails = document.getElementById("details");
    
};