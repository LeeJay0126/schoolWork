<?php

	// error reporting
	error_reporting(E_ALL);
	ini_set('display_errors', 1);

	// Import functions
	require_once('validation.php');

	// Validate form submission
	validate();
 ?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>La7: Form Validation</title>

	<link rel="stylesheet" href="style.css">
	

 	 <script src="jquery-validation-1.19.3/lib/jquery.js"></script>
    <script src="jquery-validation-1.19.3/dist/jquery.validate.js"></script>


    <!-- <script>
	$(function() {
      $("form").validate({

        rules: {

          email: {
            required: true,
            email: true
          },

          date: {
            required: true,
            dateISO: true
          },
         
          "animals[]": {
            required: true,
            minlength: 3,
            maxlength: 3
          }

			// TODO: add rules for validation here 
			// The key name on the left side is the name attribute
			// of an input field. Validation rules are defined
			// on the right side
			 
			},
    
        // These are the validation error messages that will display 
        messages: {
          email: {
            required: "Please provide an email",
            email: "Please enter a valid email address"
			},
		  date: {
            required: "Please provide a date",
            dateISO: "Date must be in ISO format"
          },
          "animals[]": "Please choose three animals"
        },
		
		 // This is a function to fix the weird placement of errors in the checkbox group
        errorPlacement: function(error, element) {
          // Note that element and error are jQuery objects - can get native DOM node by adding [0]
          element[0].parentElement.appendChild(error[0]);
        }, 
		
		 // This is the function that submits the form if there are no errors 
      submitHandler: function(form) {
          form.submit();
        }
	  });
    });
	</script> -->

  </head>
  <body>

    <div class="wrapper">

      <h1>Lab7: Form Validation with jQuery and PHP</h1>

      <form action="http://localhost/Lab7StarterFiles/lab7/lab7.php" method="post">

        <label for="email">  Please enter your email address:

          <input type="text" name="email" id="email">

          <?php the_validation_message('email'); ?>

        </label>

        <fieldset>
          <legend> Please select your three favorite animals:</legend>

            <input type="checkbox" name="animals[]" id="chicken" value="chicken">
              <label for="chicken">Chicken</label>

            <input type="checkbox" name="animals[]" id="cow" value="cow">
              <label for="cow">cow</label>

            <input type="checkbox" name="animals[]" id="whale" value="whale">
              <label for="whale">whale</label>

            <input type="checkbox" name="animals[]" id="bee" value="bee">
              <label for="bee">  bee</label>

            <input type="checkbox" name="animals[]" id="doggo" value="doggo">
              <label for="doggo">doggo</label>

            <input type="checkbox" name="animals[]" id="kitten" value="kitten">
              <label for="kitten">kitten</label>

            <input type="checkbox" name="animals[]" id="jellyfish" value="jellyfish">
              <label for="jellyfish">jellyfish</label>

        <?php the_validation_message('animals'); ?>

        </fieldset>

        <label for="date">  Please enter your favorite date: (yyyy/mm/dd)

          <input type="text" name="date" id="date">

          <?php the_validation_message("date"); ?>
      </label>

        <input type="reset" name="" value="Reset Form">

        <input type="submit" value="Submit Form">

      </form>

      <!-- Display the results -->
      <?php the_results(); ?>

      </div> <!--END WRAPPER -->

  </body>
</html>
