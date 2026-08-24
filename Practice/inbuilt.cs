class Program
{
    static void Main()
    {
        

        Func<int,int,int> add = (x,y) => x + y;


        Console.WriteLine(add(5,1));

        Action<string> display = ( name) => Console.WriteLine(name);

        Predicate<int> check = (x) => x>100;

        display("Santosh");

        Console.WriteLine(check(10));
    }
}