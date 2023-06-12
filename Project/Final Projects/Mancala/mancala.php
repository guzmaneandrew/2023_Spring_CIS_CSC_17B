<?php
session_start();
// Check if the user is logged in and the UID is set in the session
if (isset($_SESSION["users_name"])) {
    // Create a cookie with the username
    setcookie('username', $_SESSION['users_name'], time() + 3600, '/');
} else {
    header("location: index.php");
}

if (isset($_POST['logout'])) {
    session_destroy();
    header("location: index.php");
    exit();
}
?>

<!DOCTYPE html>

<html>
    <head>
        <title>Mancala</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <div class="content">
            <table id="board" class="tg">
                <tr>
                    <td class="tg-0lax" rowspan="2">0</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax" rowspan="2">0</td>
                </tr>
                <tr>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                    <td class="tg-0lax">4</td>
                </tr>
            </table>

            <div class ="buttons">
                <button class="myButton">1</button>
                <button class="myButton">2</button>
                <button class="myButton">3</button>
                <button class="myButton">4</button>
                <button class="myButton">5</button>
                <button class="myButton">6</button>
            </div>

            <div class = "playerTurn">
                <p style="text-align: center;"><strong>Your Turn</strong></p>
            </div>

            <div class ="leaderboard">
                <button class="leaderboardButton" onclick="location.href = 'leaderboard.php'">Leaderboard</button>
            </div>

            <script>
                let buttons = document.getElementsByClassName("myButton");
                let table = document.getElementById("board");
                let turnMessage = document.querySelector(".playerTurn p");
                var cell;

                function gameOver() {
                    var sum1 = 0, sum2 = 0;
                    for (let j = 0; j < 6; j++) {
                        sum1 = sum1 + Number(table.rows[1].cells[j].innerHTML);
                    }
                    for (let j = 6; j >= 1; j--) {
                        sum2 = sum2 + Number(table.rows[0].cells[j].innerHTML);
                    }
                    console.log("Sum1: " + sum1 + ", Sum2: " + sum2);
                    console.log("Player 1 Score Pit: " + Number(table.rows[0].cells[7].innerHTML));
                    console.log("Player 2 Score Pit: " + Number(table.rows[0].cells[0].innerHTML));
                    console.log("Boolean: " + (sum1 === 0 || sum2 === 0));
                    return (sum1 === 0 || sum2 === 0);
                }

                function checkGameOver() {
                    console.log("Checking game over...");
                    if (gameOver()) {
                        console.log("Game is over!");
                        // Disable buttons
                        for (let j = 0; j < buttons.length; j++) {
                            buttons[j].disabled = true;
                        }

                        // Move remaining marbles to score pits
                        let sum1 = 0, sum2 = 0;
                        for (let j = 0; j < 6; j++) {
                            sum1 = sum1 + Number(table.rows[1].cells[j].innerHTML);
                            table.rows[1].cells[j].innerHTML = 0;
                        }
                        for (let j = 6; j >= 1; j--) {
                            sum2 = sum2 + Number(table.rows[0].cells[j].innerHTML);
                            table.rows[0].cells[j].innerHTML = 0;
                        }
                        table.rows[0].cells[7].innerHTML = Number(table.rows[0].cells[7].innerHTML) + sum1;
                        table.rows[0].cells[0].innerHTML = Number(table.rows[0].cells[0].innerHTML) + sum2;


                        let username = document.cookie.replace(/(?:(?:^|.*;\s*)username\s*\=\s*([^;]*).*$)|^.*$/, "$1");
                        // Determine the winner
                        let winner = "";

                        const scorePlayer1 = Number(table.rows[0].cells[7].innerHTML);
                        const scorePlayer2 = Number(table.rows[0].cells[0].innerHTML);

                        if (scorePlayer1 > scorePlayer2) {
                            winner = username;
                            win = 1;
                            fetch('update_session.php', {
                                method: 'POST',
                                headers: {
                                    'Content-Type': 'application/json',
                                },
                                body: JSON.stringify({
                                    score: scorePlayer1,
                                    win: win
                                }),
                            })
                                    .then((response) => response.json())
                                    .then((data) => console.log(data));

                        } else if (scorePlayer1 < scorePlayer2) {
                            winner = "Computer";
                        }

                        // Update the message
                        turnMessage.textContent = "Game Over: " + (winner ? winner + " won" : "It's a tie");
                    }
                }



                for (let i = 0; i < buttons.length; i++) {
                    buttons[i].addEventListener("click", function () {
                        console.log("Button clicked: " + i);
                        // Disable buttons
                        for (let j = 0; j < buttons.length; j++) {
                            buttons[j].disabled = true;
                        }

                        cell = this.innerHTML - 1;
                        var row = 1;
                        let marbles = table.rows[row].cells[cell].innerHTML;
                        table.rows[row].cells[cell].innerHTML = 0;
                        cell++;
                        while (marbles > 0) {
                            if (cell > 0 && cell < 6 && row === 1) {
                                let m = Number(table.rows[row].cells[cell].innerHTML);
                                m += 1;
                                table.rows[row].cells[cell].innerHTML = m;
                                cell++;
                            } else if (cell === 6 && row === 1) {
                                row = 0;
                                cell = 7;
                                let m = Number(table.rows[row].cells[cell].innerHTML);
                                m = m + 1;
                                table.rows[row].cells[cell].innerHTML = m;
                                cell = cell - 1;
                            } else if (row === 0) {
                                if (cell === 1) {
                                    cell = 0;
                                    row = 1;
                                    let m = Number(table.rows[row].cells[cell].innerHTML);
                                    m = m + 1;
                                    table.rows[row].cells[cell].innerHTML = m;
                                } else {
                                    let m = Number(table.rows[row].cells[cell - 1].innerHTML);
                                    m = m + 1;
                                    table.rows[row].cells[cell].innerHTML = m;
                                    cell = cell - 1;
                                }
                            }
                            marbles--;
                        }
                        checkGameOver();
                        console.log("Game state after player's turn: ", table);

                        var startr, startc;
                        setTimeout(() => {
                            cell = Math.floor(Math.random() * (6)) + 1;
                            turnMessage.textContent = "Computer selected cell : " + cell;
                            console.log(cell);
                            row = 0;
                            marbles = Number(table.rows[row].cells[cell].innerHTML);

                            startr = row, startc = cell;
                            table.rows[startr].cells[startc].setAttribute('style', 'border:2px solid red; background:yellow');

                            table.rows[row].cells[cell].innerHTML = 0;
                            cell--;
                            while (marbles > 0) {
                                if (row === 0 && cell >= 1 && cell <= 6) {
                                    let m = Number(table.rows[row].cells[cell].innerHTML);
                                    m += 1;
                                    table.rows[row].cells[cell].innerHTML = m;
                                    cell--;
                                } else if (row === 0 && cell === 0) {
                                    let m = Number(table.rows[row].cells[cell].innerHTML);
                                    m += 1;
                                    table.rows[row].cells[cell].innerHTML = m;
                                    row = 1;
                                    cell = 0;
                                } else if (row === 1 && cell >= 0 && cell <= 5) {
                                    let m = Number(table.rows[row].cells[cell].innerHTML);
                                    m += 1;
                                    table.rows[row].cells[cell].innerHTML = m;
                                    cell++;
                                } else {
                                    row = 0;
                                }
                                marbles--;
                            }


                        }, 300);


                        setTimeout(() => {
                            // Enable buttons
                            table.rows[startr].cells[startc].setAttribute('style', 'border:1px solid black; background:white');
                            for (let j = 0; j < buttons.length; j++) {
                                buttons[j].disabled = false;
                            }
                            // Change message back to "Your Turn"
                            turnMessage.textContent = "Your Turn";
                            checkGameOver();
                            // 0.5 Second delay
                        }, 500);

                    });
                }
            </script>
            <form method="post" action="">
                <button id="logout" type="submit" name="logout">Log out</button>
            </form>
        </div>
    </body>
</html>

