#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        build(0,n-1,0,nums);
    }
    void build(int low,int high,int i,vector<int>&nums)
    {
        if(low==high)
        {
            seg[i]=nums[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(low,mid,2*i+1,nums);
        build(mid+1,high,2*i+2,nums);
        seg[i]=seg[2*i+1]+seg[2*i+2];
        return;
    }
    void updateTree(int low,int high,int i,int val,int x)
    {
        if(low==high)
        {
            seg[x]=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(mid>=i)
        {
            updateTree(low,mid,i,val,2*x+1);
        }
        else
        {
            updateTree(mid+1,high,i,val,2*x+2);
        }
        seg[x]=seg[2*x+1]+seg[2*x+2];
    }
    
    void update(int index, int val) {
        updateTree(0,n-1,index,val,0);
    }
    
    int sumTree(int low,int high,int l,int r,int index)
    {

        if (high < l || low > r)
            return 0;
        if (low >= l && high <= r)
            return seg[index];

        int mid = low + (high - low) / 2;

        int left = sumTree(low, mid, l, r,2 * index + 1);
        int right = sumTree(mid + 1, high,l,r, 2 * index + 2);

        return (left+ right);
    }
    int sumRange(int left, int right) {
        return sumTree(0,n-1,left,right,0);
    }
};