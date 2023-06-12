<?php

require_once 'connection-inc.php';
require_once 'functions-inc.php';

if (isset($_POST["submit"])) {

    $username = $_POST["name"];
    $pwd = $_POST["password"];
    $pwdRepeat = $_POST["passwordConf"];

    if (emptyInputSignUp($username, $pwd, $pwdRepeat) !== false) {
        header("location: register.php?error=emptyinput");
        exit();
    }

    if (invalidUid($username) !== false) {
        header("location: register.php?error=invaliduid");
        exit();
    }

    if (pwdMatch($pwd, $pwdRepeat) !== false) {
        header("location: register.php?error=passwordsdontmatch");
        exit();
    }

    if (uidExists($conn, $username) !== false) {
        header("location: register.php?error=usernametaken");
        exit();
    }

    createUser($conn, $username, $pwd);
} else {
    header("location: register.php");
    exit();
}
