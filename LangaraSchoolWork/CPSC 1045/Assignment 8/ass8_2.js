
// way 1
function visualize() {

    let vowels = [ "a", "e", "i", "o", "u"];
    let consonants = [ "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v","w", "x", "z"];
    let input = document.getElementById("sentence").value;
    let result = " ";
    let sentence = input.split("");

    for (let i = 0; i < sentence.length; i++) {

        if (vowels.includes(sentence[i])) {

            result += '<circle r="10" fill="black" cx="' + i * 40 + '"cy="60"/>';

        } else if (consonants.includes(sentence[i])) {

            result += '<rect width="20" height="20" x="' + i * 40 + '" y= "50" fill="black"/>';

        }

    }

    document.getElementById("visualization").innerHTML = result;
    
}
function changeVowelColor(event) {

    let visualizationArray = document.querySelectorAll("#visualization > circle")

    for (circle of visualizationArray){

       circle.setAttribute("fill",document.querySelector("#vowelColor").value);
        
        
    }
   
}
function changeConsonantColor(event) {

    let visualizationArray = document.querySelectorAll("#visualization > rect")
    

    for (rect of visualizationArray) {

        
        rect.setAttribute("fill",document.querySelector("#consonantColor").value);

    }

}