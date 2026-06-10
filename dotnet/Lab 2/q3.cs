using System;

class Student
{
    public string Name;
    public int Age;

    static Student()
    {
        Console.WriteLine("Static Constructor called.");
    }

    // 2. Default Constructor
    public Student()
    {
        Name = "Default";
        Age = 0;
        Console.WriteLine("Default Constructor called. Name=" + Name);
    }

    // 3. Parameterized Constructor
    public Student(string name, int age)
    {
        Name = name;
        Age = age;
        Console.WriteLine("Parameterized Constructor called. Name=" + Name);
    }

    // 4. Copy Constructor
    public Student(Student s)
    {
        Name = s.Name;
        Age = s.Age;
        Console.WriteLine("Copy Constructor called. Name=" + Name);
    }

    // 5. Private Constructor
    private Student(string name)
    {
        Name = name;
        Console.WriteLine("Private Constructor called. Name=" + Name);
    }

    public static Student Create(string name)
    {
        return new Student(name);
    }

}

class Program
{
    static void Main()
    {
        Student s1 = new Student();                  
        Student s2 = new Student("Santosh", 20);       
        Student s3 = new Student(s2);                
        Student s4 = Student.Create("Ram");          

    }
}