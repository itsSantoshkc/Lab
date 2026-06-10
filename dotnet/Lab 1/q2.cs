using System;

class Q2
{
    

  

    static void Main()
    {
       int sum = 0;

        Console.WriteLine("First 10 Natural Numbers:");

        for (int i = 1; i <= 10; i++)
        {
            Console.Write(i + " ");
            sum += i;
        }

        Console.WriteLine("\nSum = " + sum);            // call method
    }
}