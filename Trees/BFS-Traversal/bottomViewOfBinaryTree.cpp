#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> bottomView(Node *root) {
      if(root->left==NULL && root->right==NULL)return {root->data};
       queue<pair<int,Node*>>q;
       map<int,int>mp;
       q.push({0,root});
       while(!q.empty())
       {
           int s=q.size();
           for(int i=1;i<=s;i++)
           {
               auto it=q.front();
               q.pop();
               Node*temp=it.second;
               int x=it.first;
               mp[x]=temp->data;
               if(temp->left)q.push({x-1,temp->left});
               if(temp->right)q.push({x+1,temp->right});
           }
       }
       vector<int>ans;
       for(auto it:mp)
       {
           ans.push_back(it.second);
       }
       return ans;
        
    }
};