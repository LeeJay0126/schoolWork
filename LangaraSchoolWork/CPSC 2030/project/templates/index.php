<?php
    if($login){
        header("Location: http://localhost/project/main.php",true, 301);
        exit();
    }
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <title>Sign in Page</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="general.css">

    <!-- <script>
        $(function() {
            $("form").validate({

                rules: {
                    password: {
                        required: true,
                    },
                    username: {
                        required: true,
                    }
                },

                messages: {
                    password: {
                        required: "Please Enter a Valid Password",
                    },
                    username: {
                        required: "Please Enter a Valid Username"
                    }
                },


                submitHandler: function(form) {
                    form.submit();
                }
            });
        });
    </script> -->

</head>

<body>
    <div class="navBar">
        <div class="Logo"><a href="index.php">
                LeeJay
            </a></div>
    </div>
    <form class="card" action="http://localhost/project/index.php" METHOD="get">
        <h1 class="cardHeading">Sign In</h1>
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
            <button type="submit" name="button" class="submitButton">Sign In</button>
            <button type="nav" class="submitButton"><a href="signup.php">or.. Sign Up</a></button>
        </section>
    </form>



    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>

</html>