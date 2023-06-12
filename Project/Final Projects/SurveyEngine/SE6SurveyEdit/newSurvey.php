<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Create Survey</title>
        <link rel="stylesheet" href="styles.css">
        <link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css">
    </head>
    <body>
        <h1 id="title">SurveyMonster</h1>
        <p id="motto">The best way to do surveys!</p>

        <?php
        session_start();
        echo 'Hello, ' . $_SESSION['user_name'];
        echo '<div class="container btn-container">  
                <a class="buttons" href="welcome.php">Home</a>
                <a class="buttons" href="logout.php">Logout</a>
            </div>';
        ?>

        <h1>Create Survey</h1>

        <form action="createSurvey.php" method="post">
            <label for="surveyTitle">Survey Title:</label>
            <input type="text" id="surveyTitle" name="surveyTitle" required>

            <label for="numQuestions">Number of Questions:</label>
            <input type="number" id="numQuestions" name="numQuestions" max="10" required>

            <div id="questionsContainer"></div>

            <input id="submit-btn" name="submit" type="submit" value="Create Survey" class="buttons">
        </form>

        <script>
            const numQuestionsInput = document.getElementById('numQuestions');
            const questionsContainer = document.getElementById('questionsContainer');

            numQuestionsInput.addEventListener('change', function () {
                const numQuestions = parseInt(numQuestionsInput.value);

                //Clear previous questions
                questionsContainer.innerHTML = '';

                //Create input fields for questions
                for (let i = 1; i <= numQuestions; i++) {
                    const questionLabel = document.createElement('label');
                    questionLabel.innerHTML = 'Question ' + i + ':';
                    const questionInput = document.createElement('input');
                    questionInput.type = 'text';
                    questionInput.name = 'question' + i;
                    questionInput.placeholder = 'Question ' + i;
                    questionInput.required = true;
                    questionInput.style = 'width: 100%;'

                    const questionNumRespLabel = document.createElement('label');
                    questionNumRespLabel.innerHTML = 'Number of Response Options:';
                    const questionNumResp = document.createElement('input');
                    questionNumResp.type = 'number';
                    questionNumResp.max = '10';
                    questionNumResp.name = 'numResp' + i;
                    questionNumResp.required = true;

                    const respOptionsContainer = document.createElement('div');
                    respOptionsContainer.id = 'responseOptions' + i;

                    questionNumResp.addEventListener('change', function () {
                        const numResp = parseInt(questionNumResp.value);

                        //Clear previous response options
                        respOptionsContainer.innerHTML = '';

                        //Create input fields for response options
                        for (let j = 1; j <= numResp; j++) {
                            const label = document.createElement('label');
                            label.innerHTML = j + ' )';
                            const input = document.createElement('input');
                            input.type = 'text';
                            input.name = 'respOption' + i + '_' + j;
                            input.placeholder = 'Response Option ' + j;
                            input.required = true;
                            input.style = 'width: 98%;margin: 10px;'
                            respOptionsContainer.appendChild(label);
                            respOptionsContainer.appendChild(input);
                        }
                    });

                    const questionDiv = document.createElement('div');
                    questionDiv.appendChild(questionLabel);
                    questionDiv.appendChild(questionInput);
                    questionDiv.appendChild(questionNumRespLabel);
                    questionDiv.appendChild(questionNumResp);
                    questionDiv.appendChild(respOptionsContainer);

                    questionsContainer.appendChild(questionDiv);
                }
            });
        </script>
    </body>
</html>
