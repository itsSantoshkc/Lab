using System;

class Box
{
    public int length, width, height;
    private int vol, area;

    // Constructor
    public Box(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;

        vol = l * w * h;

        // Surface area of a box
        area = 2 * (l * w + w * h + l * h);
    }

    // Constructor used for creating Box from an area
    public Box(int area)
    {
        this.area = area;
    }

    // Calculate volume
    public int volume()
    {
        return vol;
    }

    // Calculate surface area
    public int surfaceArea()
    {
        return area;
    }

    // Overload < operator
    public static bool operator <(Box b1, Box b2)
    {
        return b1.volume() < b2.volume();
    }

    // Overload > operator
    public static bool operator >(Box b1, Box b2)
    {
        return b1.volume() > b2.volume();
    }

    // Overload == operator
    public static bool operator ==(Box b1, Box b2)
    {
        return b1.length == b2.length &&
               b1.width == b2.width &&
               b1.height == b2.height;
    }

    // Overload != operator
    public static bool operator !=(Box b1, Box b2)
    {
        return !(b1 == b2);
    }

    // Overload & operator
    public static Box operator &(Box b1, Box b2)
    {
        return new Box(b1.area & b2.area);
    }
}

class Program
{
    static void Main()
    {
        Box b1 = new Box(5, 10, 15);
        Box b2 = new Box(50, 10, 5);

        Console.WriteLine("b1 > b2: " + (b1 > b2));
        Console.WriteLine("b1 < b2: " + (b1 < b2));
        Console.WriteLine("b1 == b2: " + (b1 == b2));
        Console.WriteLine("b1 != b2: " + (b1 != b2));

        Box b3 = b1 & b2;

        Console.WriteLine("Area after &: " + b3.surfaceArea());
    }
}