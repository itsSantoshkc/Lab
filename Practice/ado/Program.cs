// 10.Which namespace is used for accessing data? 
// Explain method of each key components of ADO.NET. 
// Assume a database name CompanyDB containing 
// Employee table(Eid, Name, Department, Salary).
// Write a c# program to connect to the database and 
// insert 5 employee records and 
// display the employee record from 
// CompanyDB database having highest and lowest salary. [1+4+5]



using Microsoft.Data.SqlClient;

class Employee
{
    public int eid;
    public string name;
    public string department;
    public decimal salary;

    public Employee(int eid,string name,string department,decimal salary)
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

     
     string connectionString = "Server = localhost,1433;Database=LabDb;User Id = Santosh;Password=Password1!;TrustServerCertificate=True;";
     SqlConnection conn = new SqlConnection(connectionString);
     conn.open();

        Employee[] employees =
        {
            new Employee(1, "John", "IT", 50000.00),
            new Employee(2, "Alice", "HR", 45000.00),
            new Employee(3, "Bob", "Finance", 55000.00)
        };

        foreach(var emp in employees)
        {
            string query = $"INSERT INTO Employee (Eid, Name, Department, Salary) VALUES({emp.eid}, {emp.name}, {emp.department}, {emp.salary});";
            SqlCommand cmd = new SqlCommand(query,conn);
            cmd.ExecuteNonQuery();
        }
        

        SqlCommand cmd = new SqlCommand("SELECT TOP 1 FROM Employee ORDER BY Salary DESC",conn);

        SqlDataReader reader = cmd.ExecuteReader();

        while (reader.Read())
        {
            Console.WriteLine(reader["Name"]);
        }



     

     
    }
}