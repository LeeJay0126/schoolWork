<?php

require 'config.php';

$conString = "mysql:host=" . constant("DBHOST") . ";dbname=" . constant("DBNAME");
$user = constant("DBUSER");
$pass = constant("DBPASS");

$pdo = new PDO($conString, $user, $pass);

function db_connect() {

    try {
        global $pdo;
        return $pdo;
        
    }catch (PDOException $e){
        die($e->getMessage());
    }
}

function submit_post() {
  global $pdo;
  if($_SERVER["REQUEST_METHOD"] == "POST"){
    if(isset($_POST['make']) && isset($_POST['model']) && isset($_POST['plateNumber']) && isset($_POST['year']) && isset($_POST['price'])){
        $sql = "INSERT INTO inventory(make, model, plateNumber, year, price) VALUES (:make, :model, :plateNumber, :year, :price)";
        $statement = $pdo->prepare($sql);

        $statement->bindValue(':make', $_POST['make']);
        $statement->bindValue(':model', $_POST['model']);
        $statement->bindValue(':plateNumber', $_POST['plateNumber']);
        $statement->bindValue(':year', $_POST['year']);
        $statement->bindValue(':price', $_POST['price']);

        $statement->execute();
    }
  }
}

function get_posts() {
    global $pdo;
    global $posts;

    $sql = "SELECT * FROM comments ORDER BY id DESC";

    while ($post = $result->fetch()) {
        $temp = array();
        array_push($temp, $post['make'], $post['price'], $post['year'], $post['model'], $post['plateNumber']);
        array_push($posts, $temp);
    }
}

?>
