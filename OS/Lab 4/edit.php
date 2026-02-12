<?php
include 'db.php';

$id = $_GET['id'];

if (isset($_POST['update'])) {
    $title = $_POST['title'];

    $sql = "UPDATE todos SET title='$title' WHERE id=$id";
    mysqli_query($conn, $sql);

    header("Location: index.php");
}

$result = mysqli_query($conn, "SELECT * FROM todos WHERE id=$id");
$row = mysqli_fetch_assoc($result);
?>

<!DOCTYPE html>
<html>
<head><title>Edit Task</title></head>
<body>

<h2>Edit Task</h2>

<form method="POST">
    <input type="text" name="title" value="<?php echo $row['title']; ?>" required>
    <button type="submit" name="update">Update</button>
</form>

<a href="index.php">Back</a>

</body>
</html>
