#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:

    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n)
    {
        tree.resize(4*n);
        lazy.resize(4*n,0);
    }

    void build(int node,int start,int end,vector<int>&arr)
    {
        if(start==end)
        {
            tree[node]=arr[start];
            return;
        }

        int mid=(start+end)/2;

        build(2*node,start,mid,arr);
        build(2*node+1,mid+1,end,arr);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    void update(int node,int start,int end,int l,int r,int val)
    {
        // First resolve any pending lazy update
        if(lazy[node]!=0)
        {
            tree[node]+=(end-start+1)*lazy[node];

            if(start!=end)
            {
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }

            lazy[node]=0;
        }

        // No overlap
        if(start>r || end<l)
            return;

        // Complete overlap
        if(start>=l && end<=r)
        {
            tree[node]+=(end-start+1)*val;

            if(start!=end)
            {
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }

            return;
        }

        // Partial overlap
        int mid=(start+end)/2;

        update(2*node,start,mid,l,r,val);
        update(2*node+1,mid+1,end,l,r,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    int query(int node,int start,int end,int l,int r)
    {
        // Resolve pending update
        if(lazy[node]!=0)
        {
            tree[node]+=(end-start+1)*lazy[node];

            if(start!=end)
            {
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }

            lazy[node]=0;
        }

        // No overlap
        if(start>r || end<l)
            return 0;

        // Complete overlap
        if(start>=l && end<=r)
            return tree[node];

        // Partial overlap
        int mid=(start+end)/2;

        int left=query(2*node,start,mid,l,r);
        int right=query(2*node+1,mid+1,end,l,r);

        return left+right;
    }
};

int main()
{
    vector<int> arr={0,1,2,3,4,5,6,7}; // 1-based indexing

    int n=7;

    SegmentTree st(n);

    st.build(1,1,n,arr);

    cout<<"Sum from 3 to 5 = ";
    cout<<st.query(1,1,n,3,5)<<endl;

    st.update(1,1,n,3,7,20);

    cout<<"Sum from 3 to 7 = ";
    cout<<st.query(1,1,n,3,7)<<endl;

    return 0;
}