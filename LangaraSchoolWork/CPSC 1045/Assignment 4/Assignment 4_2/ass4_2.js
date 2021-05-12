let ans = 2;
let ans2 = 4;
let ans3 = 6;
let ans4 = 9;
let ans5 = 10;


function howToMark(answer, ans) {


    if (answer == ans) {
        return 1;
    } else {
        return 0;
    }
}


function markQuiz() {


    let quizmark1 = howToMark(document.getElementById("answer1").value, ans);
    let quizmark2 = howToMark(document.getElementById("answer2").value, ans2);
    let quizmark3 = howToMark(document.getElementById("answer3").value, ans3);
    let quizmark4 = howToMark(document.getElementById("answer4").value, ans4);
    let quizmark5 = howToMark(document.getElementById("answer5").value, ans5);

    let total = quizmark1 + quizmark2 + quizmark3 + quizmark4 + quizmark5;

    
    if (total == 5) {
        document.getElementById("showMark").innerHTML = "Great Job! You got 5/5!";
    } else if (total == 4) {
        document.getElementById("showMark").innerHTML =   "You got 4/5";
    } else if (total == 3) {
        document.getElementById("showMark").innerHTML = " You got 3/5!";
    } else if (total == 2) {
        document.getElementById("showMark").innerHTML = " You got 2/5!";
    } else if (total == 1) {
        document.getElementById("showMark").innerHTML = " You got 1/5!";
    } else {
        document.getElementById("showMark").innerHTML = " You got 0! ";
    }

}
