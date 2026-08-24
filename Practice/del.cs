using System;


public delegate void myDelegate(string name);



class Program
{
    static void display(string name)
    {
        Console.WriteLine(name);
    }
    static void Main()
    {
        myDelegate d = new myDelegate(display);

        d("santosh");
    }
}