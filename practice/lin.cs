// What is LINQ? Write a program to select employees whose salary is greater than 20000 and whose address is kathmandu using LINQ
using System.Linq;
class Employee
{
    private int eid;
    public int deptId;
    public  string name {get;set;}
    public string address {get;set;}

    public long salary {get;set;}

    public Employee(int eid,string name,long salary,int deptId,string address)
    {
        this.eid = eid;
        this.name = name;
        this.salary = salary;
        this.deptId = deptId;
        this.address = address;
    }


    public void DisplayEmployeeDetails()
    {
        Console.WriteLine($"Employee Id {this.eid}\nName : {this.name}\nSalary: {this.salary}\nAddress: {this.address}");
    }

}

class Department
{
    public int deptId {get;set;}
    public string departmentName {get;set;}

    public Department(int did,string dname)
    {
        this.departmentName = dname;
        this.deptId = did;
    }

}

class Program
{
    static void Main()
    {
        Employee[] employees = 
        {
            new Employee (1,"Ram",50000,1,"KTM"),
            new Employee (2,"Shyam",30000,2,"PKR"),
            new Employee (3,"Hari",60000,1,"KTM"),
            new Employee (4,"Sita",70000,2,"PKR"),
            new Employee (5,"Gita",80000,1,"LTP"),
        };

        Department[] depts = {new Department(1,"IT"),new Department(2,"Marketing")};

        // var res = employees.Join(depts,employee => employee.deptId,dept => dept.deptId,(
        //     employee,dept) => new {
        //         Name = employee.name,
        //     DepartmentName = dept.departmentName} 
        // );

        // var res = 
        // from employee in employees
        // join dept in depts
        // on  employee.deptId equals dept.deptId
        // select new
        // {
        //     Name = employee.name,
        //      DepartmentName = dept.departmentName
        // };

        // foreach(var r in res)
        // {
        //     Console.WriteLine($"{r.Name} {r.DepartmentName}");
        // }
        //  var Result = employees.Where(employee => employee.salary > 20000 && employee.address == "PKR");
        // var Result = from emp in employees 
        // where emp.address == "KTM" && emp.salary >= 50000
        // select emp;

        var Result = employees.OrderByDescending(emp => emp.salary);

        // long totalSalary = employees.Aggregate(0L,(total, emp) => total + emp.salary);

        var groups = employees.GroupBy(emp => emp.address);

        foreach (var group in groups)
        {
            Console.WriteLine($"\nDepartment: {group.Key}");

            foreach (var emp in group)
            {
                Console.WriteLine(emp.name);
            }
        }

        //  foreach (var employee in Result)
        //  {
        //     employee.DisplayEmployeeDetails();
        //  }

    }
}
