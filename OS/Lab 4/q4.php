<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {

    $reg_no = trim($_POST['reg_no'] ?? '');
    $email  = trim($_POST['email'] ?? '');
    $file   = $_FILES['project_file'] ?? null;

    // Mandatory fields
    if (empty($reg_no)) {
        echo "<p style='color:red'>Registration number is required.</p>";
        exit;
    }

    if (empty($email)) {
        echo "<p style='color:red'>Email is required.</p>";
        exit;
    }

    if (!$file || $file['name'] == '') {
        echo "<p style='color:red'>Project file is required.</p>";
        exit;
    }

    // Email format validation
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "<p style='color:red'>Invalid email format.</p>";
        exit;
    }

    // Allowed file formats
    $allowed_ext = ['pdf', 'doc', 'docx', 'ppt', 'pptx', 'jpeg', 'jpg'];
    $filename = $file['name'];
    $filesize = $file['size'];
    $ext = strtolower(pathinfo($filename, PATHINFO_EXTENSION));

    if (!in_array($ext, $allowed_ext)) {
        echo "<p style='color:red'>File type must be PDF, DOC, DOCX, PPT, PPTX, or JPEG.</p>";
        exit;
    }

    // Max 5MB file size
    if ($filesize > 5 * 1024 * 1024) {
        echo "<p style='color:red'>File size must be less than 5MB.</p>";
        exit;
    }

    // Upload file to server
    $upload_dir = "uploads/";
    if (!is_dir($upload_dir)) {
        mkdir($upload_dir);
    }

    $target_path = $upload_dir . basename($filename);

    if (!move_uploaded_file($file['tmp_name'], $target_path)) {
        echo "<p style='color:red'>Error uploading file.</p>";
        exit;
    }

    require "db.php";
    // INSERT INTO DATABASE
    $query = "INSERT INTO submissions (reg_no, email, file_path)
              VALUES ('$reg_no', '$email', '$target_path')";

    if (mysqli_query($conn, $query)) {
        echo "<p style='color:green'>Project submitted successfully!</p>";
    } else {
        echo "<p style='color:red'>Database error: " . mysqli_error($conn) . "</p>";
    }

    mysqli_close($conn);
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Project Submission</title>
</head>

<body>
    <h2>Project Submission Form</h2>

    <form action="q4.php" method="post" enctype="multipart/form-data">

        TU Registration Number:
        <input type="text" name="reg_no"><br><br>

        Email Address:
        <input type="text" name="email"><br><br>

        Upload your Project File:
        <input type="file" name="project_file"><br><br>

        <button type="submit">Submit Project</button>

    </form>

</body>
</html>