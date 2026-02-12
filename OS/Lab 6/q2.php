<?php
class Person
{
    protected $name;
    protected $age;

    public function __construct($name, $age)
    {
        $this->name = $name;
        $this->age = $age;
        echo "A new Person object created.<br>";
    }

    public function introduce()
    {
        echo "Hello, my name is {$this->name} and I am {$this->age} years old.<br>";
    }
}

class Student extends Person
{
    private $studentId;

    public function __construct($name, $age, $studentId)
    {
        parent::__construct($name, $age);

        $this->studentId = $studentId;
        echo "A Student object created.<br>";
    }

    public function study()
    {
        echo "I am a student with ID {$this->studentId}, and I am studying.<br>";
    }

    public function introduce()
    {
        // parent::introduce();
        echo "Hi, I'm a student. My name is {$this->name} and my ID is {$this->studentId}.<br>";
    }
}

class Employee extends Person
{
    private $employeeId;
    private $salary;

    public function __construct($name, $age, $employeeId, $salary)
    {
        parent::__construct($name, $age);

        $this->employeeId = $employeeId;
        $this->salary = $salary;
        echo "An Employee object created.<br>";
    }

    public function work()
    {
        echo "I am an employee with ID {$this->employeeId}, and I am working.<br>";
    }

    public function introduce()
    {
        echo "Hello, I am an employee. My name is {$this->name} and I earn \${$this->salary}.<br>";
    }
}

echo "--- Creating a Student ---<br>";
$student1 = new Student("Alice", 20, "S12345");
$student1->introduce();
$student1->study();
echo "<br>";

echo "--- Creating an Employee ---<br>";
$employee1 = new Employee("Bob", 35, "E9876", 50000);
$employee1->introduce();
$employee1->work();
echo "<br>";

echo "--- Creating just a Person ---<br>";
$person1 = new Person("Charlie", 50);
$person1->introduce();
echo "<br>";