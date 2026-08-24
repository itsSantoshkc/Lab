using System;

public delegate void TemperatureDelegate(int temperature);


class Sensor
{
    public int threshold{get;set;}

    public event  TemperatureDelegate temperatureEvent;

    public void setTemp(int temp)
    {
        Console.WriteLine($"Current Temperature {temp}");

        if(temp > threshold)
        {
            temperatureEvent?.Invoke(temp);
        }
    }
    
}

class Program
{

    static void Alert(int temp)
    {
        Console.WriteLine($"{temp} too High");
    }
    static void Main()
    {
        Sensor s = new Sensor();
        s.threshold = 30;
        s.temperatureEvent += Alert;
        int currTemp;
        Console.WriteLine("Enter the Temperature");
        currTemp = Convert.ToInt32(Console.ReadLine());

        s.setTemp(currTemp);
        
    }
}