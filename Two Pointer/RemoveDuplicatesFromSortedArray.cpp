#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]!=arr[i])
            {
                temp.push_back(arr[i]);
            }

        }
        return temp;
    }
};