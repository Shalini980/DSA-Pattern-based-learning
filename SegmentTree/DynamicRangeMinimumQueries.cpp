#include<bits/stdc++.h>
using namespace std;
void build(int low,int high,int i,vector<int>&nums,vector<int>&seg)
{
    if(low==high)
    {
        seg[i]=nums[low];
        return ;
    }
    int mid=low+(high-low)/2;
    build(low,mid,2*i+1,nums,seg);
    build(mid+1,high,2*i+2,nums,seg);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
    return ;
}
void update(int low,int high,int val,int k,int i,vector<int>&seg)
{
    if(low==high)
    {
        seg[i]=val;
        return;
    }
    int mid=low+(high-low)/2;
    if(mid>k)update(low,mid,val,k,2*i+1,seg);
    else update(mid+1,high,val,k,2*i+2,seg);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
    return;
}
int find(int left,int right,int low,int high,int i,vector<int>&seg)
{
    if(left>high||right<low)return INT_MAX;
    if(low>=left && high<=right)return seg[i];
    int mid=low+(high-low)/2;
    int l=find(left,right,low,mid,2*i+1,seg);
    int r=find(left,right,mid+1,high,2*i+2,seg);
    return min(l,r);
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    vector<int>seg(4*n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    build(0,n-1,0,nums,seg);
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            update(0,n-1,c,b,0,seg)
            
            ;
        }
        else 
        {
            int x=find(b,c,0,n-1,0,seg);
            cout<<x<<" "<<endl;
        }
    }
    return 0;
}