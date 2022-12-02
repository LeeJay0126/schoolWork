<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

//array that stores logged in user info
$login = false;

require_once 'database/database.php';
require_once 'templates/functions/template_functions.php';

//connect to database: PHP Data object representing Database connection
$pdo = db_connect();

//submit user log in information for signup
submit_post();
get_posts();

// // get posts from database
// get_posts();
// // get commenters from database
// get_commenters();

// include the template to display the page
include 'templates/index.php';

 ?>