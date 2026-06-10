using System;

class Program
{
    static void Main()
    {
        try
        {
            Console.Write("Enter your balance: ");
            double balance = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter withdraw amount: ");
            double withdraw = Convert.ToDouble(Console.ReadLine());

            if (balance > withdraw)
            {
                double remaining = balance - withdraw;
                Console.WriteLine("Remaining Balance = " + remaining);
            }
            else
            {
                throw new ApplicationException("Insufficient balance! Withdrawal not possible.");
            }
        }
        catch (ApplicationException ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Invalid input! " + ex.Message);
        }
    }
}
