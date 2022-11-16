<?php

ini_set('display_errors', 1);
error_reporting(E_ALL);

// Import functions
require_once 'database/database.php';
require_once 'templates/functions/template_functions.php';
require_once 'templates/functions/validation.php';

$pdo = db_connect();
submit_post();
get_posts();

// include the template to display the page
include 'templates/index.php';

 ?>
