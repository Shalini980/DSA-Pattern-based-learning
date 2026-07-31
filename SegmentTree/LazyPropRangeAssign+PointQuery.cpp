#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<long long> seg;
    vector<long long> lazy;

    Solution(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1, LLONG_MIN);
    }

    void build(vector<int>&a,int low,int high,int ind)
    {
        if(low==high)
        {
            seg[ind]=a[low];
            return;
        }

        int mid=(low+high)/2;

        build(a,low,mid,2*ind+1);
        build(a,mid+1,high,2*ind+2);
    }

    void push(int low,int high,int ind)
    {
        if(lazy[ind]==LLONG_MIN)
            return;

        seg[ind]=lazy[ind];

        if(low!=high)
        {
            lazy[2*ind+1]=lazy[ind];
            lazy[2*ind+2]=lazy[ind];
        }

        lazy[ind]=LLONG_MIN;
    }

    void update(int low,int high,int l,int r,int ind,long long val)
    {
        push(low,high,ind);

        if(high<l || low>r)
            return;

        if(low>=l && high<=r)
        {
            lazy[ind]=val;
            push(low,high,ind);
            return;
        }

        int mid=(low+high)/2;

        update(low,mid,l,r,2*ind+1,val);
        update(mid+1,high,l,r,2*ind+2,val);
    }

    long long query(int low,int high,int ind,int pos)
    {
        push(low,high,ind);

        if(low==high)
            return seg[ind];

        int mid=(low+high)/2;

        if(pos<=mid)
            return query(low,mid,2*ind+1,pos);

        return query(mid+1,high,2*ind+2,pos);
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int>a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];

    Solution s(n);

    s.build(a,0,n-1,0);

    int q;
    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r,val;
            cin>>l>>r>>val;

            s.update(0,n-1,l,r,0,val);
        }
        else
        {
            int pos;
            cin>>pos;

            cout<<s.query(0,n-1,0,pos)<<endl;
        }
    }
}