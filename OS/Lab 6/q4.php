<?php
class Employee
{
    protected $name;
    protected $address;

    public function __construct($name, $address)
    {
        $this->name = $name;
        $this->address = $address;
    }

    public function setName($name)
    {
        $this->name = $name;
    }

    public function setAddress($address)
    {
        $this->address = $address;
    }
}

class Permanent extends Employee
{
    private $salary;
    private $post;

    public function __construct($name, $address, $salary, $post)
    {
        parent::__construct($name, $address);

        $this->salary = $salary;
        $this->post = $post;
    }

    public function setSalary($salary)
    {
        $this->salary = $salary;
    }

    public function setPost($post)
    {
        $this->post = $post;
    }

    public function displayAll()
    {
        echo "<strong>Name:</strong> " . $this->name . "<br>";
        echo "<strong>Address:</strong> " . $this->address . "<br>";
        echo "<strong>Salary:</strong> $" . number_format($this->salary, 2) . "<br>";
        echo "<strong>Post:</strong> " . $this->post . "<br>";
        echo "<hr>";
    }
}

echo "<h1>Employee Records</h1>";

$employee_data = [
    ["Alice", "789 Pine", 60000, "Designer"],
    ["Bob", "101 Maple", 55000, "QA Tester"],
    // ... 18 more entries
];

foreach ($employee_data as $data) {
    $emp = new Permanent($data[0], $data[1], $data[2], $data[3]);
    $emp->displayAll();
}
?>