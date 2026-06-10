// enum Department
// {
//     Computer,Management,Science,Humanities
// }

namespace Lab;

public delegate void Notify();


class Publisher
{
    public event Notify? ProcessCompleted;

    public void StartProcess()
    {
        Console.WriteLine("Starting process");
        Thread.Sleep(2000);
        OnProcessCompleted();
    }

    public virtual void OnProcessCompleted()
    {
        ProcessCompleted?.Invoke();
    }
}

class Subscriber
{
    public void OnProcessCompleted()
    {
        Console.WriteLine("Subscriber OnProcessCompleted");
    }
    
    public void OnProcessStarted()
    {
        Console.WriteLine("Subscriber Process Started");
    }
}

// class Employee
// {
//     // 1. Required property
//     public required int Id { get; set; }
//
//     // 2. Field-backed property (with validation)
//     private string name;
//     public string Name
//     {
//         get => name;
//         set
//         {
//             if (!string.IsNullOrWhiteSpace(value))
//                 name = value;
//         }
//     }
//
//     // 3. Property with backing field
//     private double salary;
//     public double Salary
//     {
//         get { return salary; }
//         set
//         {
//             if (value >= 0)
//                 salary = value;
//         }
//     }
//
//     // 4. Expression-bodied property (computed)
//     public double AnnualSalary => salary * 12;
//
//     // 5. Access control (private setter)
//     public string Department { get; private set; } = "Not Assigned";
//
//     // Method to modify controlled property
//     public void SetDepartment(string dept)
//     {
//         if (!string.IsNullOrWhiteSpace(dept))
//             Department = dept;
//     }
// }

// Example usage
class Program
{
    static void Main()
    {
        // Employee emp = new Employee
        // {
        //     Id = 101,
        //     Name = "John"
        // };
        //
        // emp.Salary = 4000;
        // emp.SetDepartment("IT");
        //
        // Console.WriteLine(emp.Id);
        // Console.WriteLine(emp.Name);
        // Console.WriteLine(emp.AnnualSalary);
        // Console.WriteLine(emp.Department);

        // foreach (Department d in Enum.GetValues(typeof(Department)))
        // {
        //     Console.WriteLine(d);
        // }
        // Notify n = new Notify();
        // DelExample d = new DelExample(n.sendMessage);
        // d("Hello World!");
        
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();
        Notify n = new Notify(subscriber.OnProcessStarted);
        n.Invoke();
        
        publisher.ProcessCompleted += subscriber.OnProcessStarted;
        publisher.ProcessCompleted += subscriber.OnProcessCompleted;
        publisher.StartProcess();
        
        
        
    }
}