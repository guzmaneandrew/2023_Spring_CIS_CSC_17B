<?php

/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $surveyTitle = $_POST["surveyTitle"];
    $numQuestions = $_POST["numQuestions"];
    $questions = array();

    //Get questions and response options
    for ($i = 1; $i <= $numQuestions; $i++) {
        $question = $_POST["question" . $i];
        $options = array();

        // Collect response options for each question
        $numResp = $_POST["numResp" . $i];
        for ($j = 1; $j <= $numResp; $j++) {
            $option = $_POST["respOption" . $i . "_" . $j];
            $options[] = $option;
        }

        $questions[] = array("question" => $question, "options" => $options);
    }
    
    //Database connection
    require_once 'connection-inc.php';

    //Insert survey into table
    $sql = "INSERT INTO entity_survey (title, is_active,numQuestions) VALUES (?, 1, ?)";
    $stmt = mysqli_stmt_init($conn);
    if (!mysqli_stmt_prepare($stmt, $sql)) {
        header("Location: createSurvey.php?error=stmtfailed");
        exit();
    }
    mysqli_stmt_bind_param($stmt, "ss", $surveyTitle,$numQuestions);
    mysqli_stmt_execute($stmt);
    $surveyId = mysqli_insert_id($conn);
    mysqli_stmt_close($stmt);

    //Insert questions and options into tables
    foreach ($questions as $question) {
        $questionText = $question["question"];

        $sql = "INSERT INTO entity_question (question) VALUES (?)";
        $stmt = mysqli_stmt_init($conn);
        if (!mysqli_stmt_prepare($stmt, $sql)) {
            header("Location: createSurvey.php?error=stmtfailed");
            exit();
        }
        mysqli_stmt_bind_param($stmt, "s", $questionText);
        mysqli_stmt_execute($stmt);
        $questionId = mysqli_insert_id($conn);
        mysqli_stmt_close($stmt);

        $options = $question["options"];
        foreach ($options as $option) {
            $sql = "INSERT INTO entity_option (option, question_id) VALUES (?, ?)";
            $stmt = mysqli_stmt_init($conn);
            if (!mysqli_stmt_prepare($stmt, $sql)) {
                header("Location: createSurvey.php?error=stmtfailed");
                exit();
            }
            mysqli_stmt_bind_param($stmt, "si", $option, $questionId);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_close($stmt);
        }
    }

    mysqli_close($conn);

    header("Location: welcome.php");
    exit();
} else {
    header("Location: logout.php");
    exit();
}
?>
