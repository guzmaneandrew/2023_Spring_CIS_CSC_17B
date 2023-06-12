<?php
session_start();
$admin = $_SESSION["users_status"];
if ($admin !== 1) {
    session_destroy();
    header("location: index.php?error=noaccess");
    exit();
}
?>
<!DOCTYPE html>
<html>
    <head>
        <title>Admin Page</title>
        <link rel="stylesheet" href="adminstyle.css">
    </head>
    <body>
        <?php
        require_once 'dbh.inc.php';

        $users = [];

        $query = "SELECT * FROM users";
        $result = mysqli_query($conn, $query);
        while ($row = mysqli_fetch_assoc($result)) {
            $users[] = $row;
        }

        if (isset($_POST['logout'])) {
            session_destroy();
            header("location: index.php");
            exit();
        }

        if (isset($_POST['update'])) {
            $passwords = $_POST['password'];
            $admin = $_POST['admin'];

            foreach ($passwords as $userID => $password) {
                $sql = "UPDATE users SET users_pwd = ? WHERE users_id = ?";
                $stmt = mysqli_prepare($conn, $sql);
                mysqli_stmt_bind_param($stmt, "si", $password, $userID);
                $success = mysqli_stmt_execute($stmt);
                mysqli_stmt_close($stmt);
            }

            foreach ($admin as $userID => $adminStatus) {
                $sql = "UPDATE users SET users_status = ? WHERE users_id = ?";
                $stmt = mysqli_prepare($conn, $sql);
                mysqli_stmt_bind_param($stmt, "ii", $adminStatus, $userID);
                $success = mysqli_stmt_execute($stmt);
                mysqli_stmt_close($stmt);
            }

            if ($success) {
                $message = "Update successful.";
            } else {
                $message = "Update failed. Error: " . mysqli_error($conn);
            }

            header("Location: " . $_SERVER['PHP_SELF']);
            exit();
        }
        if (isset($_POST['remove'])) {
            $userID = $_POST['remove'];

            $sql = "DELETE FROM users WHERE users_id = ?";
            $stmt = mysqli_prepare($conn, $sql);
            mysqli_stmt_bind_param($stmt, "i", $userID);
            $success = mysqli_stmt_execute($stmt);
            mysqli_stmt_close($stmt);

            if ($success) {
                $message = "User successfully removed.";
            } else {
                $message = "Failed to remove user. Error: " . mysqli_error($conn);
            }

            $users = [];

            $query = "SELECT * FROM users";
            $result = mysqli_query($conn, $query);
            while ($row = mysqli_fetch_assoc($result)) {
                $users[] = $row;
            }

            // Refresh the page after removing the user
            header("Location: " . $_SERVER['PHP_SELF']);
            exit();
        }
        ?>

        <div>
            <?php if (isset($message)) echo $message; ?>
        </div>

        <form method="post" action="">
            <table>
                <thead>
                    <tr>
                        <th>Username</th>
                        <th>Password</th>
                        <th>Score</th>
                        <th>Wins</th>
                        <th>Admin Status</th>
                        <th>Action</th>
                        <th>Delete</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($users as $user): ?>
                        <tr>
                            <td>
                                <input type="text" name="name[]" value="<?php echo $user['users_name']; ?>" disabled>
                                <input type="hidden" name="userID[]" value="<?php echo $user['users_id']; ?>">
                            </td>
                            <td>
                                <input type="text" name="password[<?php echo $user['users_id']; ?>]" value="<?php echo $user['users_pwd']; ?>">
                            </td>
                            <td>
                                <input type="text" name="score[]" value="<?php echo $user['users_score']; ?>" disabled>
                            </td>
                            <td>
                                <input type="text" name="wins[]" value="<?php echo $user['users_win']; ?>" disabled>
                            </td>
                            <td>
                                <select name="admin[<?php echo $user['users_id']; ?>]">
                                    <option value="0" <?php if ($user['users_status'] == 0) echo 'selected'; ?>>False</option>
                                    <option value="1" <?php if ($user['users_status'] == 1) echo 'selected'; ?>>True</option>
                                </select>
                            </td>
                            <td>
                                <button type="submit" name="update">Update</button>
                            </td>
                            <td>
                                <button type="submit" name="remove" value="<?php echo $user['users_id']; ?>" style="background-color: #f44336">Remove</button>
                            </td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>

            <button id="logout" type="submit" name="logout">Log out</button>
        </form>
    </body>
</html>