<?php
if (isset($_GET["error"])) {
    if ($_GET["error"] == "emptyinput") {
        echo "<p>Please Fill in All Fields!</p>";
    } else if ($_GET["error"] == "invaliduid") {
        echo "<p>Invalid Username. Try Again!</p>";
    } else if ($_GET["error"] == "passwordsdontmatch") {
        echo "<p>Passwords Don't Match. Try Again!</p>";
    } else if ($_GET["error"] == "usernametaken") {
        echo "<p>Username is Not Available. Try again!</p>";
    } else if ($_GET["error"] == "stmtfailed") {
        echo "<p>Something Went Wrong. Try Again!</p>";
    } else if ($_GET["error"] == "none") {
        echo "<p>Account Successfully Created!</p>";
    }
}
?>

<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>SurveyMonster | Register</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>
        <div class="container">
            <form method="post" action="register-inc.php" id="survey-form">
                <h2>Register</h2>
                <label for="name" id="username-label">Username
                    <input type="text" id="name" name="name" class="input" 
                           placeholder="Enter your username" minlength="4"
                           maxlength="8" required autofocus>
                </label>
                <label for="password" id="password-label">Password
                    <input type="password" id="password" name="password" 
                           class="input" placeholder="Enter your password" 
                           minlength="6" maxlength="10" required>
                    <input type="password" id="passwordConf" name="passwordConf" 
                           class="input" placeholder="Confirm your password"
                           minlength="6" maxlength="10" required>
                </label>   
                <input id="submit-btn" name="submit" type="submit" value="Register" class="buttons">
                <div><p>Already have an account? <a href="login.php">Login now</a></div>
            </form>

        </div>
    </body>

</html>