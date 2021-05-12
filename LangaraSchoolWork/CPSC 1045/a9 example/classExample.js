class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
    clone() {
        return new Point(this.x, this.y);
    }
}
class Spaceship {
    constructor(detectionRadius, drawingString) {
        this.detectionRadius = detectionRadius; //expects a value
        this.location = new Point(0, 0); //expects a Point
        this.angle = 0;
        this.drawingString = drawingString;
        this.cloaking = false;
    }
    drawShip() { //translate the ship drawing
        if(this.cloaking){
            return "";
        } else {        
             return `<g transform="translate(${this.location.x},${this.location.y})
                              rotate(${this.angle})">
                   ${this.drawingString}
                </g>`
        }
    }
    toggleCloak(){
        this.cloaking = !this.cloaking;
    }
    cloak(flag){ //expects a boolean
        this.cloaking = flag;
    }
    rotateShip(angle) {
        this.angle += angle;
    }
    moveForward(amount){ //Move the ship in the foward facing direction.
        this.location.x += amount * Math.cos((-90+this.angle)*Math.PI/180);
        this.location.y += amount * Math.sin((-90+this.angle)*Math.PI/180);
    }
    moveShip(point) {//Expects a Point
        this.location.x += point.x;
        this.location.y += point.y;
    }
    placeShip(point, angle) { //Expects a Point
        this.location.x = point.x;
        this.location.y = point.y;
        this.angle = angle;
        this.cloak = false;
    }
}

let shipString1 = `<circle cx="0" cy="-10" r="7.5" fill="lightblue" />  
            <rect x="-10" y="-10" width="5" height="20" fill="blue" />
            <rect x="5" y="-10" width="5" height="20" fill="blue" />
            <rect x="-5" y="-10" width="10" height="15" fill="darkblue" />`

let shipString2 = `<circle cx="0" cy="-10" r="7.5" fill="lightblue" />  
            <rect x="-10" y="-10" width="5" height="20" fill="red" />
            <rect x="5" y="-10" width="5" height="20" fill="red" />
            <rect x="-5" y="-10" width="10" height="15" fill="darkred" />`

let ships = [ new Spaceship(20,shipString1),new Spaceship(20,shipString2)]  ;

function drawShips(){
    let group = document.querySelector("#ships");
    let output = "";
    for(let ship of ships){
        output += ship.drawShip();
    }
    group.innerHTML = output;
}
function setup(){
    ships[0].placeShip(new Point(100,200),90);
    ships[1].placeShip(new Point(100,300),90);
    drawShips();
}
function rotateLeft(event){
    let shipID = event.target.getAttribute("shipID");
    ships[shipID].rotateShip(-5);
    drawShips();
}
function rotateRight(event){
    let shipID = event.target.getAttribute("shipID");
    ships[shipID].rotateShip(5);
    drawShips();
}
function forward(event){
    let shipID = event.target.getAttribute("shipID");
    ships[shipID].moveForward(10);
    drawShips();
}
function cloak(event){
    let shipID = event.target.getAttribute("shipID");
    ships[shipID].toggleCloak();
    drawShips();
}

