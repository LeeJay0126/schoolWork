<!DOCTYPE html>
<html lang="en">
<head>
	<title>Langara Golf Course</title>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css">
	<script src="https://kit.fontawesome.com/39cbf8668b.js" crossorigin="anonymous"></script>

	<script src="https://code.jquery.com/jquery-1.11.1.min.js"></script>
	<script src="https://cdn.jsdelivr.net/jquery.validation/1.16.0/jquery.validate.min.js"></script>	

    <script>
	$(function() {
      $("form").validate({

        rules: {

			// TODO: add rules for validation here 
			// The key name on the left side is the name attribute
			// of an input field. Validation rules are defined
			// on the right side
		
			
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
	<h1>Langara Golf Course</h1>
	<div id="banner">
	</div>
	<h3>Book a tee time</h3>
	<form id="booking" method="post" action="http://localhost/golf/index.php">
	
		<label>Select number of players:</label><br>
		<input type="radio" name="numOfPlayers" id="player1" value="1" checked>1<br>
		<input type="radio" name="numOfPlayers" id="player2" value="2">2<br>
		<input type="radio" name="numOfPlayers" id="player3" value="3">3<br>
		<input type="radio" name="numOfPlayers" id="player4" value="4">4<br>

		<br>
		<label>Select a tee time:</label><br>
		
		<?php teetimes(); ?>
	
		<?php validateSelection();?>
		<br>
		<label>Email address:</label>
		<input type="email" name="email"><br>
		<label>Password:</label>
		<input type="password" name="password">
		<br>
		<?php validateLogin(); ?>
		
		<input type="submit" class="submit"  value="Continue">
	</form>
	

		<main>
		
			<button id="close"><i class="fas fa-times"></i></button>
			
			<table>
				<caption>Here is your booking information</caption>
				<tr>
					<td>Tee Time</td>
					<td></td>
				</tr>
				<tr>
					<td>Number of players</td>
					<td></td>
				</tr>
				<tr>
					<td>Green Fee Per Player</td>
					<td></td>
				</tr>
				<tr>
					<td>Tax (5%) Per Player</td>
					<td></td>
				</tr>
				<tr>
					<td>Total for Your Booking</td>
					<td></td>
				</tr>
			</table>
			<br>
			
		</main>

	
</div>		
</body>
</html>