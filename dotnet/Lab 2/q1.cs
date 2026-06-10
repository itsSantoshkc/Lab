using System;

class Program
{
    static void Main()
    {
        string s = "Hello";
        string t = s;

        Console.WriteLine("Before:\nstr1 : {0}\nstr2 : {1}", s, t);

        s.Replace("Hello", "World");
        Console.WriteLine("str1 after using Replace : {0}", s);

        t = "World";
        
        Console.WriteLine("\nAfter:\nstr1 : {0}\nstr2 : {1}", s, t);
    }
}
