<?php

//register
function emptyInputSignUp($username, $pwd, $pwdRepeat) {
    $result;
    if (empty($username) || empty($pwd) || empty($pwdRepeat)) {
        $result = true;
    } else {
        $result = false;
    }
    return $result;
}

function invalidUid($username) {
    $result;
    if (!preg_match("/^[a-zA-Z0-9]*$/", $username)) {
        $result = true;
    } else {
        $result = false;
    }
    return $result;
}

function pwdMatch($pwd, $pwdRepeat) {
    $result;
    if ($pwd !== $pwdRepeat) {
        $result = true;
    } else {
        $result = false;
    }
    return $result;
}

function uidExists($conn, $username) {
    $sql = "SELECT * FROM entity_user WHERE name = ?;";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        header("location: register.php?error=stmtfailed1");
        exit();
    }
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);

    $resultData = mysqli_stmt_get_result($stmt);
    if ($row = mysqli_fetch_assoc($resultData)) {
        return $row;
    } else {
        $result = false;
    }
    return $result;
    mysqli_stmt_close($stmt);
}

function createUser($conn, $username, $password) {
    $sql = "INSERT INTO entity_user (name, password, status) VALUES (?, ?, ?);";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        header("location: register.php?error=stmtfailed2");
        exit();
    }
    $status = 1;
    mysqli_stmt_bind_param($stmt, "ssi", $username, $password, $status);
    mysqli_stmt_execute($stmt);
    
    if (mysqli_stmt_error($stmt)) {
        // Display or log the SQL error message
        echo "SQL Error: " . mysqli_stmt_error($stmt);
        exit();
    }
    mysqli_stmt_close($stmt);
    header("location: index.php?error=none");
    exit();
}

//singin
function emptyInputLogIn($username, $pwd) {
    $result;
    if (empty($username) || empty($pwd)) {
        $result = true;
    } else {
        $result = false;
    }
    return $result;
}

function loginUser($conn, $username, $pwd) {
    $uidExists = uidExists($conn, $username);
    if ($uidExists === false) {
        header("location: login.php?error=wronglogin");
        exit();
    }
    $pwdDB = $uidExists["password"];

    if ($pwd !== $pwdDB) {
        header("location: login.php?error=wronglogin");
        exit();
    } else if ($pwd === $pwdDB) {
        session_start();
        $_SESSION["user_id"] = $uidExists["user_id"];
        $_SESSION["name"] = $uidExists["name"];
        header("location: welcome.php");
        exit();
    }
}
