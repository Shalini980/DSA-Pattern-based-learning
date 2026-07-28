#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int n, int sum) {

        if (n == 0)
            return (sum==0);

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] <= sum) {
            return dp[n][sum] =
                solve(nums, n - 1, sum - nums[n - 1]) +
                solve(nums, n - 1, sum);
        }

        return dp[n][sum] = solve(nums, n - 1, sum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2)
            return 0;

        int req = (total + target) / 2;

        dp.assign(nums.size() + 1, vector<int>(req + 1, -1));

        return solve(nums, nums.size(), req);
    }
};