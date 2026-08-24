// Write a C# program to demonstrate binary and relational operator overloading.

using System;
    
class Number{
    public int value {get;set;}
    public Number(int x)
        {
            this.value = x;
        }
    
    public static Number operator +(Number n1,Number n2)
        {

            return new Number(n1.value + n2.value);
        }
}

class Program
    {
        public static void Main()
        {
            Number n1 = new Number(10);
            Number n2 = new Number(20);

            Number n3 = n1 + n2;

            Console.WriteLine(n3.value);
        }
    }