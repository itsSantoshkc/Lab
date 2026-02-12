<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = trim($_POST['name'] ?? '');
    $patient_id = trim($_POST['patient_id'] ?? '');
    $mobile = trim($_POST['mobile'] ?? '');
    $gender = trim($_POST['gender'] ?? '');
    $address = trim($_POST['address'] ?? '');
    $dob = trim($_POST['dob'] ?? '');
    $doctor_name = trim($_POST['doctor_name'] ?? '');

    if (empty($name)) {
        echo "<p style='color: red;'>Name is required</p>";
        exit;
    }

    if (empty($patient_id)) {
        echo "<p style='color: red;'>Patient id is required</p>";
        exit;
    }

    if (empty($mobile)) {
        echo "<p style='color: red;'>Mobile number is required</p>";
        exit;
    }
    // Mobile validation: 10 digits starting with 98, 97, or 96
    if (!preg_match('/^(98|97|96)\d{8}$/', $mobile)) {
        echo "<p style='color: red;'>Mobile must be 10 digits and start with 98, 97, or 96</p>";
        exit;
    }

    if (empty($gender)) {
        echo "<p style='color: red;'>Gender is required</p>";
        exit;
    }

    if (empty($address)) {
        echo "<p style='color: red;'>Address is required</p>";
        exit;
    }

    if (empty($dob)) {
        echo "<p style='color: red;'>Date of birth is required</p>";
        exit;
    }

    // DOB validation: YYYY-MM-DD format
    if (!preg_match('/^\d{4}-\d{2}-\d{2}$/', $dob)) {
        echo "<p style='color: red;'>Date of birth must be in YYYY-MM-DD format</p>";
        exit;
    }

    if (empty($doctor_name)) {
        echo "<p style='color: red;'>Doctor name is required</p>";
        exit;
    }

    require_once 'db.php';
    $query = "INSERT INTO patients (`name`, `patient_id`, `mobile`, `gender`, `address`, `dob`, `doctor_name`)
                  VALUES ('$name', '$patient_id', '$mobile', '$gender', '$address', '$dob', '$doctor_name');";

    if (mysqli_query($conn, $query)) {
        echo "Patient registered successfully!<br>";
        mysqli_close($conn);
    } else {
        echo "<p style='color: red;'>Error inserting data: " . mysqli_error($conn) . "</p>";
        mysqli_close($conn);
        exit;
    }
}
?>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="q2.php" method="post">
        Name: <input type="text" name="name"><br><br>
        Patient ID: <input type="text" name="patient_id"><br><br>
        Mobile: <input type="text" name="mobile"><br><br>

        Gender:
        <input type="radio" name="gender" value="Male"> Male
        <input type="radio" name="gender" value="Female"> Female
        <input type="radio" name="gender" value="Other"> Other
        <br><br>

        Address: <input type="text" name="address"><br><br>

        Date of Birth: <input type="text" name="dob" placeholder="YYYY-MM-DD"><br><br>

        Doctor Name: <input type="text" name="doctor_name"><br><br>

        <button type="submit">Register Patient</button>
    </form>
</body>

</html>