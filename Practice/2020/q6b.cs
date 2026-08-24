// b) Write a C# program to show insert and select operation in database.


using System;
using Microsoft.Data.SqlClient;

class Program{
  

  public static void Main(string[] args){
    string connectionString = "Server = localhost,1433;Database=LabDb;User Id = Santosh;Password=Password1!;TrustServerCertificate=True;";

    SqlConnection conn = new SqlConnection(connectionString);

    conn.open();

    SqlCommand cmd = new SqlCommand("INSERT INTO Todo(Title) VALUES ('Hello')",conn);
    cmd.ExecuteNonQuery();


    Console.WriteLine("Todo inserted Successfully");

    SqlCommand cmd1 =  new SqlCommand("SELECT * FROM Todo",conn);
    SqlDataAdapter da = new SqlDataAdapter(cmd1);
    DataSet ds = new DataSet();

    da.Fill(ds,"Todo");

    foreach(DataRow row in ds.Table["Todo"].Rows){
      Console.WriteLine($"{row["Id"]}  {row["Title"]}");
  }
        


  }

}
