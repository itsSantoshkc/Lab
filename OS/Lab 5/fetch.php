<?php
include "db.php";

$sql = "SELECT * FROM posts";
$result = mysqli_query($conn, $sql);

$output = "";

while ($row = mysqli_fetch_assoc($result)) {
    $output .= "<h3>".$row['title']."</h3>";
    $output .= "<p>".$row['content']."</p>";
    $output .= "<hr>";
}

echo $output;
?>
