class Program
{
 static void showType<T>(T data)
{
    // Call .GetType() on the instance variable
    Console.WriteLine(data.GetType()); 
}



    static void Main()
    {
        showType<int>(5);
        showType<string>("5");
    }
}