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
    ["Charlie", "202 Oak", 72000, "Software Engineer"],
    ["David", "303 Birch", 48000, "Support Engineer"],
    ["Emma", "404 Cedar", 65000, "HR Manager"],
    ["Frank", "505 Walnut", 70000, "Project Manager"],
    ["Grace", "606 Cherry", 52000, "Business Analyst"],
    ["Hannah", "707 Ash", 58000, "Marketing Executive"],
    ["Ian", "808 Spruce", 75000, "DevOps Engineer"],
    ["Jack", "909 Poplar", 62000, "UI/UX Designer"],
    ["Karen", "111 Willow", 54000, "Content Writer"],
    ["Leo", "222 Cypress", 81000, "Technical Lead"],
    ["Mia", "333 Redwood", 67000, "Finance Analyst"],
    ["Nathan", "444 Magnolia", 59000, "System Administrator"],
    ["Olivia", "555 Elm", 73000, "Product Manager"],
    ["Paul", "666 Fir", 56000, "QA Analyst"],
    ["Quincy", "777 Palm", 69000, "Database Administrator"],
    ["Rachel", "888 Maplewood", 64000, "Recruiter"],
    ["Sam", "999 Aspen", 71000, "Backend Developer"],
    ["Tina", "121 River", 53000, "Frontend Developer"],
    ["Uma", "131 Lake", 76000, "Data Scientist"],
    ["Victor", "141 Hill", 68000, "Network Engineer"]
];


foreach ($employee_data as $data) {
    $emp = new Permanent($data[0], $data[1], $data[2], $data[3]);
    $emp->displayAll();
}
?>