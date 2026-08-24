// Operator Overloading
//
//
//
//
class Complex{
 public int real;
public   int imag;

  public Complex(int r,int i){
    this.real = r;
    this.imag = i;
  }
  

  public static Complex operator +(Complex c1,Complex c2){
    return new Complex(c1.real+c2.real,c1.imag + c2.imag);
  }

  public static Boolean operator >(Complex c1,Complex c2){
    if(c1.real > c2.real){
      return true;
    }
    return false;
  }

  public static Boolean operator <(Complex c1,Complex c2){
    if(c1.real < c2.real){
      return true;
    }
    return false;
  }
}


class Program{

  public static void Main(){
    Complex c1 = new Complex(10,6);
    Complex c2 = new Complex(6,7);

    Complex c3 = c1 + c2;

    Console.WriteLine(c1 > c2);

    Console.WriteLine($"{c3.real} + {c3.imag}i");
    
  }

}
