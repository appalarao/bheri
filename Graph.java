import java.io.*;
import java.util.*;

class Graph
{
	class Node
	{
		Node ptr;
		int data;
		int wight;
		Node(int data,int wight)
		{
			this.data=data;
			this.ptr=null;		
			this.wight=wight;
		}
	}
	final static int WHITE=0;
	final static int GRAY=1;
	final static int BLACK=2;
	Node arr[];
	int color[];

	Graph(int n)
	{
		arr=new Node[n+1];
		color=new int[n+1];
		for(int i=1;i<=n;i++)
		{
			arr[i]=null;
			color[i]=WHITE;;
		}
	}

	void add(int data,int i,int w)
	{
		arr[i]=insert(arr[i],data,w);
	}

	Node insert(Node root, int data,int wight)
	{
		Node temp=new Node(data,wight);
		temp.ptr=null;
		if(root==null)
		{
			root=temp;
		}
		else
		{
			Node walk=root;
			while(walk.ptr!=null)
				walk=walk.ptr;
			walk.ptr=temp;
		}
		return root;
			
	}

	void show_graph(int n)
	{
		int i;
		Node walk;
		for(i=1;i<=n;i++)
		{
			walk=arr[i];
			System.out.print(i+"--> ");
			while(walk!=null)
			{
		    		System.out.print(walk.data+"\t"+walk.wight);
		    		walk=walk.ptr;
			}
	                System.out.println();
		}
	}

	void BFS(int source)
	{
		Queue<Integer> q=new LinkedList<>();
		q.add(source);
		Node temp;
		int val1,val2;
		while(!q.isEmpty())
		{
			val1=q.remove();
			temp=arr[val1];
			while(temp!=null)
			{
				val2=temp.data;
				if(color[val2]==WHITE)
				{
					q.add(val2);
					color[val2]=GRAY;
				}
				temp=temp.ptr;
			}
			color[val1]=BLACK;
			System.out.println("data is "+val1);	
		}
	}
	void DFS(int source,int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			if(color[i]==WHITE)
				DFS_visit(i);
		}
	}
	void DFS_visit(int i)
	{
		color[i]=GRAY;
		Node temp;
		int val;
		temp=arr[i];
		while(temp!=null)
		{
			val=temp.data;
			if(color[val]==WHITE)
			{
				DFS_visit(val);
			}
			temp=temp.ptr;
		}
		System.out.println(i+"\t");
		color[i]=BLACK;
	}
	int doesContainsCycle()
	{
		int flag=0;
		return flag;
	}

	public static void main(String args[])throws Exception
	{
		Scanner sc=new Scanner(System.in);
		int n,i,j,adjacent,data,wt;
		System.out.println("Enter number of vertices in the graph ");
		n=sc.nextInt();
		Graph g=new Graph(n);
		for(i=1;i<=n;i++)
		{
			System.out.println("how many adjacent nodes for node "+i+"\t");
			adjacent=sc.nextInt();
			for(j=1;j<=adjacent;j++)
			{
				System.out.println("enter node "+j+"\t");
				data=sc.nextInt();
				System.out.println("enter wt of edge "+i+"  to  "+data+"\t");
				wt=sc.nextInt();
				g.add(i,data,wt);      
			}
		}
		g.show_graph(n); 
//		g.BFS(1);
//		g.DFS(1,n);
	}
}
