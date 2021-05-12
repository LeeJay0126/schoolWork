class cat{

    constructor(name,color,size,sound){
        this.name = name;
        this.color = color;
        this.size = size;
        this.sound = sound;
    }
    description(){
        return `Your cat is named ${this.name} and is of the color ${this.color}. It is a ${this.size} cat, and `;
    }

    emote(){
        return this.sound + " all the time";
    }

}


let catArray = [];

function addingCat(){

    let catName = document.querySelector("#name").value;
    let catColor = document.querySelector("#color").value;
    let catSize = document.querySelector("#size").value;
    let catSound = document.querySelector("#sound").value;

    if(catSize != "small" && catSize != "medium" && catSize != "large" ){
        catSize = "medium";
    }
    
    
    let myCat = new cat(catName,catColor,catSize,catSound);

    catArray.push (myCat);
    document.getElementById("savedCats").innerHTML = "";
    for (let i = 0; i < catArray.length; i ++){

        document.getElementById("savedCats").innerHTML += `<li onclick="catInfo(event)" value="` + catArray[i].name + `">` + catArray[i].name + `</li>`;

    }
    
    
   
    
}

function catInfo(event){

    let x = event.target;

    for (let i = 0; i < catArray.length; i++){

        let targetAttribute = x.getAttribute("value");
        let catAttribute = catArray[i].name;
        
        if(targetAttribute == catAttribute){
            document.getElementById("catInfo").innerHTML = catArray[i].description() + catArray[i].emote();
        }


    }

}

function redrawDiv(){

    catArray = [];
    document.getElementById("savedCats").innerHTML = "";

}

