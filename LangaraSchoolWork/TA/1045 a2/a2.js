let mExpenseTotal = 0;
let mExpense = 0;

function formatDollarAmount(n) {
    return "$" + parseFloat(n).toFixed(2);
};

function addListItem(id, text) {
    document.getElementById(id).innerHTML += `<li>${text}</li>`;
};

function updateTotals() {
    mExpenseTotal = mExpense * 12;
    document.getElementById("total").innerHTML = formatDollarAmount(mExpenseTotal);
};

function addExpense() {
    const text = prompt("Enter item description: ");
    const value = prompt("Add your expense: ");
    const formattedValue = formatDollarAmount(value);
    addListItem("expTotal", `${formattedValue} : ${text}`);
    mExpense -= parseFloat(value);
    updateTotals();
};

function addIncome() {
    const text = prompt("Enter item description: ");
    const value = prompt("Add your income: ");
    const formattedValue = formatDollarAmount(value);
    addListItem("incTotal", `${formattedValue} : ${text}`);
    mExpense += parseFloat(value);
    updateTotals();
};