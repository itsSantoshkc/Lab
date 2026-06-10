using System;
using System.Linq;


class Program
{
    public static void Main()
    {
        string[] names = {"Ram","Shyam","Hari","Bikash","Mahesh"};

        var sortedNames = names.OrderBy(name => name);

        Console.WriteLine("Sorted Names : ");
        foreach(var name in sortedNames)
        {
            Console.WriteLine(name);
        }
    }
}