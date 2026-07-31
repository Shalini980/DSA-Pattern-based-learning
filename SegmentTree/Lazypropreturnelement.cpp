/*Given an array of n integers, your task is to process q queries of the following types:

increase each value in range [a,b] by u
what is the value at position k?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 a b u" or "2 k".
Output
Print the result of each query of type 2.
Constraints

1 \le n,q \le 2 \cdot 10^5
1 \le x_i, u \le 10^9
1 \le k \le n
1 \le a \le b \le n

Example
Input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Output:
5
6*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<long long>seg;
    vector<long long>lazy;
    Solution(int n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void build(vector<int>&nums,int low,int high,int i)
    {
        if(low>high)return;
        if(low==high)
        {
            seg[i]=nums[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(nums,low,mid,2*i+1);
        build(nums,mid+1,high,2*i+2);
    }
    void update(int low,int high,int l,int r,int i,int val)
    {
        if(low>high)return;
        if(lazy[i]!=0)
        {
            seg[i]+=lazy[i];
            if(low!=high)
            {
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;
        }
        if(l>high||r<low)return ;
        if(low>=l && high<=r)
        {
            seg[i]+=val;
            if(low!=high)
            {
                lazy[2*i+1]+=val;
                lazy[2*i+2]+=val;
            }
            return;
        }
        int mid=low+(high-low)/2;
        update(low,mid,l,r,2*i+1,val);
        update(mid+1,high,l,r,2*i+2,val);
        
    }
    long long query(int low,int high,int ind,int x)
    {
         if(lazy[ind]!=0)
    {
        seg[ind]+=lazy[ind];

        if(low!=high)
        {
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }

        lazy[ind]=0;
    }
        if(low==high)
        {
            return seg[ind];
        }
        int mid=low+(high-low)/2;
        if(x <= mid)
         return query(low,mid,2*ind+1,x);
        else
         return query(mid+1,high,2*ind+2,x);
    }
};
int main()
{
    int n;
    int q;
    cin>>n;
    cin>>q;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    Solution s(n);
    s.build(nums,0,n-1,0);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int a,b,val;
            cin>>a>>b>>val;
            s.update(0,n-1,a-1,b-1,0,val);
        }
        else
        {
            int x;
            cin>>x;
            long long y=s.query(0,n-1,0,x-1);
            cout<<y<<endl;
        }
    }
    return 0;
}