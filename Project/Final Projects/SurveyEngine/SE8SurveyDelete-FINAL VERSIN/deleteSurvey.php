<?php
require_once 'connection-inc.php';

//Get the survey ID
$surveyId = $_GET['survey_id'];

$stmt = $conn->prepare("UPDATE entity_survey SET is_active = 0 WHERE survey_id = ?");
$stmt->bind_param("i", $surveyId);
$stmt->execute();

// Check if the update was successful
if ($stmt->affected_rows > 0) {
    echo "Survey with ID $surveyId has been deactivated. ";
    echo "Go <a href='welcome.php'>back</a>";
} else {
    echo "Failed to deactivate the survey with ID $surveyId. ";
    echo "Go <a href='welcome.php'>back</a>";
}

// Close the statement
$stmt->close();
?>
