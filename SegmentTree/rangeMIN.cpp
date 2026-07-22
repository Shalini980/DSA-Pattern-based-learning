#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int build(vector<int>&arr,int low,int high,int index,vector<int>&seg)
{
    if(low==high)
    {
        seg[index] = arr[low];
        return arr[low];
    }
    int mid=low+(high-low)/2;
    int left=build(arr,low,mid,2*index+1,seg);
    int right=build(arr,mid+1,high,2*index+2,seg);
    seg[index]=min(left,right);
    return min(left,right);
}
int query(int low,int high,int index,vector<int>&seg,int l,int r)
{
    if(high<l ||r<low )return INT_MAX;
    if(low>=l && high<=r)return seg[index];
    int mid=low+(high-low)/2;
    int left=query(low,mid,2*index+1,seg,l,r);
    int right=query(mid+1,high,2*index+2,seg,l,r);
    return min(left,right);

}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int>seg(4*n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    build(arr,0,n-1,0,seg);
    while(q--)
    {
        int l,r;
        cin>>l;
        cin>>r;
        cout << query(0, n-1, 0, seg, l, r) << endl;
    }
    return 0;

}