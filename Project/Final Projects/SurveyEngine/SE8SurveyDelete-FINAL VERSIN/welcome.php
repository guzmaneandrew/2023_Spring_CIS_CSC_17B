<?php
session_start();

include 'connection-inc.php';

function getSurveys($conn) {
    $query = "SELECT * FROM entity_survey";
    $result = $conn->query($query);

    //Get the surveys from db
    $surveys = array();
    while ($row = $result->fetch_assoc()) {
        $surveys[] = $row;
    }

    return $surveys;
}

$surveys = getSurveys($conn);
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
        <h2>All Surveys</h2>
        <table>
            <thead>
                <tr id="1strow">
                    <th>Title</th>
                    <th>Description</th>
                    <th>Status</th>
                    <th></th>
                </tr>
            </thead>
            <tbody>
                <?php
                foreach ($surveys as $survey) {
                    echo '<tr>';
                    echo '<td>' . $survey['title'] . '</td>';
                    echo '<td>' . $survey['description'] . '</td>';
                    echo '<td>' . ($survey['is_active'] ? 'Active' : 'Inactive') . '</td>';
                    echo '<td>
                            <a class="buttons" href="viewSurvey.php?survey_id=' . $survey['survey_id'] . '">View</a>
                            <a class="buttons" href="editSurvey.php?survey_id=' . $survey['survey_id'] . '">Edit</a>
                            <a class="buttons" href="deleteSurvey.php?survey_id=' . $survey['survey_id'] . '">Update Status</a>
                        </td>';
                    echo '</tr>';
                }
                ?>
            </tbody>
        </table>
    </div>

</body>

</html>