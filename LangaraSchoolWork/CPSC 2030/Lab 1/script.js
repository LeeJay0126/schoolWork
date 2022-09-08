const updatedDate = document.lastModified;

const footerDate = () => {
    const displayDiv = document.getElementById("secondLine");
    displayDiv.innerHTML =  'Last Updated on '+updatedDate;
};

