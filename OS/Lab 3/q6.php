<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
    <style>
      p,
      caption {
        font-weight: bold;
        text-align: center;
        margin: 30px 0;
      }

      table {
        width: 70%;
        border-collapse: collapse;
        margin: 0 auto;
      }

      th,
      td {
        border: 1px solid #ccc;
        padding: 10px 20px;
      }
    </style>
  </head>

  <body>
    <?php
$file = fopen("data.csv", "w");

fwrite($file, "name,age,city\n");
fwrite($file, "John,25,New York\n");
fwrite($file, "Sita,30,Kathmandu\n");

fclose($file);
echo "<p>CSV file created.</p>";
?>
    <table>
      <caption>
        Table 1: Reading CSV File
      </caption>
      <tr>
        <th>Name</th>
        <th>Age</th>
        <th>City</th>
      </tr>

      <tr>
        <td>Ram</td>
        <td>29</td>
        <td>Lalitpur</td>
      </tr>
      <?php
$file = fopen("data.csv", "r");

if ($file) {
    while (($line = fgets($file)) !== false) {
        if ($line == "name,age,city\n") {
            continue;
        }
        $words = explode(',', $line);
        echo "<tr>";
        foreach ($words as $word) {
            echo "<td>$word</td>";
        }
        echo "</tr>";
    }
    fclose($file);
}
?>
    </table>
  </body>
</html>