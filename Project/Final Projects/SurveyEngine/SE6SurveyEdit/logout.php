<?php
session_start();

session_destroy();
unset($_SESSION['user_name']);

// Redirect the user
header("Location: index.php");

exit();
?>
