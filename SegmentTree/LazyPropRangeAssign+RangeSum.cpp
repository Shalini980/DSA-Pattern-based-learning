#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<long long> seg;
    vector<long long> lazy;
    vector<bool> mark;

    Solution(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
        mark.resize(4*n+1,false);
    }

    void build(vector<int>&nums,int low,int high,int ind)
    {
        if(low==high)
        {
            seg[ind]=nums[low];
            return;
        }

        int mid=(low+high)/2;

        build(nums,low,mid,2*ind+1);
        build(nums,mid+1,high,2*ind+2);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void update(int low,int high,int l,int r,int ind,long long val)
    {
        // Resolve pending assignment
        if(mark[ind])
        {
            seg[ind]=(high-low+1)*lazy[ind];

            if(low!=high)
            {
                mark[2*ind+1]=true;
                mark[2*ind+2]=true;

                lazy[2*ind+1]=lazy[ind];
                lazy[2*ind+2]=lazy[ind];
            }

            mark[ind]=false;
        }

        // No overlap
        if(high<l || low>r)
            return;

        // Complete overlap
        if(low>=l && high<=r)
        {
            seg[ind]=(high-low+1)*val;

            if(low!=high)
            {
                mark[2*ind+1]=true;
                mark[2*ind+2]=true;

                lazy[2*ind+1]=val;
                lazy[2*ind+2]=val;
            }

            return;
        }

        int mid=(low+high)/2;

        update(low,mid,l,r,2*ind+1,val);
        update(mid+1,high,l,r,2*ind+2,val);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    long long query(int low,int high,int l,int r,int ind)
    {
        // Resolve pending assignment
        if(mark[ind])
        {
            seg[ind]=(high-low+1)*lazy[ind];

            if(low!=high)
            {
                mark[2*ind+1]=true;
                mark[2*ind+2]=true;

                lazy[2*ind+1]=lazy[ind];
                lazy[2*ind+2]=lazy[ind];
            }

            mark[ind]=false;
        }

        // No overlap
        if(high<l || low>r)
            return 0;

        // Complete overlap
        if(low>=l && high<=r)
            return seg[ind];

        int mid=(low+high)/2;

        return query(low,mid,l,r,2*ind+1)
             + query(mid+1,high,l,r,2*ind+2);
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    Solution s(n);

    s.build(nums,0,n-1,0);

    int q;
    cin>>q;

    while(q--)
    {
        int t;
        cin>>t;

        if(t==1)
        {
            int l,r;
            long long val;
            cin>>l>>r>>val;

            s.update(0,n-1,l,r,0,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            cout<<s.query(0,n-1,l,r,0)<<endl;
        }
    }

    return 0;
}