class Program
{
    public delegate void MyDelegate(string msg);
    static void Method1(string msg)
        { 
            Console.WriteLine("Method1: " + msg); 
            }
    static void Method2(string msg){ 
        Console.WriteLine("Method2: " + msg); 
        }
    static void Main(){ 
        MyDelegate del = Method1;
        del += Method2;
        del("Hello, Multicast Delegate!"); }
}