#include<bits/stdc++.h>
#define nl cout<<endl;
#define First_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll Mx=100005;
bool node[Mx*3];

void segmentree(ll p,ll b,ll e,ll l,ll r)
{
	if(l==b and r==e)
	{
		node[p]=!node[p];
		return;
	}
	ll mid = (b+e)/2;
	if(r<=mid)
	{
		segmentree(2*p,b,mid,l,r);
	}
	else if(l>mid)
	{
		segmentree(2*p+1,mid+1,e,l,r);
	}
	else
	{
		segmentree(2*p,b,mid,l,mid);
		segmentree(2*p+1,mid+1,e,mid+1,r);
	}
}

ll query(ll p,ll b,ll e,ll pos)
{
	if(pos==b and pos==e)
	{
		return node[p];
	}
	if(node[p])
	{
		node[2*p]=!node[2*p];
		node[2*p+1]=!node[2*p+1];
		node[p]=0;
	}
	
	ll mid=(b+e)/2;
	
	if(pos<=mid)
	{
		query(2*p,b,mid,pos);
	}
	else
	{
		query(2*p+1,mid+1,e,pos);
	}
	
}

void solve(ll Case)
{
	string s;cin>>s;
	ll q;cin>>q;
	ll len = s.size();
	memset(node,0,sizeof(node));
	cout<<"Case "<<Case<<":"<<endl;
	for(ll i=0;i<len;i++)
	{
		if(s[i]=='1')
		{
			segmentree(1,1,len,i+1,i+1);
		}
	}
	while(q--)
	{
		char ch;
		cin>>ch;
		if(ch=='I')
	    {
		  ll x,y;
		  cin>>x>>y;
		  segmentree(1,1,len,x,y);
	    }
	    else
	    {
		  ll pos;
		  cin>>pos;
		  cout<<query(1,1,len,pos)<<endl;
	    }
	}
	
}
int main()
{
	First_IO; ll t,Case=0;
	cin>>t;
	while(t--)
	{
		solve(++Case);
	}
	return 0;
}
// Alhamdulillah