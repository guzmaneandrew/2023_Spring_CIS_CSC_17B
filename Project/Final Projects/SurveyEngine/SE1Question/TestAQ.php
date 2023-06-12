<!DOCTYPE html>

<!--/* 
<a href="../Compare_Objects_Arrays_Functions_CPP_PHP_Javascript/TestACard.php"></a>
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */-->

<html>
    <head>
        <meta charset="UTF-8">
        <title>Test Question Objects</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
        <?php include './Question.php'; ?>
    </head>
    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>
        <?php
        //Test the Question by creating a survey then printing the result
        $nQuestions = 5;
        $survey = array();
        echo "Title: " . "<br><br>";
        for ($i = 0; $i < $nQuestions; $i++) {
            echo "Question " . $i + 1 . "<br>";
            $survey[$i] = new Question();
            $survey[$i]->toString();
        }
        ?>
    </body>
</html>
