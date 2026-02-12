<?php

$arr = [10,20,30,40,50];

echo "<br>Indexed Array <br>";
echo $arr[2]. "<br>";
echo $arr[4]. "<br>";

$assocArr = ["name" => "Ram","age" => 25,"city" => "KTM"];

echo "<br>Associative Array <br>";
echo $assocArr["name"]. "<br>";
echo $assocArr["age"]. "<br>";

$ma = [
    ["John",25,"A"],
    ["Jane",23,"B"],
    ["Bob",27,"A"],
];

echo "<br>Multi dimensional Array <br>";
echo $ma[0][0]. "<br>";
echo $ma[1][2]. "<br>";


?>