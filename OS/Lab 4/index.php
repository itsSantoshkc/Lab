<?php include 'db.php'; ?>

<!DOCTYPE html>
<html>
<head>
    <title>Todo App</title>
</head>
<body>

<h2>Todo List</h2>
<a href="create.php">Add New Task</a>
<hr>

<?php
$result = mysqli_query($conn, "SELECT * FROM todos ORDER BY id DESC");

while ($row = mysqli_fetch_assoc($result)) {
    echo "<p>";
    echo $row['title'] . " ";
    echo "<a href='edit.php?id=".$row['id']."'>Edit</a> ";
    echo "<a href='delete.php?id=".$row['id']."' onclick='return confirm(\"Delete?\")'>Delete</a>";
    echo "</p>";
}
?>

</body>
</html>
