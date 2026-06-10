interface Car
{
        public void DriveCar();
}


interface Bike
{
        public void DriveBike();
}

public class Animal
{
    public void Eat()
    {
        Console.WriteLine("The animal is eating.");
    }
}

public class Mammal : Animal
{
    public void Walk()
    {
        Console.WriteLine("The mammal is walking.");
    }
}


class Vehicle : Car, Bike
{
    public void DriveBike()
    {
        Console.WriteLine("Driving a Bike");
    }

    public void DriveCar()
    {
        Console.WriteLine("Driving a Car");
    }
}


public class Dog : Mammal
{
    public void Bark()
    {
        Console.WriteLine("The dog is barking.");
    }
}





// Main Program
class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Multiple Inheritance \n ");
        Vehicle vehicle = new Vehicle();
        vehicle.DriveCar();
        vehicle.DriveBike();

        Console.WriteLine("\nMultilevel Inheritance\n");
        Dog myDog = new Dog();
        myDog.Eat();   // From Animal
        myDog.Walk();  // From Mammal
        myDog.Bark();  // From Dog
    }
}