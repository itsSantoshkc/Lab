// Delegate Exampl
//
//

using System;


public delegate void myDelegate(string name);


class Program{
  static void displayName(string name){
    Console.WriteLine("Name : {0}",name);
  }

  public static void Main(string[] args){
    string name = "John";


    myDelegate d = new myDelegate(displayName);

    d(name);

  }

}


