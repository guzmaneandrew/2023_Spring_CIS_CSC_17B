<?php
require_once 'dbh.inc.php';

$query = "SELECT * FROM users ORDER BY users_win DESC";
$result = $conn->query($query);

// Check if there are any rows returned
if ($result->num_rows > 0) {
    ?>
    <!DOCTYPE html>
    <html>
        <head>
            <title>Leaderboard</title>
            <style>
                table {
                    width: 100%;
                    border-collapse: collapse;
                }

                th, td {
                    padding: 8px;
                    text-align: left;
                    border-bottom: 1px solid #ddd;
                }
            </style>
        </head>
        <body>
            <h1>Leaderboard</h1>
            <table>
                <thead>
                    <tr>
                        <th>Rank</th>
                        <th>Name</th>
                        <th>Score</th>
                        <th>Wins</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    $rank = 1;
                    while ($row = $result->fetch_assoc()) {
                        $name = $row['users_name'];
                        $score = $row['users_score'];
                        $wins = $row['users_win'];
                        echo "<tr><td>$rank</td><td>$name</td><td>$score</td><td>$wins</td></tr>";
                        $rank++;
                    }
                    ?>
                </tbody>
            </table>
            <button class="returnButton" onclick="location.href='mancala.php'">Return</button>
        </body>
    </html>
    <?php
} else {
    echo "No data found in the leaderboard.";
}
