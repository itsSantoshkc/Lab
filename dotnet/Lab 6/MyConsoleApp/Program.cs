using System;
using System.Data;
using System.Runtime.InteropServices;
using Microsoft.Data.SqlClient;

class Employee
{
    public int eid;
    public string name;
    public string department;
    public decimal salary;

    public Employee(int eid, string name, string department, decimal salary)
    {
        this.eid = eid;
        this.name = name;
        this.department = department;
        this.salary = salary;
    }
}

class Program
{
    static void Main()
    {
        string connectionString = "Server=localhost,1433;Database=LabDb;User Id=Santosh;Password=Password1!;TrustServerCertificate=True;";
        SqlConnection conn = new SqlConnection(connectionString);
        conn.Open(); // FIX 1: open() → Open() (C# is case-sensitive)
string createTable = @"
    IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Employee' AND xtype='U')
    CREATE TABLE Employee (
        Eid        INT            PRIMARY KEY,
        Name       NVARCHAR(100)  NOT NULL,
        Department NVARCHAR(100)  NOT NULL,
        Salary     DECIMAL(18,2)  NOT NULL
    )";
SqlCommand createCmd = new SqlCommand(createTable, conn);
createCmd.ExecuteNonQuery();
        Employee[] employees =
        {
            new Employee(11, "John",  "IT",        500.00m), // FIX 2: added 'm' suffix — decimal literals
            new Employee(21, "Alice", "HR",        45000.00m), //         need 'm', else they're double
            new Employee(31, "Bob",   "Finance",   55000.00m), //         and won't compile
            new Employee(41, "Sara",  "Marketing", 48000.00m), // FIX 3: added 2 missing employees
            new Employee(51, "Mike",  "IT",        6200000.00m)  //         (task requires 5, only 3 were present)
        };

        foreach (var emp in employees)
        {
            // FIX 4: string values (Name, Department) must be wrapped in single quotes in SQL
            string query = $"INSERT INTO Employee (Eid, Name, Department, Salary) VALUES({emp.eid}, '{emp.name}', '{emp.department}', {emp.salary});";
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.ExecuteNonQuery();
        }

        // FIX 5: "SELECT TOP 1 FROM ..." is invalid SQL — must specify columns; used *
        SqlCommand highCmd = new SqlCommand("SELECT TOP 1 * FROM Employee ORDER BY Salary DESC", conn);
        SqlDataReader highReader = highCmd.ExecuteReader();
        Console.WriteLine("Highest Salary Employee:");
        while (highReader.Read())
        {
            Console.WriteLine($"Eid: {highReader["Eid"]}, Name: {highReader["Name"]}, Department: {highReader["Department"]}, Salary: {highReader["Salary"]}");
        }
        highReader.Close(); // FIX 6: reader must be closed before opening another one on the same connection

        // FIX 7: lowest salary query was entirely missing (task requires it)
        SqlCommand lowCmd = new SqlCommand("SELECT TOP 1 * FROM Employee ORDER BY Salary ASC", conn);
        SqlDataReader lowReader = lowCmd.ExecuteReader();
        Console.WriteLine("Lowest Salary Employee:");
        while (lowReader.Read())
        {
            Console.WriteLine($"Eid: {lowReader["Eid"]}, Name: {lowReader["Name"]}, Department: {lowReader["Department"]}, Salary: {lowReader["Salary"]}");
        }
        lowReader.Close();

        conn.Close(); // FIX 8: connection was never closed
    }
}