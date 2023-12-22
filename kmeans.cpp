#include<iostream>
#include<math.h>
using namespace std;
struct point{
	float x;
	float y;
};
float distance(float x1,float x2,float y1,float y2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main()
{
	int m,k,set=0;
	cout<<"Enter the number of points : ";
	cin>>m;
	struct point P[m];
	for(int i=0;i<m;i++)
	{
		cout<<"Enter x-coordiate : ";
		cin>>P[i].x;
		cout<<"Enter y-coordiate : ";
		cin>>P[i].y;
	}
	cout<<"Enter the no.of clusters:";
	cin>>k;
	struct point rp[k];
	for(int i=0;i<k;i++)
	{
		cout<<"Enter random x from the input:";
		cin>>rp[i].x;
		cout<<"Enter random y from the input:";
		cin>>rp[i].y;
	}
	do{
	struct point arr[k][m];
	struct point mp;
	int count[k];
	for(int i=0;i<k;i++)
	count[i]=0;
	for(int i=0;i<m;i++)
	{
		float d[k];
		float min=-1;
		int c=0;
		for(int j=0;j<k;j++)
		{
			d[j]=distance(P[i].x,rp[j].x,P[i].y,rp[j].y);
			if(min>d[j]||min==-1)
			{
			mp=rp[j];
			min=d[j];
			c=j;
			}
		}
		arr[c][count[c]]=P[i];
		count[c]++;
	/*	for(int i=0;i<k;i++)
		{
			for(int j=0;j<count[i];j++)
			cout<<arr[i][j].x<<" "<<arr[i][j].y<<"\t";
			cout<<endl;
		}*/
	}
	struct point res[k];
	for(int i=0;i<k;i++)
	{
		float sumx=0.0,sumy=0.0;
		for(int j=0;j<count[i];j++)	
		{
			sumx+=arr[i][j].x;
			sumy+=arr[i][j].y;
		}
		res[i].x=sumx/count[i];
		res[i].y=sumy/count[i];
	    cout<<res[i].x<<endl;
		cout<<res[i].y<<endl;
	}
	int flag=0;
	for(int i=0;i<k;i++)
	{
		for(int p=0;p<k;p++)
		{
		if(rp[i].x==res[p].x&&rp[i].y==res[p].y)
		flag++;
    	}
	}
	if(flag==k)
	{
	cout<<"Successssssss....\n";
	for(int i=0;i<k;i++)
	{
	cout<<"Cluster no. : "<<i+1<<endl;
	for(int j=0;j<count[i];j++)
	cout<<"("<<arr[i][j].x<<","<<arr[i][j].y<<") ";
	cout<<endl;
	}
	set=0;
	}
	else
	{
		cout<<"Sorry...next trial...\n";
		set=1;
		for(int i=0;i<k;i++)
		{
		rp[i].x=res[i].x;
		rp[i].y=res[i].y;
		}
	}
	}while(set==1);
	return 0;
}
