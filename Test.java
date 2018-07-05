import java.io.*;
import java.lang.*;
import java.util.*;
 abstract class A{  
  A(){System.out.println("bike is created");}  
   abstract void run();  
   void changeGear(){System.out.println("gear changed");}  
 }  
  
 class B extends A
{  
 void run(){System.out.println("running safely..");}  
 }  
 class Test
{  
 public static void main(String args[])throws Exception
{  
  A obj = new B();  
  obj.run();  
  obj.changeGear();  
 }  
}  
