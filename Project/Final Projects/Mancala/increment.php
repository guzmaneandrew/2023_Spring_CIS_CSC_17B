<?php

require_once 'dbh.inc.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = 'test';
    updateUserStats($conn, $username);
    header("Location: index.php");
    exit();
}

function updateUserStats($conn, $username) {
    $sql = "UPDATE users SET users_score = users_score + 1, users_win = users_win + 1 WHERE users_name = ?";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        echo 'Statement preparation failed.';
        exit();
    }
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
}
