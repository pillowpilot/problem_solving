#include<bits/stdc++.h>
using namespace std;
long long int hi[1600005],lo[1600005],mini[1600005],delta[1600005];

void init(long long int i,long long int a,long long int b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return; 
	long long int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}
void prop(long long int i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}
void update(long long int i)
{
	mini[i]= min(mini[2*i]+delta[2*i],mini[2*i+1]+delta[2*i+1]);
}
void increment(long long int i,long long int a,long long int b,long long int val)
{
	if(b<lo[i] || a>hi[i])
		return;
	if(a<=lo[i] && b>=hi[i])
	{	
		delta[i]+=val;
		return;
	}
	
	prop(i);
	increment(2*i,a,b,val);
	increment(2*i+1,a,b,val);
	update(i);
}
long long int minimum(long long int i,long long int a,long long int b)
{
	if(b<lo[i] || a>hi[i])
		return 1000000000000000000;
	if(a<=lo[i] && b>=hi[i])
	{	
		return mini[i]+delta[i];
	}
	prop(i);
	long long int miniL=minimum(2*i,a,b);
	long long int miniR=minimum(2*i+1,a,b);
	update(i);
	return min(miniL,miniR);
}
int main()
{
	memset(mini,0,sizeof(mini));
	long long int n;
	cin>>n;
	long long int a[400005];
	long long int i;
	init(1,0,n-1);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		increment(1,i,i,a[i]);
	} 
	//cout<<minimum(1,2,2)<<'\n';
	long long int m;
	cin>>m;
	char s[105];
	long long int j,l,r,flag;
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld",&l,&r);
		gets(s);
		flag=0;
		if(l>r)
			flag=1;
		if(strlen(s)==0)
		{
			if(flag==0)
				cout<<minimum(1,l,r)<<'\n';
			else
			{
				long long int mini1=minimum(1,l,n-1);
				long long int mini2=minimum(1,0,r);
				cout<<min(mini1,mini2)<<'\n';
			}
		}
		else
		{
			if(flag==0)
				increment(1,l,r,atoi(s));
			else
			{
				increment(1,0,r,atoi(s));
				increment(1,l,n-1,atoi(s));
			}
		}
	}
	return 0;
}
