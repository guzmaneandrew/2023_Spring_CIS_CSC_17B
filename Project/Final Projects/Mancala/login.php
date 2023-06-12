<?php
session_start();
if (isset($_GET["error"])) {
    if ($_GET["error"] == "emptyinput") {
        echo "<p>Fill in all fields!</p>";
    } else if ($_GET["error"] == "wronglogin") {
        echo "<p>Incorrect login information!</p>";
    }
}
?>

<!DOCTYPE html>
<html>

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Mancala | Log in</title>
        <style>
<?php include 'style.css'; ?>
        </style>
    </head>

    <body>
        <div class="signup-form">
            <h1 id="title">Log In</h1>
            <div class="container">
                <form action="login-inc.php" method="post">
                    <input type="text" name="uid" placeholder="Username...">
                    <input type="password" name="pwd" placeholder="Password...">
                    <button type="submit" name="submit">Log In</button>
                </form>
                <p>Don't have an account? <a href="signup.php">Sign up</a></p>
            </div>
        </div>
    </body>

</html>