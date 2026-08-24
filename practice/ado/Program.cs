using System;
using System.Data;
using Microsoft.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connectionString =
            "Server=localhost,1433;Database=LabDb;User Id=Santosh;Password=Password1!;TrustServerCertificate=True;";

        string title;

        Console.WriteLine("Enter Todo Title");
        title = Console.ReadLine();



        using var conn = new SqlConnection(connectionString);
        conn.Open();

        string query = $"INSERT INTO todo(Title) VALUES('{title}')";
        SqlCommand cmd = new SqlCommand(query,conn);

        cmd.ExecuteNonQuery();


        SqlCommand cmd1 = new SqlCommand("SELECT * FROM todo",conn);
        SqlDataReader reader = cmd1.ExecuteReader();

        while (reader.Read())
        {
            Console.WriteLine($"{reader["Id"]} {reader["title"]}");
        }
        // using var da = new SqlDataAdapter("SELECT * FROM todo", conn); // ← dispose adapter too

        // var ds = new DataSet();
        // da.Fill(ds, "todos");

        // var table = ds.Tables["todos"]!; // ← grab reference once

        // // Print header
        
        // foreach (DataRow row in table.Rows)
        // {
        //     foreach (DataColumn col in table.Columns)
        //         Console.Write($"{row[col],-20}");
        //     Console.WriteLine();
        // }
    }
}