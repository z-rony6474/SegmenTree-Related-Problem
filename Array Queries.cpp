#include<bits/stdc++.h>
#define nl cout<<endl;
#define First_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll Mx = 100005;
ll node[Mx*4];
ll ar[Mx*4];
void segmentree(ll v, ll b, ll e)
{
	if(b==e)
	{
		node[v] = ar[b];
		return;
	}
	ll mid = b+((e-b)/2);
	segmentree(2*v,b,mid);
	segmentree(2*v+1,mid+1,e);
	node[v]=min(node[2*v],node[2*v+1]);
}

ll query(ll v,ll b,ll e, ll l,ll r)
{
	 if(e<l or r<b)
        return INT_MAX;
        
     if(l<=b && e<=r)
     {
     	return node[v];
     }
    
	ll mid = b+((e-b)/2);
	ll q1=query(2*v,b,mid,l,r);
	ll q2=query(2*v+1,mid+1,e,l,r);
	return min(q1,q2);
}
void solve(ll Case)
{
	ll n,q;
	cin>>n>>q;
	memset(node,0,sizeof(node));
	memset(ar,0,sizeof(ar));
	cout<<"Case "<<Case<<":"<<endl;
	for(ll i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	segmentree(1,1,n);
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<query(1,1,n,x,y)<<endl;
	}
}
int main()
{
	First_IO; ll t,Case=0;
	cin>>t;
	while(t--) solve(++Case);
	return 0;
}
// Alhamdulillah