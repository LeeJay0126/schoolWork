<?php
// Global result of form validation
$valid = false;

// Global array of validation messages. For valid fields, message is ""
$val_messages = ["email" => "", "animals" => "", "date" => ""];

// Output the results if all fields are valid.
function the_results()
{
  global $valid;

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if ($valid == true) {
      echo '<div class="results">
        <p class="result-text"> Your email address is: ' . $_POST["email"] . '</p>
        <div class="result-text">
          <p> Your favorite animals are: </p>
          <li> ' . $_POST["animals"][0] . '</li>
          <li> ' . $_POST["animals"][1] . '</li>
          <li> ' . $_POST["animals"][2] . '</li>
        </div>
        <p class="result-text"> Your favorite date is : ' . $_POST["date"] . '
      </div';
    }
  }
}

// Check each field to make sure submitted data is valid. 
// If no check boxes are checked, isset() will return false
function validate()
{
  global $valid;
  global $val_messages;

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $validCount = 0;
  // Validator for email
    if ($_POST["email"] == "") {
      $val_messages["email"] = "Please provide an email";
    } else if (preg_match('#^(.+)@([^\.].*)\.([a-z]{2,})$#', $_POST["email"]) == 1) {
      $validCount += 1;
    } else {
      $val_messages["email"] = "Please enter a valid email address";
    };
  // Validator for date
    if (preg_match('#^\d{4}/((0[1-9])|(1[0-2]))/((0[1-9])|([12][0-9])|(3[01]))$#', $_POST["date"]) == 1) {
      $validCount += 1;
    } else if ($_POST["date"] == "") {
      $val_messages["date"] = "Please provide a date";
    } else {
      $val_messages["date"] = "Date must be in ISO format";
    }
  // Validator for animals
    if (isset($_POST["animals"])) {
      if (count($_POST["animals"]) == 3) {
        $validCount += 1;
      } else {
        $val_messages["animals"] = "Please choose three animals";
      }
    } else {
      $val_messages["animals"] = "Please choose three animals";
    }
  // line that will set $valid to true if all 3 validators are true
    if ($validCount == 3) {
      $valid = true;
    }
    // Use these patterns to check email and date, or come up with your own.
    // email: '#^(.+)@([^\.].*)\.([a-z]{2,})$#'
    // date: '#^\d{4}/((0[1-9])|(1[0-2]))/((0[1-9])|([12][0-9])|(3[01]))$#'
  }
}

// Display error message if field not valid. Displays nothing if the field is valid.
function the_validation_message($type)
{

  global $val_messages;
  // print error message that matches the parameter
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    echo '<div class="failure-message">' . $val_messages[$type] . '</div>';
  }
}