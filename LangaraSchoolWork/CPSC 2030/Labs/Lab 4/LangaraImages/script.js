const imgArray = ["langara.jpg", "c-building.jpg", "golfcourse.jpg", "students.jpg", "t-building.jpg"];
const captionArray = [
    "Beautiful Langara College", "Langara's c-building", "Langara's golf course", "Students of Langara College", "Langara's T-Building"
];

const imgPrefix = "images/";
let arrayCount = 0;

function prevImage(){
    if(arrayCount == 0){
        arrayCount = 4;
    }else{
        arrayCount -= 1;
    }

    document.getElementById("langara").src = imgPrefix + imgArray[arrayCount];
    document.getElementById("caption").innerHTML = captionArray[arrayCount];
}

function nextImage(){
    if(arrayCount == 4){
        arrayCount = 0;
    }else{
        arrayCount += 1;
    }

    document.getElementById("langara").src = imgPrefix + imgArray[arrayCount];
    document.getElementById("caption").innerHTML = captionArray[arrayCount];
}