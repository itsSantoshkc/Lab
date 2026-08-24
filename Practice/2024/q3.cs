using System;

namespace EnumerationDemo
{
    // Enumeration for Department
    enum Department
    {
        ComputerScience = 1,
        InformationTechnology,
        Electronics,
        MechanicalEngineering,
        CivilEngineering,
        Biotechnology
    }

    // Enumeration for College
    enum College
    {
        TribuvanUniversity = 1,
        KathmanduUniversity,
        PokharaUniversity,
        PurbanchalUniversity,
        MidWesternUniversity
    }

    class Program
    {
        // Function to display Department enumeration values
        static void DisplayDepartments()
        {
            Console.WriteLine("=============================");
            Console.WriteLine("       DEPARTMENTS LIST      ");
            Console.WriteLine("=============================");
            Console.WriteLine($"{"Code",-6} {"Department Name",-25}");
            Console.WriteLine("-----------------------------");

            foreach (Department dept in Enum.GetValues(typeof(Department)))
            {
                Console.WriteLine($"{(int)dept,-6} {dept,-25}");
            }

            Console.WriteLine("=============================\n");
        }

        // Function to display College enumeration values
        static void DisplayColleges()
        {
            Console.WriteLine("=============================");
            Console.WriteLine("        COLLEGES LIST        ");
            Console.WriteLine("=============================");
            Console.WriteLine($"{"Code",-6} {"College Name",-30}");
            Console.WriteLine("-----------------------------");

            foreach (College col in Enum.GetValues(typeof(College)))
            {
                Console.WriteLine($"{(int)col,-6} {col,-30}");
            }

            Console.WriteLine("=============================\n");
        }

        static void Main(string[] args)
        {
            Console.WriteLine("\n===== Enumeration Demo in C# =====\n");

            // Call function to display departments
            DisplayDepartments();

            // Call function to display colleges
            DisplayColleges();

            // ── Accessing individual enum values ──────────────────────
            Console.WriteLine("===== Accessing Individual Values =====\n");

            Department myDept = Department.ComputerScience;
            College    myCol  = College.TribuvanUniversity;

            Console.WriteLine($"Selected Department : {myDept} (Code: {(int)myDept})");
            Console.WriteLine($"Selected College    : {myCol}  (Code: {(int)myCol})");

            // ── Enum to int and int to Enum conversion ────────────────
            Console.WriteLine("\n===== Enum Conversion =====\n");

            int deptCode = (int)Department.Electronics;
            Console.WriteLine($"Department.Electronics as int  : {deptCode}");

            Department deptFromInt = (Department)3;
            Console.WriteLine($"int 3 as Department            : {deptFromInt}");

            // ── Check if a value exists in enum ───────────────────────
            Console.WriteLine("\n===== Enum.IsDefined Check =====\n");

            Console.WriteLine($"Is 2 a valid Department code?  : {Enum.IsDefined(typeof(Department), 2)}");
            Console.WriteLine($"Is 9 a valid College code?     : {Enum.IsDefined(typeof(College), 9)}");

            // ── Parse enum from string ────────────────────────────────
            Console.WriteLine("\n===== Parse Enum from String =====\n");

            Department parsedDept = (Department)Enum.Parse(typeof(Department), "Biotechnology");
            Console.WriteLine($"Parsed Department              : {parsedDept} (Code: {(int)parsedDept})");

            Console.WriteLine("\n===== End of Program =====");
            Console.ReadKey();
        }
    }
}