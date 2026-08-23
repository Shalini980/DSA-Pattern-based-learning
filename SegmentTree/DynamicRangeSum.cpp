
/*
Given an array of n integers, your task is to process q queries of the following types:

update the value at position k to u
what is the sum of values in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".
*/
#include<bits/stdc++.h>
using namespace std;
void build(int i,int low,int high,vector<int>&seg,vector<int>&nums)
{
    if(low==high)
    {
        seg[i]=nums[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(2*i+1,low,mid,seg,nums);
    build(2*i+2,mid+1,high,seg,nums);
    seg[i]=seg[2*i+1]+seg[2*i+2];
    return;
}
void update(int val,int k,int low,int high,vector<int>&seg,int i)
{
    if(low==high)
    {
        seg[i]=val;
        return;
    }
    int mid=low+(high-low)/2;
    if(mid>k)update(val,k,low,mid,seg,2*i+1);
    else update(val,k,mid+1,high,seg,2*i+2);
    seg[i]=seg[2*i+1]+seg[2*i+2];
    return;
}
int find(int l,int r,vector<int>&seg,int i,int high,int low)
{
    if(l>high||r<low)return 0;
    if(l>=low && high<=r)return seg[i];
    int mid=low+(high-low)/2;
    int x=find(l,r,seg,2*i+1,mid,low);
    int y=find(l,r,seg,2*i+2,high,mid+1);
    return x+y;
}
int main()
{
    int n,q;
    cin>>n;
    cin>>q;
    vector<int>nums(n,0);
    vector<int>seg(4*n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    build(0,0,n-1,seg,nums);
    while(q--)
    {
        int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        if(a==1)
        {
             update(c,b,0,n-1,seg,0);
        }
        else
        {
            int x= find(b,c,seg,0,n-1,0);
            cout<<x<<" "<<endl;
        }
    }
    return 0;
}