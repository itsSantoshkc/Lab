using System;

class Employee
{
    // 1. Required property
    public required int Id { get; set; }

    // 2. Field-backed property (with validation)
    private string name;
    public string Name
    {
        get => name;
        set
        {
                name = value;
        }
    }

    // 3. Property with backing field
    private double salary;
    public double Salary
    {
        get { return salary; }
        set
        {
            if (value >= 0)
                salary = value;
        }
    }

    // 4. Expression-bodied property (computed)
    public double AnnualSalary => salary * 12;

    // 5. Access control (private setter)
    public string Department { get; private set; } = "Not Assigned";

    // Method to modify controlled property
    public void SetDepartment(string dept)
    {
        if (!string.IsNullOrWhiteSpace(dept))
            Department = dept;
    }
}

// Example usage
class Program
{
    static void Main()
    {
        Employee emp = new Employee
        {
            Id = 101,
            Name = "John"
        };

        emp.Salary = 4000;
        emp.SetDepartment("IT");

        Console.WriteLine(emp.Id);
        Console.WriteLine(emp.Name);
        Console.WriteLine(emp.AnnualSalary);
        Console.WriteLine(emp.Department);
    }
}