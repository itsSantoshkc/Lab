<?php
session_start();

$_SESSION['name'] = "Santosh";

echo $_SESSION['name'];   


session_unset();  
session_destroy();



?>
