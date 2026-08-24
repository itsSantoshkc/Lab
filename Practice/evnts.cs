


public delegate void myDelegate(string msg);

public class Subscriber
{
    public event myDelegate eventExample;

    public void check(int num)
    {
        if(num == 5)
        {
            eventExample?.Invoke("Wassup");
        }
    }

    
    
}

class Program
{
    static void display(string msg)
    {
        Console.WriteLine(msg);
    }

    static void Main()
    {
        Subscriber s = new Subscriber();
        s.eventExample += display;
        s.check(5);

    }
    
}