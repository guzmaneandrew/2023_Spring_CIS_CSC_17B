<?php

session_start();
require_once 'dbh.inc.php';
require_once 'functions.inc.php';

// Retrieve the JSON data sent from JavaScript
$data = json_decode(file_get_contents('php://input'), true);

// Update the session variables
$_SESSION['score'] = $data['score'];
$_SESSION['win'] = $data['win'];

$username = $_SESSION['users_name'];
$win = $_SESSION['win'];
$score = $_SESSION['score'];
updatePlayer($conn, $username, $score, $win);

//// Send a response back to JavaScript
//echo json_encode(['message' => 'Session updated successfully']);




