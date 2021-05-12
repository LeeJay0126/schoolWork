function triangle(){

    let sentence = document.getElementById("inputString").value;
    let splitSentence = sentence.split(" ");
    let score = 0;

    for (i = 0; i < splitSentence.length; i++){
        console.log(splitSentence[i]);
        if (splitSentence[i].length + 1 == splitSentence[i+1].length){
            score +=1;
        }

    }

    if(score == splitSentence.length){

        for(let i = 0; i < splitSentence.length; i++){
            document.getElementById("answer").innerHTML = "The string is triangular:" + "  " + splitSentence[i] ;
        }

    }else{
        document.getElementById("answer").innerHTML = "The string is not triangular";
    }

}