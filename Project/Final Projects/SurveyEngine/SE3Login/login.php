<?php
if (isset($_GET["error"])) {
    if ($_GET["error"] == "emptyinput") {
        echo "<p>Fill In All Fields</p>";
    } else if ($_GET["error"] == "wronglogin") {
        echo "<p>Incorrect Login Information</p>";
    }
}
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>SurveyMonster | Log in</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>
    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>
        <div class="container">
            <form action="login-inc.php" method="post" id="survey-form">
                <h2>Log In</h1>
                <label for="name" id="username-label">Username
                    <input type="text" id="name" name="name" class="input" 
                           placeholder="Enter your username"required autofocus>
                </label>
                <label for="password" id="password-label">Password
                    <input type="password" id="password" name="password" 
                           class="input" placeholder="Enter your password" required>
                </label>   
                <input id="submit-btn" name="submit" type="submit" value="Login" class="buttons">
                <div><p>Don't have an account? <a href="register.php">Sign up</a></div>
            </form>
        </div>
    </body>
</html>



