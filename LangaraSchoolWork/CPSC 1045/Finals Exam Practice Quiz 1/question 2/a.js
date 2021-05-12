function returnButton(){

    let stringInput = document.getElementById("stringInput").value;
    
    let wordArray = stringInput.split(" ");
    let newString = ""
 

   for ( let i = 0; i < wordArray.length; i++){

    let word = wordArray[i];
    console.log(wordArray);
    
    if(word[0] == "a" || word[0] == "A"){

        for ( let i = 0; i < word.length; i++){

            newString = word[i] + newString;
           // to replace a word in a paragraph, stringInput = stringInput.replace(word, newString); 

        }

    }

   }
    document.getElementById("return").innerHTML = newString;
}