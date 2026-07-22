#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class STree
{
    public:
    vector<int>seg;
    STree(int n)
    {
        seg.resize(4*n+1);
    }
void build(vector<int>&arr,int low,int high,int index)
{
    if(low==high)
    {
        seg[index] = arr[low];
        return ;
    }
    int mid=low+(high-low)/2;
   build(arr,low,mid,2*index+1);
   build(arr,mid+1,high,2*index+2);
   seg[index]=min(seg[2*index+1],seg[2*index+2]);
   
}
int query(int low,int high,int index,int l,int r)
{
    if(high<l ||r<low )return INT_MAX;
    if(low>=l && high<=r)return seg[index];
    int mid=low+(high-low)/2;
    int left=query(low,mid,2*index+1,l,r);
    int right=query(mid+1,high,2*index+2,l,r);
    return min(left,right);

}
void update(int index,vector<int>arr,int low,int high,int val)
{
    if(low==high)
    {
        seg[index]=val;
        return;
    }
    int mid=low+(high-low)/2;
    if(mid>=index)update(2*index+1,arr,low,mid+1,val);
    else update(2*index+2,arr,mid+1,high,val);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    STree s1(n);
    s1.build(arr,0,n-1,0);
    int n1;
    cin>>n1;
    vector<int> arr1(n);
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    STree s2(n1);
    s2.build(arr1,0,n1-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)//find minimum in range from both array
        {
            int l,r;
            cin>>l>>r;
            int l1, r1;
            cin>>l1>>r1;
            int x=s1.query(0,n,0,l,r);
            int y=s2.query(0,n1,0,l1,r1);
            cout<<"minimum of both array"<<min(x,y)<<endl;

        }
        else
        {
            int arrno,val,i;
            cin>>arrno>>val>>i;
            if(arrno==1)
            {
                s1.update(i,arr,0,0,val);
            }
            else
            {
                s2.update(i,arr1,0,0,val);
            }
        }
    }
    return 0;

}