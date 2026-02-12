<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name      = trim($_POST['name'] ?? '');
    $email     = trim($_POST['email'] ?? '');
    $gender    = trim($_POST['gender'] ?? '');
    $education = trim($_POST['education'] ?? '');

    if (empty($name)) {
        echo "<p style='color:red'>Name is required.</p>";
        exit;
    }

    if (empty($email)) {
        echo "<p style='color:red'>Email is required.</p>";
        exit;
    }

    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "<p style='color:red'>Invalid email format.</p>";
        exit;
    }

    if (empty($gender)) {
        echo "<p style='color:red'>Gender is required.</p>";
        exit;
    }

    if (empty($education)) {
        echo "<p style='color:red'>Please select your education field.</p>";
        exit;
    }

    require "db.php";
    $query = "INSERT INTO students (`name`, `email`, `gender`, `education`)
              VALUES ('$name', '$email', '$gender', '$education')";

    if (mysqli_query($conn, $query)) {
        echo "<p style='color:green'>Registration successful!</p>";
    } else {
        echo "<p style='color:red'>Database error: " . mysqli_error($conn) . "</p>";
    }

    mysqli_close($conn);
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Registration Form</title>
    <meta charset="UTF-8">
</head>

<body>

<h2>Student Registration Form</h2>

<form action="q5.php" method="post">

    Name:
    <input type="text" name="name"><br><br>

    Email:
    <input type="text" name="email"><br><br>

    Gender:
    <input type="radio" name="gender" value="Male"> Male
    <input type="radio" name="gender" value="Female"> Female
    <input type="radio" name="gender" value="Other"> Other
    <br><br>

    Education:
    <select name="education">
        <option value="">-- Select Education Field --</option>
        <option value="Science">Science</option>
        <option value="Management">Management</option>
        <option value="Humanities">Humanities</option>
        <option value="Engineering">Engineering</option>
        <option value="IT">IT</option>
    </select>
    <br><br>

    <button type="submit">Register</button>

</form>

</body>
</html>