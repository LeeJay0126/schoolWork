<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />

    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link href="https://fonts.googleapis.com/css2?family=Rubik:wght@400;500;600;700&display=swap" rel="stylesheet" />
    <link href="general.css" rel="stylesheet" />
    <link href="style.css" rel="stylesheet" />

    <script type="module" src="salary.js"></script>
    <title>Salary Calculator</title>
</head>

<body onload="onLoadFunction()" class="mainBody">
    <div class="navBar">
        <div class="Logo"><a href="index.php">
                LeeJay
            </a></div>
    </div>

    <main>
        <div class="mainNav">
            <ul class="navItems">
                <li class="navItem" id="Alberta" onclick="provinceChanger(this.id)">
                    Alberta
                </li>
                <li class="navItem" id="BC" onclick="provinceChanger(this.id)">BC</li>
                <li class="navItem" id="Saskatchewan" onclick="provinceChanger(this.id)">
                    Saskatchewan
                </li>
                <li class="navItem" id="Manitoba" onclick="provinceChanger(this.id)">
                    Manitoba
                </li>
                <li class="navItem" id="Ontario" onclick="provinceChanger(this.id)">
                    Ontario
                </li>
                <li class="navItem" id="Quebec" onclick="provinceChanger(this.id)">
                    Quebec
                </li>
                <li class="navItem" id="newBrunswick" onclick="provinceChanger(this.id)">
                    New Brunswick
                </li>
                <li class="navItem" id="novaScotia" onclick="provinceChanger(this.id)">
                    Nova Scotia
                </li>
                <li class="navItem" id="princeEdward" onclick="provinceChanger(this.id)">
                    Prince Edward Island
                </li>
                <li class="navItem" id="newFoundLand" onclick="provinceChanger(this.id)">
                    Newfoundland
                </li>
                <li class="navItem" id="yukon" onclick="provinceChanger(this.id)">
                    Yukon
                </li>
                <li class="navItem" id="northWestTerritory" onclick="provinceChanger(this.id)">
                    North West Territories
                </li>
                <li class="navItem" id="nunavut" onclick="provinceChanger(this.id)">
                    Nunavut
                </li>
            </ul>
        </div>

        <div class="serviceDisplay">
            <div class="provincialAndFederalTaxBrackets">
                <section class="projectGuideLine taxBracketSections">
                    <div class="displayHeader">
                        <ion-icon class="sectionIcon Icon" name="book-outline"></ion-icon>
                        <span class="displayHeading">Salary Calculator</span>
                    </div>
                    <p class="taxBracketDisplayDecoration">
                        Ever wondered how much you are getting paid after taxes? Our
                        program calculates your salary after taxes! After entering your
                        hourly wage and hours you work per week or annual salary, we can
                        tell you how much you make after taxes in matter of seconds!
                        Breaking down federal and provincial taxes per province!
                    </p>
                </section>
                <section class="provinceTaxBracket taxBracketSections">
                    <div class="displayHeader taxBracketHeader">
                        <ion-icon class="sectionIcon Icon" name="airplane-outline"></ion-icon>
                        <span class="displayHeading">Provincial Tax Bracket</span>
                    </div>
                    <div class="taxBracketDisplay">
                        <p id="taxBracketDisplayElement" class="taxBracketDisplayDecoration"></p>
                    </div>
                </section>
                <section class="federalTaxBracket taxBracketSections">
                    <div class="displayHeader">
                        <ion-icon class="sectionIcon Icon" name="people-circle-outline"></ion-icon>
                        <span class="displayHeading">Federal Tax Bracket</span>
                    </div>
                    <p id="federalTaxBracketDisplayElement" class="taxBracketDisplayDecoration"></p>
                </section>
            </div>

            <div class="salaryCalculatorButtons">
                <section class="checkBoxes">
                    <div class="checkBoxFlexBox">
                        <button class="button" id="hourButton" onclick="hourlyWageButton()">Hourly Wage</button>
                        <button class="button" id="salaryButton" onclick="salaryWageButton()">Salary Wage</button>
                    </div>
                </section>
            </div>

            <div class="salaryCalculatorMain" id="mainArea">
                <div class="mainInputField" id="mainSection">
                    <div class="inputFieldHolder">
                        <div class="displayHeader inputContainer">
                            <ion-icon id="mainIcon" class="inputIcon Icon" name="cash-outline"></ion-icon>
                            <span class="displayHeading" id="mainHeading">Enter your annual salary</span>
                        </div>
                        <input class="inputField" id="mainInputField" type="number" />
                        <div class="errorDisplay" id="display1"></div>
                    </div>
                    <div class="inputFieldHolder" id="secondInput">
                        <div id="secondInputField">
                            <div class="displayHeader inputContainer">
                                <ion-icon id="secondaryIcon" class="inputIcon Icon" name="calendar-outline"></ion-icon>
                                <span class="displayHeading" id="secondaryHeading">Enter your hours per week</span>
                            </div>
                            <input class="inputField" id="secondaryInputField" type="number" placeholder="Enter your hours per week here" />
                            <div class="errorDisplay" id="display2"></div>
                        </div>
                    </div>
                </div>


                <section class="mainTaxDisplay">
                    <div class="displayArea">
                        <span class="displayHeading" id="firstDisplayHeading">Hourly wage calculated to annual</span>
                        <div class="calculatedDisplayArea" id="hourlyToAnnualCalculated"></div>
                    </div>
                    <div class="displayArea">
                        <span class="displayHeading">Provincial Tax</span>
                        <div class="calculatedDisplayArea" id="provincialTaxDisplay"></div>
                    </div>
                    <div class="displayArea">
                        <span class="displayHeading">Federal Tax</span>
                        <div class="calculatedDisplayArea" id="federalTaxDisplay"></div>
                    </div>
                    <div class="displayArea">
                        <span class="displayHeading">Your Income After Taxes</span>
                        <div class="calculatedDisplayArea" id="calculatedIncomeDisplay"></div>
                    </div>
                </section>

                <section class="resultSection">
                    <div class="centerButton">
                        <button id="resultButton" onclick="calculateIncome()">
                            Calculate
                        </button>
                    </div>
                    <div class="calculatedDisplayArea" id="resultDisplay">

                    </div>
                </section>
            </div>

        </div>
    </main>

    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>

</html>