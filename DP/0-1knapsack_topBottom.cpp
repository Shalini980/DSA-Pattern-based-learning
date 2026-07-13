#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));

        // Base case is already handled: t[0][w] = 0 and t[i][0] = 0
        // since the vector is initialized to 0.

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i-1] > w) {
                    // can't include item i-1
                    t[i][w] = t[i-1][w];
                } else {
                    int include = val[i-1] + t[i-1][w - wt[i-1]];
                    int exclude = t[i-1][w];
                    t[i][w] = max(include, exclude);
                }
            }
        }

        return t[n][W];
    }
};