<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

// array of posts, fetched from database
$slots = [];
$users = [];
$loginValid = false;
$selectionValid = false;

require_once 'database/database.php';
require_once 'templates/functions/template_functions.php';
require_once 'templates/functions/validate_functions.php';

//connect to database: PHP Data object representing Database connection
$pdo = db_connect();

// get slots from database
get_slots();

// get users from database
get_users();

// include the template to display the page
include 'templates/index.php';

 ?>
