<?php
if (isset($_GET["error"])) {
    if ($_GET["error"] == "emptyinput") {
        $errorMessage = "Fill In All Fields";
    } else if ($_GET["error"] == "wronglogin") {
        $errorMessage = "Incorrect Login Information";
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
                        <input type="text" id="name" name="user_name" class="input" 
                               placeholder="Enter your username"required autofocus>
                    </label>
                    <label for="password" id="password-label">Password
                        <input type="password" id="password" name="password" 
                               class="input" placeholder="Enter your password" required>
                    </label>   
                    <input id="submit-btn" name="submit" type="submit" value="Login" class="buttons">
                    <div id="message"></div>
                    <div><p>Don't have an account? <a href="register.php">Sign up</a></div>
            </form>
        </div>
        <script>
            // Retrieve error message from the PHP variable
            var errorMessage = "<?php echo isset($errorMessage) ? $errorMessage : ''; ?>";

            // display the error message
            document.getElementById("message").innerText = errorMessage;
        </script>
    </body>
</html>



