class Vehicle
{
    public virtual void Drive()
    {
        Console.WriteLine("Brr");
    }
}

class Car : Vehicle
{
    public override void Drive()
    {
        Console.WriteLine("Skrrr");
    }
}


class Program
{
    static void Main()
    {
        Vehicle v1 = new Vehicle();
        v1.Drive();

        Vehicle v2 = new Car();
        v2.Drive();
    }
}