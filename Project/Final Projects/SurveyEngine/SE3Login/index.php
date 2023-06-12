<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>SurveyMonster</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>

        <?php
        if (!isset($_SESSION["name"])) {
            echo 'Hello, ' . $_SESSION['name'];
            echo '<div class="container btn-container">  
                <a class="buttons" href="logout.php">Logout</a>
            </div>';
            
        } else {
            echo '<div class="container btn-container">  
            <a class="buttons" href="login.php">Log In</a>
            <a class="buttons" href="register.php">Register</a>
        </div>';
        }
        ?>





    </body>

</html>