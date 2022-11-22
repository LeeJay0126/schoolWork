<!DOCTYPE html>
<html lang="en">

<head>
    <title>Sign in Page</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="style.css">

    <script>
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
    </script>

</head>

<body>
    <div class="navBar">
        <div class="Logo"><a href="index.php">
                LeeJay
            </a></div>
    </div>
    <section class="card">
        <h1 class="cardHeading">Sign In</h1>
        <div class="inputFlexbox">
            <ion-icon name="person-outline" class="inputIcon"></ion-icon>
        </div>
    </section>


    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>

</html>