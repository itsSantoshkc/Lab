using System;
using System.Collections;

class Program
{
    static void Main()
    {
        ArrayList marks = new ArrayList();
        marks.Add(5);
        marks.Add("Hello");

        foreach(var item in marks)
        {
            Console.WriteLine(item);
        }


        List<int> m = new List<int>();

        m.Add(100);
        m.Add(500);
        m.Remove(100);

        foreach(var item in m)
        {
            Console.WriteLine(item);
        }

        Stack<int> st = new Stack<int>();
        st.Push(5);
        st.Push(15);
        st.Push(25);
        st.Push(35);
        st.Push(45);

        while (st.Count > 0)
        {
            
        Console.WriteLine(st.Peek());
        st.Pop();
        }

        Dictionary<string,int> dt = new Dictionary<string, int>();

        dt.Add("k1",2);
        dt.Add("k2",21);
        dt.Add("k3",22);
        dt.Add("k4",23);

        foreach(var item in dt)
        {
            Console.WriteLine($"{item.Key} : {item.Value}");
        }

        

    }
}
