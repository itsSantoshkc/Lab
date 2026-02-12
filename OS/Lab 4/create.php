<?php
include 'db.php';

if (isset($_POST['submit'])) {
    $title = $_POST['title'];

    $sql = "INSERT INTO todos (title) VALUES ('$title')";
    mysqli_query($conn, $sql);

    header("Location: index.php");
}
?>

<!DOCTYPE html>
<html>
<head><title>Add Task</title></head>
<body>

<h2>Add Task</h2>

<form method="POST">
    <input type="text" name="title" required>
    <button type="submit" name="submit">Save</button>
</form>

<a href="index.php">Back</a>

</body>
</html>
