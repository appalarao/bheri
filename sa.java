import java.lang.*;
import java.io.*;
class P
{
	P()
	{
		System.out.println("\npar con\n");
	}
	void fun()
	{
		System.out.println("\n---concrete fun---\n");
	}
}
class C extends P
{
	int a
	
	C(int a)
	{
		this.a=a;		
	}
	void fun()
	{
		super();
		System.out.println("\n----concrete fun in child---\n");
	}	
}

class Main1()
{
:wq
:wq
	public static void main(String args[])
	{
		C obj=new C(10);
		obj.fun();
	}
}
