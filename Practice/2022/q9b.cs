using System;
using System.Collections.Generic;
using System.Linq;

public class Employee
{
    public string Name { get; set; }
    public decimal Salary { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        // Initialize list of 5 employees
        List<Employee> employees = new List<Employee>
        {
            new Employee { Name = "Aarav Sharma", Salary = 65000 },
            new Employee { Name = "Priya Thapa", Salary = 85000 },
            new Employee { Name = "Bikash Gurung", Salary = 50000 },
            new Employee { Name = "Sneha Shrestha", Salary = 92000 },
            new Employee { Name = "Rohan Karki", Salary = 70000 }
        };

        // 1. Compute aggregate salary using the LINQ Sum operator
        decimal totalSalary = employees.Sum(e => e.Salary);
        Console.WriteLine(totalSalary);


        var sortedEmployee = employees.OrderByDescending(e => e.Salary);

        foreach(var emp in sortedEmployee){
          Console.Write(emp.Name);
          Console.WriteLine(emp.Salary);
        }
    }
}
