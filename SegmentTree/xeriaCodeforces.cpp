#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void build(vector<int>&arr,int low,int high,int index,vector<int>&seg,int orr)
{
    if(low==high)
    {
        seg[index] = arr[low];
        return ;
    }
    int mid=low+(high-low)/2;
    build(arr,low,mid,2*index+1,seg,!orr);
    build(arr,mid+1,high,2*index+2,seg,!orr);
    if(orr)
    seg[index]=seg[2*index+1]|seg[2*index+2];
    else
    {
        seg[index]=seg[2*index+1]^seg[2*index+2];
    }
   
}

 void update(int node, int low, int high, int idx, int val,vector<int>&seg,int orr)
    {
        if (low == high)
        {
            seg[node] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (idx <= mid)
            update(2 * node + 1, low, mid, idx, val,seg,!orr);
        else
            update(2 * node + 2, mid + 1, high, idx, val,seg,!orr);

       if(orr)
    seg[node]=seg[2*node+1]|seg[2*node+2];
    else
    {
        seg[node]=seg[2*node+1]^seg[2*node+2];
    }
    }
int main()
{
    int n;
    cin>>n;
    int el=pow(2,n);
    vector<int> arr(el);
    vector<int>seg(4*n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    if(n%2==0)
    build(arr,0,n-1,0,seg,0);
    else
    build(arr,0,n-1,0,seg,1);
    while(q--)
    {
        int i,val;
        cin >>i;
        cin>>val;
        if(n%2==0)
        update(0, 0,n-1, i,val, seg,0);
        else
        update(0, 0,n-1, i,val, seg,1);
    }
    return 0;

}