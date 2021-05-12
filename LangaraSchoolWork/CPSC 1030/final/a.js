
function submit() {

    let studentIdValue = document.getElementById("studentId").value;
    if (studentIdValue.length < 1) {
        alert("Please Do Not Leave Your Student Number Blank!");
    } else if (document.getElementById("certificate").checked) {
        alert("Good luck with your certificate!");
    } else if (document.getElementById("diploma").checked) {
        alert("Good luck with your diploma!");
    } else if (document.getElementById("degree").checked) {
        alert("Good luck with your degree!");
    }

}
