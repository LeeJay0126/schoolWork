function doubleChar(){

    let string = document.getElementById("stringInput").value;
    score = 0;
    let assign = string.split(" ");

    for(let i = 0; i < assign.length; i++){

        for (let j = 0; j < assign[i].length; j++){

            if(assign[i][j] === assign[i][j+1]){
                score += 1;
                break;
                
            }

        }

    }
    
    document.getElementById("answer").innerHTML = "There are " + score + "set(s) of double characters";

}