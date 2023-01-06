<?php
require 'config.php';

function db_connect() {

  // try to open database connection
  try {

    $connectionString = 'mysql:host=' . DBHOST . ';dbname=' . DBNAME;
    $user = DBUSER;
    $pass = DBPASS;

    // MAKE CONNECTION AND SET UP ERROR STUFF
    $pdo = new PDO($connectionString, $user, $pass);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    return $pdo;

  }
  catch (PDOException $e)
  {
    die($e->getMessage());

  }
}

function get_slots() {

	global $pdo;
	global $slots;

	// ACTUALLY GET THE SLOTS
	$sql = "SELECT * FROM teetime";

	$result = $pdo->query($sql);
	while($row = $result->fetch())
	{
		$slots[] = $row;
	}
}

function get_users()
{
	global $pdo;
	global $users;
 
	// ACTUALLY GET THE USERS
	$sql = "SELECT * FROM user";

	$users = $pdo->query($sql);
}
?>
