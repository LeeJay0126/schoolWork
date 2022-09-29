//Create an empty array to store the zoo's info
let zooArray = [];
//Creaete a constructor for the species

function species(name, count) {
	this.name = name;
	this.count = Number(count);
}
// const gorila = new species("gorila", 10);
// zooArray.push(gorila);

//Create a new species object and push it onto the array.  Then update the zoo list.
//You do not need to do any input validation
function addSpecies() {
	const name = document.getElementById("name").value;
	const count = document.getElementById("count").value;
	const specie = zooArray.find((element) => element.name === name);

	if(specie != undefined){
		specie.count += Number(count);
	}

	if(specie == undefined){
		const newAnimal = new species(name,count);
		zooArray.push(newAnimal);
	}

	createList();

}


//Create and set the HTML for the zoo unordered list
function createList() {
	let html = "";

	//loop through array adding a list item for each species
	for (let i = 0; i < zooArray.length; i++) {
		html += `<li>${zooArray[i].name}  :  ${zooArray[i].count} </li>`;
	}
	document.getElementById("zoo").innerHTML = html;
}

function removeSpecies() {
	const name = document.getElementById("name").value;
	const count = document.getElementById("count").value;
	
	for(var i = 0; i < zooArray.length; i++){
		if(zooArray[i].name == name){
			zooArray[i].count = zooArray[i].count -  count;
			break;
		}
	}

	if(zooArray[i].count <= 0){
		zooArray.splice(i,1);
	}

	createList();

}
