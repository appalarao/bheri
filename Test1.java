import java.io.*;
import java.lang.*;
import java.util.*;
 interface X{
//  A(){System.out.println("bike is created");}    
public void run1();
  // void changeGear(){System.out.println("gear changed");}
 }

 class Y implements X
{
 public void run1(){System.out.println("running safely..");}
 }
 class Test1
{
 public static void main(String args[])throws Exception
{
  X obj = new Y();
  obj.run1();
 // obj.changeGear();
/*
public class SimpleMonitor {
    private final Lock lock = new ReentrantLock();

    public void testA() {
        lock.lock();

        try {
            //Some code
        } finally {
            lock.unlock();
        }
    }

    public int testB() {
        lock.lock();

        try {
            return 1;
        } finally {
            lock.unlock();
        }
    }
}
*/
 }
}

