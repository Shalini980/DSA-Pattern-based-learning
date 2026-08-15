#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)mini=prices[i];
            maxprofit=max(maxprofit,prices[i]-mini);
            
        }
        return maxprofit;
    }
};
