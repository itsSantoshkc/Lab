class BCA
{
    string[] subject = new string[5];
    

    public string this[int index]
    {
        get
        {
            return subject[index];
        }
        set
        {
            subject[index] = value;
        }
    }
}


class Program
{
    static void Main()
    {

        int[] num = {1,2,3,4,5};
        BCA bca= new BCA();
        bca[0] = "MIS";
        bca[1] = "Dot Net";
        bca[2] = "CG";
        bca[3] = "CN";
        bca[4] = "Management";

        
        Console.WriteLine(num.Length);
        for(int i = 0;i< 5; i++)
        {
            Console.WriteLine(bca[i]);
        }
    }
}