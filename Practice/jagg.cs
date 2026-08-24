class Program
{
    static void Main()
    {
        int[][] jagged = new int[3][];

        jagged[0] = new int[3]{1,2,3};
        jagged[1] = new int[4]{5,6,7,8};
        jagged[2] = new int[2]{9,10};


        foreach(var nums in jagged)
        {
            foreach(var num in nums)
            {
                Console.Write(num + "\t");
            }
            Console.WriteLine();
        }
    }
}