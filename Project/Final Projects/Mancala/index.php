<?php
session_start();
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Mancala | Welcome</title>
        <link rel="stylesheet" href="style.css"/>
    </head>
    <body>
        <div>
            <h1 id="title">Welcome to Mancala!</h1>
            <div class="container">
                <div>
                    <button onclick="window.location.href = 'login.php';">Log In</button>
                    <button onclick="window.location.href = 'signup.php';">Sign Up</button>  
                </div>
            </div> 
        </div>

    </body>
</html>
