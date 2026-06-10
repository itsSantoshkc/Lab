class Calculate
{
    public int sum(int x,int y)
    {
        return x + y;
    }

    public int sum(int x,int y,int z)
    {
        return this.sum(x,y) + z;
    }
}


class Program
{
    public static void Main()
    {
        Calculate calculate = new Calculate();
        int a = 5,b=6,c=7;
        Console.WriteLine($"Sum of {a} and {b} = {calculate.sum(a,b)}");
        Console.WriteLine($"Sum of {a},{b} and {c} = {calculate.sum(a,b,c)}");

    }
}