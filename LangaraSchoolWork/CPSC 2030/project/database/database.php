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

        global $pdo;

        return $pdo;
    } catch (PDOException $e) {
        die($e->getMessage());
    }
}


function submit_post()
{
    global $pdo;

    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        if (isset($_POST['email']) && isset($_POST['username']) && isset($_POST['password'])) {

            $valid = signUpValidation($_POST['username'], $_POST['email']);

            if ($valid) {

                $sql = "INSERT INTO user(email, username, password) VALUES (:email, :username, :password)";
                $statement = $pdo->prepare($sql);

                $statement->bindValue(':email', $_POST['email']);
                $statement->bindValue(':username', $_POST['username']);
                $statement->bindValue(':password', $_POST['password']);

                $statement->execute();

                echo '<script type="text/javascript">
                alert("Registration Successful!");
            </script>';

                //gotta find a way to add an error message 
            } else {
                echo '<script type="text/javascript">
                    alert("Either your email or username is currently in use. Please try another email / username");
                </script>';
            }
        }
    }
}

function signUpValidation($username, $email)
{
    global $pdo;

    $sql = "SELECT * FROM user WHERE email = :email OR username = :username";
    $statement = $pdo->prepare($sql);

    $statement->bindValue(':email', $email);
    $statement->bindValue(':username', $username);

    $statement->execute();

    $count = $statement->fetchColumn();

    if ($count == 0) {
        return true;
    }

    if ($count > 0) {
        return false;
    }
}

function get_posts()
{
    global $pdo;
    global $login;

    if ($_SERVER["REQUEST_METHOD"] == "GET") {

        $username = $_GET["username"];
        $pw = $_GET["password"];

        $sql = "SELECT username FROM user WHERE username = :username AND password = :pw";
        $statement = $pdo->prepare($sql);

        $statement->bindValue(":username", $username);
        $statement->bindValue(":pw", $pw);

        $statement->execute();
        $result = $statement->fetch();

        if ($result) {
            $login = true;
        }
    }
}

function get_commenters()
{
    global $pdo;
    global $commenters;

    $sql = "SELECT * FROM comments ORDER BY id DESC";
    $result = $pdo->query($sql);

    while ($post = $result->fetch()) {
        array_push($commenters, $post['email']);
    }
}
