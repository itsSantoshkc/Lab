<?php
// Database credentials
$servername = "localhost";
$dbusername = "root";
$dbpassword = "";
$database = "mydb";    // assumes databse exists

// Create connection using MySQLi (procedural)
$conn = mysqli_connect($servername, $dbusername, $dbpassword, $database);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}