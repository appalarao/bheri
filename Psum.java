import java.io.*;
import java.util.*;
class Sum
{
	void fun(){}
}
class Psum extends Sum
{
void fun()
{
int a[]=new int[5];
a[0]=6;
a[1]=0;
a[2]=-10;
a[3]=0;
a[4]=11;
int i;
int c_s=1,m_s=1;
for(i=0;i<5;i++)
{
c_s*=a[i];
if(c_s>m_s)
	m_s=c_s;
}
System.out.println("result is "+m_s);
}
public static void main(String a[]) throws Exception
{
	Sum s=new Psum();
	s.fun();
}
}
