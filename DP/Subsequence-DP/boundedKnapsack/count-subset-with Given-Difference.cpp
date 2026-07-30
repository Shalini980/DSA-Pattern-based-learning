#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int n, int sum) {

        if (sum == 0)
            return 1;

        if (n == 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] <= sum) {
            return dp[n][sum] =
                solve(arr, n - 1, sum - arr[n - 1]) +
                solve(arr, n - 1, sum);
        }

        return dp[n][sum] = solve(arr, n - 1, sum);
    }

    int countSubsetDiff(vector<int>& arr, int diff) {

        int total = accumulate(arr.begin(), arr.end(), 0);

        if (diff > total)
            return 0;

        if ((total + diff) % 2)
            return 0;

        int req = (total + diff) / 2;

        dp.assign(arr.size() + 1, vector<int>(req + 1, -1));

        return solve(arr, arr.size(), req);
    }
};