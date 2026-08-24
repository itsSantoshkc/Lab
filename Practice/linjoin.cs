using System;
using System.Collections.Generic;
using System.Linq;

class Employee
{
    public int EmployeeId { get; set; }
    public string Name { get; set; }
    public int DepartmentId { get; set; }
}

class Department
{
    public int DepartmentId { get; set; }
    public string DepartmentName { get; set; }
}

class Program
{
    static void Main()
    {
        List<Employee> employees = new List<Employee>
        {
            new Employee { EmployeeId = 1, Name = "Ram", DepartmentId = 101 },
            new Employee { EmployeeId = 2, Name = "Shyam", DepartmentId = 102 },
            new Employee { EmployeeId = 3, Name = "Hari", DepartmentId = 101 },
            new Employee { EmployeeId = 4, Name = "Sita", DepartmentId = 103 }
        };

        List<Department> departments = new List<Department>
        {
            new Department { DepartmentId = 101, DepartmentName = "IT" },
            new Department { DepartmentId = 102, DepartmentName = "HR" },
            new Department { DepartmentId = 103, DepartmentName = "Finance" }
        };

        var result = employees.Join(
           departments,
           emp => emp.DepartmentId,
           dept => dept.DepartmentId,
           (emp,dept) => new
           {
               EmployeeName = emp.Name,
                DepartmentName = dept.DepartmentName
           }
        );

        foreach (var item in result)
        {
            Console.WriteLine(
                item.EmployeeName + " - " + item.DepartmentName
            );
        }
    }
}