const currentDate = new Date();

const footerDate = () => {
    const displayDiv = document.getElementById("secondLine");
    displayDiv.innerHTML('Last Updated on ' + currentDate.toUTCString);
};