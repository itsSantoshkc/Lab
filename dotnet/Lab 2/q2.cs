using System;

class InternalMarks
{
    private int[] marks = new int[5];

    // Property to store student name
    
    public string? StudentName { get; set; }



    // Indexer to access marks like array
    public int this[int index]
    {
        get
        {
            return marks[index];
        }
        set
        {
            marks[index] = value;
        }
    }

    // Method to display all marks
    public void DisplayMarks()
    {
        Console.WriteLine("\n--- Internal Exam Marks ---");
        Console.WriteLine("Student Name: " + StudentName);

        for (int i = 0; i < marks.Length; i++)
        {
            Console.WriteLine("Subject " + (i + 1) + " Marks: " + marks[i]);
        }
    }
}

class Program
{
    static void Main()
    {
        InternalMarks student = new InternalMarks();

        Console.Write("Enter Student Name: ");
        student.StudentName = Console.ReadLine();

        Console.WriteLine("Enter marks of 5 subjects:");

        for (int i = 0; i < 5; i++)
        {
            Console.Write("Subject " + (i + 1) + ": ");
            student[i] = Convert.ToInt32(Console.ReadLine());   // using indexer
        }

        student.DisplayMarks();

        Console.ReadLine();
    }
}
