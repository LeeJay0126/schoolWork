<?php
// Should return a PDO

require 'config.php';

$conString = "mysql:host=" . constant("DBHOST") . ";dbname=" . constant("DBNAME");
$user = constant("DBUSER");
$pass = constant("DBPASS");

$pdo = new PDO($conString, $user, $pass);

function db_connect()
{

  try {
    // TODO
    // try to open database connection using constants set in config.php
    // return $pdo;

    global $pdo;

    return $pdo;
  } catch (PDOException $e) {
    die($e->getMessage());
  }
}

// Handle form submission
function submit_post()
{
  global $pdo;

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // TODO
    // Prepare the submitted form data and insert it to the database
    if (isset($_POST['email']) && isset($_POST['mood']) && isset($_POST['comment'])) {

      $sql = "INSERT INTO comments(email, commentText, mood, date) VALUES (:email, :comment, :mood, :date)";
      $statement = $pdo->prepare($sql);

      $statement->bindValue(':email', $_POST['email']);
      $statement->bindValue(':mood', $_POST['mood']);
      $statement->bindValue(':comment', $_POST['comment']);
      $statement->bindValue(':date', date('Y-m-d'));

      $statement->execute();
    }
  }
}

// Get all comments from database and store in $comments
function get_posts()
{
  global $pdo;
  global $posts;


  $sql = "SELECT * FROM comments ORDER BY id DESC";
  $result = $pdo->query($sql);

  while ($post = $result->fetch()) {
    $temp = array();
    array_push($temp, $post['ID'], $post['email'], $post['mood'], $post['commentText'], $post['date']);
    array_push($posts, $temp);
  }

  //TODO

}

// Get unique email addresses and store in $commenters
function get_commenters()
{
  global $pdo;
  global $commenters;

  $sql = "SELECT * FROM comments ORDER BY id DESC";
  $result = $pdo->query($sql);

  while ($post = $result->fetch()) {
    array_push($commenters, $post['email']);
  }


  //TODO

}
