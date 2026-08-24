// Write a C# program that reads a list of numbers from the user (comma-separated). Convert the inputs into integers and calculate their sum. Use exception handling to catch FormatException for invalid numbers and OverflowException for numbers too large. Display meaningful messages for each exception. [1+4]


class Program
{
    static void Main()
    {
        string numbers = "1,123,13,13123,1,31,31,3,123,13,171847199878979879776687684712984";


        try
        {
            
        var nums = numbers.Split(",");
        

          foreach (var num in nums)
            {
                int numb = int.Parse(num);
            }
        foreach(var num in nums)
        {
            Console.WriteLine(num);
        }
        }catch(OverflowException e)
        {
            Console.WriteLine("Error ! " + e.Message);
        }
    }
}




