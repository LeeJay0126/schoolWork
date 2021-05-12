

//get the string of points by getattribute, split the string and then use substring to get the x and y value and modify it to circle of square.

function accentCircle() {

    let polygonArray = document.querySelectorAll("#star > polygon");
    let result = "";

    for (polygon of polygonArray) {

        let pointsAttribute = polygon.getAttribute("points");
        let pointsArray = pointsAttribute.split(" ");


        for (let i = 0; i < pointsArray.length - 1; i++) {

            let point = pointsArray[i];
            let temp = point.split(",");
            let tokenX = temp[0];
            let tokenY = temp[1];
            let circleString = '<circle r="10" fill="black" cx="' + tokenX + '" cy="' + tokenY + '" />'

            result += circleString;


        }

    }


    document.getElementById("decorations").innerHTML = result;
    // if document.getElementById("decorations/star").innerHTML = result;, x and y value of the star is too big. where am I messing this up?

}
function accentSquare() {

    let polygonArray = document.querySelectorAll("#star > polygon");
    let result = "";

    for (polygon of polygonArray) {

        let pointsAttribute = polygon.getAttribute("points");
        let pointsArray = pointsAttribute.split(" ");


        for (let i = 0; i < pointsArray.length - 1; i++) {

            let point = pointsArray[i];
            let temp = point.split(",");
            let tokenX = temp[0];
            let tokenY = temp[1];
            let circleString = '<rect width="10" height="10" fill="blue" x="' + tokenX + '" y="' + tokenY + '" />'

            result += circleString;


        }

    }


    document.getElementById("decorations").innerHTML = result;
}