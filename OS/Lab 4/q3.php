<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $fullname  = trim($_POST['fullname'] ?? '');
    $email     = trim($_POST['email'] ?? '');
    $username  = trim($_POST['username'] ?? '');
    $password  = trim($_POST['password'] ?? '');

    if (empty($fullname)) {
        echo "<p style='color:red'>Full name is required</p>";
        exit;
    }
    if (strlen($fullname) > 40) {
        echo "<p style='color:red'>Full name must be up to 40 characters</p>";
        exit;
    }

    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "<p style='color:red'>Invalid email address</p>";
        exit;
    }

    // Username: must start with letters and followed by numbers
    // Example valid: abc123 , User45 , hello9
    if (!preg_match('/^[A-Za-z]+[0-9]+$/', $username)) {
        echo "<p style='color:red'>Username must start with letters and follow with numbers</p>";
        exit;
    }

    // Password must be longer than 8 characters
    if (strlen($password) <= 8) {
        echo "<p style='color:red'>Password must be more than 8 characters</p>";
        exit;
    }

    // Hash the password
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

    require_once 'db.php';
    $query = "INSERT INTO users (`fullname`, `email`, `username`, `password`)
              VALUES ('$fullname', '$email', '$username', '$hashedPassword')";

    if (mysqli_query($conn, $query)) {
        echo "<p style='color:green'>User Registered Successfully!</p>";
    } else {
        echo "<p style='color:red'>Error inserting data: " . mysqli_error($conn) . "</p>";
    }

    mysqli_close($conn);
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Registration</title>
    <meta charset="UTF-8">
</head>

<body>
    <h2>User Registration Form</h2>

    <form action="q3.php" method="post">

        Full Name:
        <input type="text" name="fullname"><br><br>

        Email:
        <input type="text" name="email"><br><br>

        Username:
        <input type="text" name="username" placeholder="e.g., user123"><br><br>

        Password:
        <input type="password" name="password"><br><br>

        <button type="submit">Register</button>
    </form>

</body>
</html>