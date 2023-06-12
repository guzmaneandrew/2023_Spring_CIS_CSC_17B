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
    $sql = "SELECT * FROM users WHERE users_name = ?;";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        header("location: signup.php?error=stmtfailed");
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

function createUser($conn, $username, $pwd) {
    $sql = "INSERT INTO users (users_name, users_pwd, users_score, users_status, users_win) VALUES (?, ?, ?, ?, ?);";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        header("location: signup.php?error=stmtfailed");
        exit();
    }
    $stat = 0;
    $win = 0;
    $score = 0;
    mysqli_stmt_bind_param($stmt, "ssiii", $username, $pwd, $score, $stat, $win);
    mysqli_stmt_execute($stmt);
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
    $pwdDB = $uidExists["users_pwd"];

    if ($uidExists["users_status"] === 1) {
        session_start();
        $_SESSION["users_id"] = $uidExists["users_id"];
        $_SESSION["users_name"] = $uidExists["users_name"];
        $_SESSION["users_status"] = $uidExists["users_status"];
        header("location: adminPage.php?error=adminloggedin");
        exit();
    }

    if ($pwd !== $pwdDB) {
        header("location: login.php?error=wronglogin");
        exit();
    } else if ($pwd === $pwdDB) {
        session_start();
        $_SESSION["users_id"] = $uidExists["users_id"];
        $_SESSION["users_name"] = $uidExists["users_name"];
        header("location: mancala.php");
        exit();
    }
}

function updatePlayer($conn, $username, $score, $win) {
// Retrieve the current user data
    $stmt = $conn->prepare("SELECT users_score, users_win FROM users WHERE users_name = ?");
    $stmt->bind_param('s', $username);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();

    // Increment wins if $win is true
    $new_win = $row['users_win'];
    if ($win) {
        $new_win++;
    }

    // Update score if the new score is higher than the old score
    $new_score = $row['users_score'];
    if ($score > $row['users_score']) {
        $new_score = $score;
    }

    // Prepare an SQL statement to update the user record
    $stmt = $conn->prepare("UPDATE users SET users_score = ?, users_win = ? WHERE users_name = ?");
    $stmt->bind_param('iis', $new_score, $new_win, $username);

    // Execute the statement
    if ($stmt->execute()) {
        header('Location: leaderboard.php');
    } else {
        echo "Error: " . $stmt->error;
    }
}
