using System;
using System.Linq;


class Program{

  public static void Main(String[] args){
    string[] names = {"Bill","Steve","James","Harry"};

    var filteredName = names.Where(name => name.Contains('a'));

    foreach(var name in filteredName){
      Console.WriteLine(name);
    }
  }
}
