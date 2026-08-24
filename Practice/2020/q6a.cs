using System;
/* 6.a) What is LINQ? Write a program to select employees whose salary is greater than 20000 and whose address is kathmandu using LINq */


public class Employee{
  public string name;
  public long salary;

  public Employee(long salary,string name){
    this.name = name;
    this.salary = salary;
  }

}

class Program{


  public static void Main(string[] args){
    Employee[] emps = new Employee[4];
    emps[0] = 
      new Employee(50000,"Ram");
    emps[1] = 
      new Employee(20000,"Shyam");
emps[2] = 
      new Employee(15000,"Hari");
emps[3] = 
      new Employee(70000,"Sita");
    var filteredEmp = emps.Where(emp => emp.salary > 20000);

    foreach(Employee emp in filteredEmp){
      Console.WriteLine(emp.name);
    }




  }


}

