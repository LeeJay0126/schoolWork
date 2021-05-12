let scoreArray = [];
// Im going to use this Array when I'm working on the play button using a loop. 
// so something like using the listKey below and listKey.length and push them in to the array and play it.
function keyboardInput(event) {

    var x = event.target;
    let keyboardId = x.getAttribute("id");
    let score = "";

    if (keyboardId == "A") {
        scoreArray.push("A");
        synth.playNote("A");
    } else if (keyboardId == "B") {
        scoreArray.push("B");
        synth.playNote("B");
    } else if (keyboardId == "C") {
        scoreArray.push("C");
        synth.playNote("C");
    } else if (keyboardId == "D") {
        scoreArray.push("D");
        synth.playNote("D");
    } else if (keyboardId == "E") {
        scoreArray.push("E");
        synth.playNote("E");
    } else if (keyboardId == "F") {
        scoreArray.push("F");
        synth.playNote("F");
    }

    if (scoreArray.length > 16) {

        scoreArray.shift();

    }
    let circleString = "";


    for (let i = 0; i < scoreArray.length; i++) {

        if (scoreArray[i] == "A") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",0)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + i * 30 + ",20)'/>";
        } else if (scoreArray[i] == "B") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",-10)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + 30 + ",14)'/>";
        } else if (scoreArray[i] == "C") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",-20)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + 60 + ",8)'/>";
        } else if (scoreArray[i] == "D") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",-30)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + 90 + ",2)'/>";
        } else if (scoreArray[i] == "E") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",-40)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + 120 + ",39)'/>";
        } else if (scoreArray[i] == "F") {
            score += "<use href='#note' transform = 'translate(" + i * 37 + ",-50)'/>";
            circleString += "<use href='#smallCircles' transform ='translate(" + 150 + ",11)'/>";
        }

     

        document.getElementById("circlescircle").innerHTML = circleString;
        
       

    }


    document.getElementById("notesScore").innerHTML = score;


}

async function playButton() {
    //It does play the note, but it plays everything so fast that it sounds like a single note.

    for (let i = 0; i < scoreArray.length; i++) {

        if (scoreArray[i] == "A") {
            await synth.playNote("A");
        } else if (scoreArray[i] == "B") {
            await synth.playNote("B");
        } else if (scoreArray[i] == "C") {
            await synth.playNote("C");
        } else if (scoreArray[i] == "D") {
            await synth.playNote("D");
        } else if (scoreArray[i] == "E") {
            await synth.playNote("E");
        } else if (scoreArray[i] == "F") {
            await synth.playNote("F");
        }

    }
}

function resetButton() {

    scoreArray = [];
    score = "";

    document.getElementById("notesScore").innerHTML = score;
    document.getElementById("circlescircle").innerHTML = "";

}