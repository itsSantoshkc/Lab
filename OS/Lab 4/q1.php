<?php
session_start();

function authenticateStudent($username, $password)
{
    require "db.php";
    $sql = "SELECT * FROM student WHERE username = '$username'";
    $result = mysqli_query($conn, $sql);

    // Check if user exists
    if (mysqli_num_rows($result) > 0) {
        // Get student from db
        $student = mysqli_fetch_assoc($result);

        // Verify the password against the hashed password
        if (password_verify($password, $student['password'])) {
            // Credentials are valid
            $_SESSION["username"] = $username;

            // Close connection
            mysqli_close($conn);

            // Redirect to dashboard
            header("Location: dashboard.php");
            exit();
        } else {
            // Invalid password
            mysqli_close($conn);
            echo "Invalid username/password";
        }
    } else {
        // Invalid username
        mysqli_close($conn);
        echo "Invalid username/password";
    }
}


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $password = $_POST["password"];

    authenticateStudent($username, $password);
}
?>
<!DOCTYPE html>
<html>

<head>
    <title>Login</title>
</head>

<body>
    <form method="post" action="login.php">
        Username: <input type="text" name="username" required><br><br>
        Password: <input type="password" name="password" required><br><br>
        <input type="submit" value="Login">
    </form>
    <br>

</body>

</html>