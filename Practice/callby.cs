



using System;



class Program
{
    

    static void byref(ref int x)
    {
        x = 15;
    }

    static void byVal(int x)
    {
        x = 15;
    }

    static void Main()
    {
        int x = 10,y = 20;


        byref(ref x);
        byVal(y);


        Console.WriteLine($"{x}\n{y}");
    }
}