<?php

// Include your database connection file or establish the connection here
require_once 'connection.inc.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Check if the request is a POST request
    // Get the username of the user whose status you want change
    $username = 'test';

    // Call the updateUserStats function to increment the stats
    updateStatus($conn, $username);

    // Redirect back to the index page or any other desired page
    header("Location: index.php");
    exit();
}

function updateStatus($conn, $username) {
    $sql = "UPDATE users SET status = !status WHERE name = ?";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        // Handle errors, such as echoing an error message
        echo 'Statement preparation failed.';
        exit();
    }
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
}

?>