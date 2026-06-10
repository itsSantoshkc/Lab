using System;
class Lab
{
  
   
enum Days {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday}
    static void Main()
    {
     
        Console.WriteLine("Dot Net Technology Class Routine:\n");

        foreach (Days day in Enum.GetValues<Days>())
        {
            switch (day)
            {
                case Days.Sunday:
                    Console.WriteLine(day + ": 7:00 AM - 9:00 AM");
                    break;
                case Days.Wednesday:
                    Console.WriteLine(day + ": 7:00AM - 8:00 AM");
                    break;
                case Days.Thursday:
                    Console.WriteLine(day + ": 7:00AM - 8:00 AM");
                    break;
                case Days.Friday:
                    Console.WriteLine(day + ": 7:00AM - 8:00 AM");
                    break;
                case Days.Saturday:
                    break;
                default:
                    Console.WriteLine(day + ": No Class");
                    break;
            }
        }           // call method
    }
}
