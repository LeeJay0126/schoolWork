
function question1(numberArray) {

    for (let i = 0; i < numberArray.length; i++) {

        if (numberArray[i] > numberArray[i + 1]) {
            numberArray[i + 1] = numberArray[i];
        }

    }

    return numberArray[numberArray.length - 1];
    //For this function: return the largest number in the numberArray array.


    //Remember to return the largest number
}
function question2(numberArray) {


    for (let i = 0; i < numberArray.length; i++) {

        if (numberArray[i] > numberArray[i + 1]) {
            return false;
        }
    }
   
    return true;

    //For this function, return true if the numberArray is sorted from
    //smallest to largest. That is the smallest number is at index 0, 
    //and the largest number is at the last index and the numbers are in order.

    //Remember to return the boolean value

}

function question3(numberArray, minNumber, maxNumber) {

    let resultArray = [];

    for (let i = 0; i < numberArray.length; i++) {

        if (numberArray[i] < maxNumber && numberArray[i] > minNumber) {

            resultArray += numberArray[i];

        }

    }

    return resultArray;
    //For this function, returns an array with all the numbers
    //in numberArray that is between minNumber and maxNumber, not including minNumber and maxNumber


    //Remember to return the result array
}
function question4(stringArray, oldWord, newWord) {
    //For this function modify the stringArray, such that every element that matches 
    //the oldWord, is changed to the newWord.

    for (i = 0; i < stringArray.length; i++) {

        if (stringArray[i] == oldWord) {

            stringArray[i] = newWord;

        }

    }



    return stringArray;
}
function question5(numberArray) {

    let resultArray = [];

    
    for (let i = 0; i < numberArray.length; i ++){

        for (let j = 1; j < numberArray.length - 1; j ++){

            if (numberArray[j-1] > numberArray[j]){
               var tmp = numberArray[j-1];
               numberArray[j-1] = numberArray[j];
               numberArray[j] = tmp;
            }

        }

    }


    resultArray.push (numberArray[numberArray.length - 3]);
    resultArray.push (numberArray[numberArray.length - 2]);
    resultArray.push (numberArray[numberArray.length - 1]);

    return resultArray;



    //for this function return as an array, the largest 3 numbers of numberArray

    //remember to return the result array

}


//tests for functions above
function testQuestion1() {
    let testArray = [10, 45, 33, 67, 433, 33];

    let answer1 = question1(testArray);
    if (question1(testArray) == 433) {
        console.log("Question 1:Found the largest")
    } else {
        console.log("Question1: For array ", testArray, " returned ", answer1, "Which is not the largest");
    }

    let testArray2 = [10, -900, 3000, 22, 33, 67, 433, 33];
    let answer2 = question1(testArray);
    if (question1(testArray2) == 3000) {
        console.log("Question 1: Found the largest")
    } else {
        console.log("Question 1: For array ", testArray2, " returned ", answer2, "Which is not the largest");
    }
}

function testQuestion2() {
    let testArray = [1, 4, 5, 6, 9, 11, 14, 55];//sorted array
    if (question2(testArray) === true) {
        console.log("Question2: for input ", testArray, " answer is correct");
    } else {
        console.log("Question2: for input ", testArray, " answer is incorrect");
    }

    let testArray2 = [1, 4, 5, 6, 14, 11, 14, 55];//Not sorted array
    if (question2(testArray2) === false) {
        console.log("Question2: for input ", testArray2, " answer is correct");
    } else {
        console.log("Question2: for input ", testArray2, " answer is incorrect");
    }
}

function testQuestion3() {
    let testArray = [9, 2, 4, 3, 6, 7, 8]
    let min = 4;
    let max = 9;

    let result = question3(testArray, min, max);
    if (typeof (result) != "undefined") {
        if (result.length == 3 &&
            result.indexOf(6) != -1 &&
            result.indexOf(7) != -1 &&
            result.indexOf(8) != -1) {
            console.log("Question 3 test passed for ", testArray);
        } else {
            console.log("Question 3 test failed for ", testArray);
        }
    } else {
        console.log("Question3: No return value");
    }
}
function testQuestion4() {
    let testArray = ["a", "random", "pie", "random", "cheese"];
    let oldWord = "random";
    let newWord = "rabbit";

    let result = question4(testArray, oldWord, newWord);
    if (typeof (result) != "undefined") {
        if (result[0] == "a" &&
            result[1] == newWord &&
            result[2] == "pie" &&
            result[3] == newWord &&
            result[4] == "cheese") {
            console.log("Question 4: Passed");
        } else {
            console.log("Question 4: Failed");
        }

    } else {
        console.log("Question 4: No return value");
    }
}

function testQuestion5() {
    let testArray = [30, 40, 88, 60, 70, 75, 99, 200]; //Answer 75, 99, 88    
    let result = question5(testArray);
    if (typeof (result) != "undefined") {
        if (result.includes(200) && result.includes(99) && result.includes(88) && result.length == 3) {
            console.log("Question 5: Passed")
        } else {
            console.log("Question 5: Failed");
        }
    } else {
        console.log("Question 5: No return value");
    }
}

testQuestion1();
testQuestion2();
testQuestion3();
testQuestion4();
testQuestion5();