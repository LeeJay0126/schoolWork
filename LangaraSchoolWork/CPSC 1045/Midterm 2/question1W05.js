/*Remember that array indexes in computer science starts from 0 */
/*While humnan language usually starts indexes at 1 */

function verify() {


    let textInput = document.querySelector("#message").value;
    textSentence = textInput.split(".");
    let result = "";
    let msg = document.querySelector("#secretMessage").value;
    let secretMsg = msg.split("");

    for (let i = 0; i < textSentence.length; i++) {


        sentenceSplit = textSentence[i].split(" ");
        let n = Number(document.querySelector("#n").value);
        let j = Number(document.querySelector("#l").value);
        let nthWord = sentenceSplit[n-1];
        console.log(nthWord);
        let nthWordString = nthWord.split("");
        let msgLetter = nthWordString[j-1];
        

        result += msgLetter;
        



    }


    if (result == secretMsg) {
        document.querySelector("#output").innerHTML = "Message is Valid";
    } else {
        document.querySelector("#output").innerHTML = "Message is Not Valid"
    }

    console.log(result);
}