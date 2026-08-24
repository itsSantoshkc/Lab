using System;

using System.Numerics;

class Calculate
{

    
    public void sum(int x,int y)
    {
        Console.WriteLine(x + y);
    }

    public void sum(int x,int y,int z)
    {
        Console.WriteLine(x + y + z);
    }

    public void sum(int x,int y,int z,int a)
    {
        Console.WriteLine(x + y + z + a);
    }
}



class Program
{
    static void Main()
    {
        Calculate c  = new Calculate();
        c.sum(5,10);
        c.sum(5,10,15);
        c.sum(5,10,15,20);

    }
}
