using System;

class ComplexNumber
{
    private int real, imaginary;

    public ComplexNumber(int r, int i)
    {
        real = r;
        imaginary = i;
    }

    // Operator Overloading
    public static ComplexNumber operator +(ComplexNumber c1, ComplexNumber c2)
    {
        return new ComplexNumber(c1.real + c2.real, c1.imaginary + c2.imaginary);
    }

    public void Display() => Console.WriteLine($"{real} + {imaginary}i");
}

class Program
{
    static void Main()
    {
        ComplexNumber c1 = new ComplexNumber(1, 2);
        ComplexNumber c2 = new ComplexNumber(3, 4);

        ComplexNumber c3 = c1 + c2;

        c1.Display();
        c2.Display();
        c3.Display();
    }
}