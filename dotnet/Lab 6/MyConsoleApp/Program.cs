// See https://aka.ms/new-console-template for more information



using System;
using System.Linq;
using Microsoft.Data.SqlClient;


class Todo
{
    private SqlConnection conn;
    private int id;
    private string title;

    Todo(SqlConnection conn)
    {
        this.conn = conn;
    }

    public void addNewTodo(string title)
    {
        try
        {   
        string sql = $"INSERT INTO todo(title) VALUES (${title})";   
        SqlCommand cmd = new SqlCommand(sql,this.conn) ;

        cmd.ExecuteNonQuery();
        Console.WriteLine("New Todo Added Successfully");
        }catch(SqlException e)
        {
            Console.WriteLine(e.Message);
        }

        
    }

}


class Program
{
    public static void Main()
    {
        string connectionString = "Server=localhost,1433;Database=labDb;User Id=santosh;Password=Password1!;TrustServerCertificate=True;";

        try
        {
            
        SqlConnection conn = new SqlConnection(connectionString);

        Console.WriteLine("Conncted Successfully");
        }catch(Exception e)
        {
            Console.WriteLine(e);
        }
    }
}