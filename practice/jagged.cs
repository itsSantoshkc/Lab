using System;


class Program
{
    public static void Main()
    {
        int[][] std_marks = new int[3][];
        std_marks[0] = new int[] {91,90,90};
        std_marks[1] = new int[] {90,90,90,90};
        std_marks[2] = new int[] {93,90,90};

        for(int i = 0; i < std_marks.Length; i++)
        {
            for(int j = 0;j< std_marks[i].Length; j++)
            {
                Console.WriteLine(std_marks[i][j]);
            }
        }

    }
}