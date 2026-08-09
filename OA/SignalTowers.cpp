#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> signalTowers(vector<int>& height) {
        int n = height.size();
        vector<int> result(n, 0);
        stack<int> st; // stores heights, maintained decreasing top-to-bottom won't matter, just track values
       
        for(int i=n-1;i>=0;i--)
        {
              while (!st.empty() && st.top() < height[i]) {
                result[i]++;
                st.pop();
            }
            if(!st.empty())
            {
                result[i]++;
            }
            st.push(height[i]);
        }

        return result;
    }
};