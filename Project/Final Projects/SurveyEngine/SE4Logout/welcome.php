<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>SurveyMonster</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>

        <?php
        echo 'Hello, ' . $_SESSION['name'];
        echo '<div class="container btn-container">  
                <a class="buttons" href="logout.php">Logout</a>
            </div>';
        ?>

        <div class="container surv-container">
            <h2>Surveys</h2>
            <table>
                <thead>
                    <tr id="1strow">
                        <th>Title</th>
                        <th>Description</th>
                        <th>Start Date</th>
                        <th>End Date</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    foreach ($surveys as $survey) {
                        echo '<tr>';
                        echo '<td>' . $survey['title'] . '</td>';
                        echo '<td>' . $survey['description'] . '</td>';
                        echo '<td>' . $survey['start_date'] . '</td>';
                        echo '<td>' . $survey['end_date'] . '</td>';
                        echo '</tr>';
                    }
                    ?>
                </tbody>
            </table>
        </div>

    </body>

</html>