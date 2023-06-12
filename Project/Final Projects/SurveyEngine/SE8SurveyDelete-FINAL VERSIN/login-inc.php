<?php

//if (isset($_POST["submit"])) {
//    $username = $_POST["user_name"];
//    $pwd = $_POST["password"];
//
//    require_once 'connection-inc.php';
//    require_once 'functions-inc.php';
//
//    if (emptyInputLogIn($username, $pwd) !== false) {
//        header("location: login.php?error=emptyinput");
//        exit();
//    }
//
//    loginUser($conn, $username, $pwd);
//} else {
//    header("location: logout.php");
//    exit();
//}

if (isset($_POST["submit"])) {
    $username = $_POST["user_name"];
    $pwd = $_POST["password"];

    require_once 'connection-inc.php';
    require_once 'functions-inc.php';

    if (empty($username) || empty($pwd)) {
        header("location: login.php?error=emptyinput");
        exit();
    }

    loginUser($conn, $username, $pwd);
} else {
    header("location: logout.php");
    exit();
}
