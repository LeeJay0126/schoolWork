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
    name: "Winnie The Poo",
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

const showDetails = (name) => {
    const displayDetails = document.getElementById("details");
    const animal = data.animals.find(d => d.name === name);
    let {numberOfLegs, location} = animal;
    const string = `The animal ${name} lives in the ${location} and has ${numberOfLegs} legs.`;
    displayDetails.innerHTML = string;
};