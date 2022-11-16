<!DOCTYPE html>
<html lang="en">
<head>
	<title>Langara Auto Mall</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">

	<script src="https://code.jquery.com/jquery-1.11.1.min.js"></script>
	<script src="https://cdn.jsdelivr.net/jquery.validation/1.16.0/jquery.validate.min.js"></script>	
	<script src="https://cdn.jsdelivr.net/jquery.validation/1.16.0/additional-methods.min.js"></script>

    <script>
	$(function() {
      $("form").validate({

        rules: {

			// TODO: add rules for validation here 
			// The key name on the left side is the name attribute
			// of an input field. Validation rules are defined
			// on the right side
			make: {
				required: true,
			},
			model: {
				required: true,
			},
			year: {
				required: true,
			},
			plateNumber: {
				required: true,
			},
			year: {
				required: true,
			},
			price: {
				required: true,
			}
		},
		
		//	These are the validation error messages that will display 
		messages: {
			make: {
				required: "Please provide a maker",
			},
			model: {
				required: "Please provide a model name",
			},
			year: {
				required: "Please provide a year",
			},
			plateNumber: {
				required: "Please provide a plate number",
			},
			year: {
				required: "Please provide a year",
			},
			price: {
				required: "Please provide a price",
			}
		},
		
		 // This is the function that submits the form if there are no errors 
		submitHandler: function(form) {
			form.submit();
		}
	  });
    });
	</script>


</head>
<body>
<div id="wrapper">
	<h1>Langara Auto Mall</h1>
	<div id="inventory">
		<h2>Car Inventory</h2>
		<table>
			
			<tr>
				<th>ID</th>
				<th>Make</th>
				<th>Model</th>
				<th>Plate Number</th>
				<th>Year</th>
				<th>Price</th>
			</tr>
			
		</table>
		
	</div>
	<br>

	<div id="add">
		<h2>Add a Car</h2>
		<form>
			
			<div><label for="make">Make:</label>
			<input type="text" name="make" id="name"></div>
			<div><label for="model">Model:</label>
			<input type="text" name="model" id="model"></div>
			<div><label for="plateNumber">Plate Number:</label>
			<input type="text" name="plateNumber" id="plateNumber"></div>
			<div><label for="year">Year:</label>
			<input type="text" name="year" id="year"></div>
			<div><label for="price">Price:</label>
			<input type="text" name="price" id="price"></div>
			
			<div><input type="reset" id="reset" value="Reset">
			<input type="submit" id="mySubmit"  value="Add a Car"></div>
			
		</form>
	</div>
</div>		
</body>
</html>