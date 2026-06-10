using System;

class Base
{
    public virtual void ShowClassName() => Console.WriteLine("Base Class");
}

class Calculate : Base
{
    // Overloading
    public int Add(int a, int b) => a + b;
    public int Add(int a, int b, int c) => a + b + c;

    // Overriding
    public override void ShowClassName() => Console.WriteLine("Calculate Class");
}

class Program
{
    static void Main()
    {
        Calculate obj = new Calculate();
        Base a = new Base();
        
        // Overloading
        Console.WriteLine(obj.Add(2, 3));
        Console.WriteLine(obj.Add(2, 3, 4));

        // Overriding
        a.ShowClassName();

        a = obj
        a.ShowClassName();
        
    }
}