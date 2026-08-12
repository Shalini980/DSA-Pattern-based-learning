#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1;
        int mini=prices[0];
        int maxs=0;
        while(i<prices.size())
        {
            mini=min(mini,prices[i]);
            maxs=max(maxs,prices[i]-mini);
            i++;
        }
        return maxs;
        
    }
   
 
};
