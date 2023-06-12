<?php
session_start();

include 'connection-inc.php';

//Get the survey ID from the query parameters
$surveyId = $_GET['survey_id'];

function getSurvey($conn, $surveyId) {
    $query = "SELECT * FROM entity_survey WHERE survey_id = '$surveyId'";
    $result = $conn->query($query);

    //Get the survey
    $survey = $result->fetch_assoc();

    return $survey;
}

function updateSurvey($conn, $surveyId, $title, $description) {
    $query = "UPDATE entity_survey SET title = '$title', description = '$description' WHERE survey_id = '$surveyId'";
    $result = $conn->query($query);

    return $result;
}

$survey = getSurvey($conn, $surveyId);

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $newTitle = $_POST['title'];
    $newDescription = $_POST['description'];

    $updateResult = updateSurvey($conn, $surveyId, $newTitle, $newDescription);

    if ($updateResult) {
        header("Location: viewSurvey.php?id=$surveyId");
        exit();
    }
}
?>

<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Edit Survey | SurveyMonster</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>

        <?php
        echo 'Hello, ' . $_SESSION['user_name'];
        echo '<div class="container btn-container">  
            <a class="buttons" href="newSurvey.php">Create Survey</a>
            <a class="buttons" href="logout.php">Logout</a>
        </div>';
        ?>

        <div class="surv-container">
            <h2>Edit Survey</h2>
            <form method="POST" action="editSurvey.php">
                <label for="title">Title:</label>
                <input type="text" id="title" name="title" value="<?php echo $survey['title']; ?>">

                <label for="description">Description:</label>
                <textarea id="description" name="description"><?php echo $survey['description']; ?></textarea>

                <input type="submit" value="Update">
            </form>
        </div>

    </body>

</html>