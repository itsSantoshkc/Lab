using System;
using System.Collections.Generic;
using System.Linq;

class Student
{
    public int StudentId { get; set; }
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
        List<Student> students = new List<Student>()
        {
            new Student { StudentId = 1, Name = "Ram", DepartmentId = 101 },
            new Student { StudentId = 2, Name = "Shyam", DepartmentId = 102 },
            new Student { StudentId = 3, Name = "Hari", DepartmentId = 101 }
        };

        List<Department> departments = new List<Department>()
        {
            new Department { DepartmentId = 101, DepartmentName = "Computer Science" },
            new Department { DepartmentId = 102, DepartmentName = "Management" }
        };

        var result = students.Join(
            departments,
            s => s.DepartmentId,
            d => d.DepartmentId,
            (s, d) => new
            {
                StudentName = s.Name,
                DepartmentName = d.DepartmentName
            });

        foreach (var item in result)
        {
            Console.WriteLine(
                $"Student: {item.StudentName}, Department: {item.DepartmentName}");
        }
    }
}