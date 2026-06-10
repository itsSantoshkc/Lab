using System;
using System.Collections;
using System.Collections.Generic;

class Student
{
    public string Name;
    public int Age;

    public Student(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public void Display() => Console.WriteLine($"Name: {Name}, Age: {Age}");
}

class Program
{
    static void Main()
    {
        // ArrayList
        ArrayList students = new ArrayList()
        {
            new Student("Ram", 20),
            new Student("Sita", 19),
            new Student("Hari", 21)
        };

        // Hashtable
        Hashtable studentHash = new Hashtable();
        studentHash["S1"] = new Student("John", 20);
        studentHash["S2"] = new Student("Mary", 21);

        // Dictionary
        Dictionary<int, Student> studentsDict = new Dictionary<int, Student>();
        studentsDict[1] = new Student("Neymar", 21);
        studentsDict[2] = new Student("Messi", 20);

        // ArrayList display
        Console.WriteLine("ArrayList:");
        foreach (Student s in students)
            s.Display();

        // Hashtable display
        Console.WriteLine("\nHashtable:");
        foreach (DictionaryEntry s in studentHash)
        {
            Console.Write($"Key: {s.Key}, ");
            ((Student)s.Value).Display();
        }

        // Dictionary display
        Console.WriteLine("\nDictionary:");
        foreach (var s in studentsDict)
        {
            Console.Write($"Key: {s.Key}, ");
            s.Value.Display();
        }
    }
}