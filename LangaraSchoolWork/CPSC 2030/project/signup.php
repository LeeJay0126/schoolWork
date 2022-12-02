<!DOCTYPE html>
<html lang="en">

<head>
    <title>Sign in Page</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="general.css">
</head>

<body>
    <div class="navBar">
        <div class="Logo"><a href="index.php">
                LeeJay
            </a></div>
    </div>
    <form class="card" action="http://localhost/project/index.php" method="post">
        <h1 class="cardHeading">Sign Up</h1>
        <div class="inputFlexbox">
            <ion-icon name="mail" class="inputIcon"></ion-icon>
            <label>Email: &nbsp; &nbsp; &nbsp;</label>
            <input class="inputbox" name="email" placeholder="email.123@gmail.com" />
        </div>
        <div class="inputFlexbox">
            <ion-icon name="person-outline" class="inputIcon"></ion-icon>
            <label>Username: </label>
            <input class="inputbox" name="username" placeholder="username123" />
        </div>
        <div class="inputFlexbox">
            <ion-icon name="keypad" class="inputIcon"></ion-icon>
            <label>Password: </label>
            <input class="inputbox" name="password" placeholder="password123" />
        </div>
        <section class="buttonFlex">
            <button type="Submit" class="submitButton">Sign Up</button>
        </section>
        <div id="signupError">

        </div>
    </form>



    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>

</html>