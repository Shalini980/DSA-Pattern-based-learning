#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    int solveRec(int W, vector<int> &val, vector<int> &wt, int n) {
        // Base case: no items left or no capacity left
        if (n == 0 || W == 0) return 0;

        // If current item's weight exceeds capacity, must skip it
        if (wt[n-1] > W) {
            return solveRec(W, val, wt, n-1);
        }

        // Choice: include or exclude current item
        int include = val[n-1] + solveRec(W - wt[n-1], val, wt, n-1);
        int exclude = solveRec(W, val, wt, n-1);

        return max(include, exclude);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        return solveRec(W, val, wt, n);
    }
};