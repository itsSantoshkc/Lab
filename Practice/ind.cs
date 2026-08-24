using System;



class Buff{
  string[] data = new string[30];




  public string this[int index]{
    get  {
      return data[index];
    }
    set  {
      data[index] = value;
    }

  }

}

class Program{
  public static void Main(){
    Buff bd = new Buff();
    bd[0] = "Hell";
    bd[1] = "Wassup";

    Console.Write(bd[0]);
    Console.Write(bd[1]);
  
  }
}
