using System.Numerics;

class Vehicle
{

    
    public virtual void Drive(string name = "BMW")
    {
        Console.WriteLine($"{name} is driving");
    }
}

class Car : Vehicle
{
    public override void Drive(string name = "BMW")
    {
        Console.WriteLine("Car is driving");
        base.Drive(name);
    }
}

class Program
{
    static void Main()
    {
        Vehicle v = new Vehicle();
        v.Drive();
        v.Drive("Ferrari");

        v = new Car();
        v.Drive("RR");
    }
}