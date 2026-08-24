/*
The first line contains two integers n and m (1≤n,m≤100000), the size of the array and the number of operations.
The next line contains n numbers ai, the initial state of the array (0≤ai≤10⁹).

The following lines contain the description of the operations. The description of each operation is as follows:

1 i v: set the element with index i to v (0≤i<n, 0≤v≤10⁹).

2 l r: calculate the minimum and number of elements equal to minimum of elements with indices from l to r−1 (0≤l<r≤n).
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int minv;
    int count;
};
Node merge(Node left,Node right)
{
    if(left.minv<right.minv)return left;
    if(right.minv<left.minv)return right;
    else return {left.minv,left.count+right.count};
}
void build(int low,int high,vector<int>&nums,vector<Node>&seg,int i)
{
    if(low==high)
    {
        seg[i]={nums[low],1};
        return;
    }
    int mid=low+(high-low)/2;
    build(low,mid,nums,seg,2*i+1);
    build(mid+1,high,nums,seg,2*i+2);
    seg[i]=merge(seg[2*i+1],seg[2*i+2]);
}
void update(int low,int high,vector<Node>&seg,int i,int k,int val)
{
    if(low==high)
    {
        seg[i]={val,1};
        return;
    }
    int mid=low+(high-low)/2;
    if(mid>k)update(low,mid,seg,2*i+1,k,val);
    else update(mid+1,high,seg,2*i+2,k,val);
    seg[i]=merge(seg[2*i+1],seg[2*i+2]);
    return;
}
Node query(int low,int high,int l,int r,int i,vector<Node>&seg)
{
    if(l>high||r<low)return {INT_MAX,0};
    if(low>=l && high<=r)return seg[i];
    int mid=low+(high-low)/2;
    Node left=query(low,mid,l,r,2*i+1,seg);
    Node right=query(mid+1,high,l,r,2*i+2,seg);
    return merge(left,right);
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    vector<Node>seg(4*n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    build(0,n-1,nums,seg,0);
    while(q--)
    {
        int x,a,b;
        cin>>x;
        cin>>a>>b;
        if(x==1)
        {
            update(0,n-1,seg,0,a,b);
        }
        else
        {
            Node x=query(0,n-1,a,b-1,0,seg);
            cout<<x.minv<<" "<<x.count<<endl;
        }
    }
    return 0;
}