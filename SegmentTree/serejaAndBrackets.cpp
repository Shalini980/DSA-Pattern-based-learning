#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int full;
    int open;
    int close;
    Node(int _full,int _open,int _close )
    {
        full=_full;
        open=_open;
        close=_close;
    }
};
void build(int index,int low,int high,vector<Node>&seg,string &s)
{
    if(low==high)
    {
        seg[index]=Node(s[low]=='(',s[low]==')',0);
        return;
    }
    int mid=low+(high-low)/2;
    build(2*index+1,0,mid,seg,s);
    build(2*index+1,mid+1,high,seg,s);
    merge();
}
int main()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<Node>seg(4*s.length());
    build(0,0,s.length()-1,seg,s);
    while(q--)
    {
        int l,r;
        l--;
        r--;

    }
}