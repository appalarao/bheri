#include<iostream>
usin namespace std;

int main()
{
int arr[4][4]={2,-3,-4,1,-5,-6,-1,0,-3,12,16,-4,-4,11,17,-9};
int c1=0,c2=0,c3=0,c4=0;

int f_cur_sum=0,f_max_sum=0,i,j;
int cur_sum=0,max_sum=0,a_c3,a_c4;
int row,col,temp[4],k;
	
	for(i=0;i<4;i++)
	{	
		for(j=0;j<4;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}

for(row=0;row<4;row++)
{
//	memset(temp,0,4);
	for(k=0;k<4;k++)
		temp[k]=0;
	for(col=row;col<4;col++)
	{
		for(k=0;k<4;k++)
		{
			temp[k] +=arr[k][col];		
		}
		cout<<"\n array is----\n";
		for(k=0;k<4;k++)
		{
			cout<<temp[k]<<"\t";
		}
		cur_sum=0;
		max_sum=0;
		int aux_c3=0;
		a_c3=0,a_c4=0;
		for(k=0;k<4;k++)
		{
			//int aux_c3=0;
			cur_sum+=temp[k];
			if(cur_sum<=0)
			{
				aux_c3=k+1;
				cur_sum=0;
			}
			if(cur_sum>max_sum)
			{
				a_c3=aux_c3;
				a_c4=k;
			        max_sum=cur_sum;
			}
		}
		cout<<"\nsum is "<<max_sum<<"\n";
		cout<<"\n positions are "<<a_c3<<"\t"<<a_c4<<"\n";

		int min=temp[0];
		if(max_sum==0)
		{	
			for(k=1;k<4;k++)
				if(min<temp[k])
			        min=temp[k];                                                       
		}

		if(max_sum>f_max_sum)
		{
			f_max_sum=max_sum;
			c1=row;
			c2=col;
			c3=a_c3;
			c4=a_c4;
		}

	}
}

	cout<<"\n---------------------------res------------------\n";
	cout<<"c1="<<c1<<"\tc2= "<<c2<<"\tc3= "<<c3<<"\tc4= "<<c4<<"\n";	
	cout<<"\nval is "<<f_max_sum<<"\n";
	cout<<"\n----------------final matrix is-----------\n";
	for(i=c3;i<=c4;i++)	
	{
		for(j=c1;j<=c2;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}

return 0;
}

