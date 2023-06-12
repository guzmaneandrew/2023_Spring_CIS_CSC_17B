<?php
session_start();

include 'connection-inc.php';

//Get the survey ID
$surveyId = $_GET['survey_id'];

function getSurvey($conn, $surveyId) {
    $query = "SELECT * FROM entity_survey WHERE survey_id = '$surveyId'";
    $result = $conn->query($query);

    //Get the survey
    $survey = $result->fetch_assoc();

    return $survey;
}

function getQuestions($conn, $surveyId) {
    $query = "SELECT * FROM x_survey_question WHERE survey_id = '$surveyId'";
    $result = $conn->query($query);

    //Get all questions
    $questions = array();
    while ($row = $result->fetch_assoc()) {
        $questionId = $row['question_id'];
        $questionText = getQText($conn, $questionId);
        $row['question'] = $questionText;
        $questions[] = $row;
    }

    return $questions;
}

function getQText($conn, $questionId) {
    $query = "SELECT question FROM entity_question WHERE question_id = '$questionId'";
    $result = $conn->query($query);
    $question = $result->fetch_assoc();

    return $question['question'];
}

function getAnswers($conn, $surveyId) {
    $query = "SELECT * FROM x_survey_question_answer WHERE survey_id = '$surveyId'";
    $result = $conn->query($query);

    //Get answers
    $answers = array();
    while ($row = $result->fetch_assoc()) {
        $answerId = $row['answer_id'];
        $answerText = getAnswerText($conn, $answerId);
        $row['option'] = $answerText;
        $answers[] = $row;
    }

    return $answers;
}

function getAnswerText($conn, $answerId) {
    $query = "SELECT option FROM entity_option WHERE option_id = '$answerId'";
    $result = $conn->query($query);
    $answer = $result->fetch_assoc();

    return $answer['option'];
}

$survey = getSurvey($conn, $surveyId);
$questions = getQuestions($conn, $surveyId);
$answers = getAnswers($conn, $surveyId);
?>

<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>View Survey | SurveyMonster</title>
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
            <h2>Survey Details</h2>
            <h3>Title: <?php echo $survey['title']; ?></h3>
            <p>Description: <?php echo $survey['description']; ?></p>

            <h2>Questions</h2>
            <?php foreach ($questions as $question): ?>
                <h4>Question <?php echo $question['question_id']; ?></h4>
                <p><?php echo $question['question']; ?></p>

                <h2>Answers</h2>
                <?php foreach ($answers as $answer): ?>
                    <h4>Answer <?php echo $answer['answer_id']; ?></h4>
                    <p><?php echo $answer['option']; ?></p>
                <?php endforeach; ?>
            <?php endforeach; ?>

        </div>

    </body>

</html>
