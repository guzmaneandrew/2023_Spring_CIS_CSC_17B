<?php
if (isset($_GET["error"])) {
    if ($_GET["error"] == "emptyinput") {
        echo "<p>Fill in all fields!</p>";
    } else if ($_GET["error"] == "invaliduid") {
        echo "<p>Choose proper username!</p>";
    } else if ($_GET["error"] == "passwordsdontmatch") {
        echo "<p>Passwords do not match!</p>";
    } else if ($_GET["error"] == "usernametaken") {
        echo "<p>Username not available. Try again!</p>";
    } else if ($_GET["error"] == "stmtfailed") {
        echo "<p>Something went wrong, try again!</p>";
    } else if ($_GET["error"] == "none") {
        echo "<p>You have signed up!</p>";
    }
}
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Mancala | Sign up</title>
        <style>
<?php include 'style.css'; ?>
        </style>
    </head>
    <body>
        <div class="signup-form">
            <h1 id="title">Sign Up</h1>
            <div class="container">
                <form action="signup-inc.php" method="post">
                    <input type="text" name="uid" placeholder="Username...">
                    <input type="password" name="pwd" placeholder="Password...">
                    <input type="password" name="pwdrepeat" placeholder="Repeat Password...">
                    <button type="submit" name="submit">Sign up</button>
                </form>
                <p>Already have an account? <a href="login.php">Log in</a></p>
            </div>
        </div>
    </body>






