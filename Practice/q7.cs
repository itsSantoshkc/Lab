// 7.Why Delegate is used in C#? Write a C# program to select odd and 
// divisible by 3 number from list of number (1-30) using LINQ query.


using System.Globalization;

class Program
{
    
    static void Main(String[] args)
    {
        List<int> nums = new List<int>{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30
    };


    var oddNums = nums.Where(num => num %3 == 0 && num %2 != 0);

    foreach(var num in oddNums)
        {
            Console.WriteLine(num);
        }



    }
}