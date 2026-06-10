using System;

class Q1
{


    static void Main()
    {
         Console.Write("Enter first number: ");
        int @int = Convert.ToInt32(Console.ReadLine());

        Console.Write("Enter second number: ");
        int num2 = Convert.ToInt32(Console.Read());

        int sum = @int + num2;

        Console.WriteLine("Sum = " + sum);          // call method
    }
}
