# Dynamic Programming (DP) — Complete Pattern Guide

A structured reference for understanding, identifying, and solving Dynamic Programming problems in C++, from brute-force recursion to top-down (memoization) to bottom-up (tabulation).

---

## Table of Contents
1. [What is DP](#what-is-dp)
2. [How to Identify a DP Problem](#how-to-identify-a-dp-problem)
3. [The 3-Step DP Approach](#the-3-step-dp-approach)
4. [Recursion → Memoization → Tabulation (Worked Example)](#recursion--memoization--tabulation-worked-example)
5. [DP Patterns](#dp-patterns)
   - [1. Linear / 1D DP](#1-linear--1d-dp)
   - [2. 0/1 Knapsack](#2-01-knapsack)
   - [3. Unbounded Knapsack](#3-unbounded-knapsack)
   - [4. Longest Common Subsequence (LCS) Family](#4-longest-common-subsequence-lcs-family)
   - [5. Longest Increasing Subsequence (LIS) Family](#5-longest-increasing-subsequence-lis-family)
   - [6. Matrix Chain Multiplication (Partition DP)](#6-matrix-chain-multiplication-partition-dp)
   - [7. DP on Grids](#7-dp-on-grids)
   - [8. DP on Subsets / Bitmask DP](#8-dp-on-subsets--bitmask-dp)
   - [9. DP on Strings (Palindrome type)](#9-dp-on-strings-palindrome-type)
   - [10. DP on Trees](#10-dp-on-trees)
6. [Space Optimization](#space-optimization)
7. [Practice Roadmap](#practice-roadmap)

---

## What is DP

Dynamic Programming is an optimization technique used when a problem can be broken into **overlapping subproblems** that have an **optimal substructure** — meaning the optimal solution to the problem can be built from optimal solutions of its subproblems.

Two properties must hold for DP to apply:

- **Overlapping Subproblems** — the same subproblem is solved multiple times in a naive recursive solution (e.g. `fib(5)` calls `fib(3)` twice).
- **Optimal Substructure** — the optimal answer to the problem can be constructed from optimal answers to its subproblems.

If a problem has overlapping subproblems but *no* optimal substructure, DP won't help — you need something else (e.g. plain recursion, greedy, or graph algorithms).

---

## How to Identify a DP Problem

Ask these questions when you read a problem statement:

| Signal | Example phrasing |
|---|---|
| Asked for **count of ways** | "In how many ways can you..." |
| Asked for **min/max** of something | "Minimum cost to...", "Maximum profit if..." |
| Asked for **yes/no feasibility** with choices | "Can you partition the array such that..." |
| Involves **making a decision at each step** (take/skip, include/exclude) | subsequence, subset, coin, item problems |
| Involves **two sequences/strings being compared or merged** | LCS, edit distance, string matching |
| Naive recursion **re-solves the same state** repeatedly | draw the recursion tree — do branches repeat? |

**Practical test:** Write the brute-force recursive solution first. If you can define the recursive call using a small number of **changing parameters** (the "state"), and the same state gets recomputed across different call paths, it's DP.

---

## The 3-Step DP Approach

1. **Define the state** — what parameters uniquely describe a subproblem? (e.g. `index`, `remaining capacity`, `i`, `j`)
2. **Write the recurrence** — express `dp[state]` in terms of smaller/previous states (this is just the recursive relation).
3. **Choose the implementation**:
   - **Recursion** (brute force) — correct but exponential, recomputes states.
   - **Memoization (Top-Down)** — same recursion + a cache (`dp` array/map) to store already-computed states.
   - **Tabulation (Bottom-Up)** — iteratively fill the `dp` table starting from base cases, no recursion/stack overhead.
   - **Space Optimization** — reduce dimensions of the `dp` table if only the last row/few states are needed.

---

## Recursion → Memoization → Tabulation (Worked Example)

Problem: **Fibonacci** — `fib(n) = fib(n-1) + fib(n-2)`

### Step 1 — Pure Recursion (exponential, O(2^n))
```cpp
int fib(int n) {
    if (n <= 1) return n;               // base case
    return fib(n - 1) + fib(n - 2);     // recurrence
}
```

### Step 2 — Top-Down (Memoization) — O(n) time, O(n) space
```cpp
int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];      // already computed
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int solve(int n) {
    vector<int> dp(n + 1, -1);
    return fib(n, dp);
}
```

### Step 3 — Bottom-Up (Tabulation) — O(n) time, O(n) space
```cpp
int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```

### Step 4 — Space Optimized — O(n) time, O(1) space
```cpp
int fib(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

**Rule of thumb:** always derive recursion first → add memoization → convert to tabulation → optimize space. Don't jump straight to tabulation; the recurrence is far easier to spot from the recursive version.

---

## DP Patterns

### 1. Linear / 1D DP
**Recognize:** state depends only on `index` (and maybe a small extra flag). Examples: Climbing Stairs, House Robber, Fibonacci, Decode Ways.

**State:** `dp[i]` = answer considering first `i` elements.

```cpp
// House Robber: dp[i] = max money robbing houses[0..i], no two adjacent
int rob(vector<int>& houses) {
    int n = houses.size();
    if (n == 0) return 0;
    vector<int> dp(n);
    dp[0] = houses[0];
    for (int i = 1; i < n; i++) {
        int take = houses[i] + (i >= 2 ? dp[i - 2] : 0);
        int skip = dp[i - 1];
        dp[i] = max(take, skip);
    }
    return dp[n - 1];
}
```

---

### 2. 0/1 Knapsack
**Recognize:** each item can be used **at most once**; you choose include/exclude under a capacity constraint. Examples: Subset Sum, Equal Partition, Target Sum, 0/1 Knapsack.

**State:** `dp[i][w]` = best value using first `i` items with capacity `w`.

```cpp
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];                    // exclude item i
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w],
                                val[i - 1] + dp[i - 1][w - wt[i - 1]]); // include
        }
    }
    return dp[n][W];
}
```
**Space optimized (1D, iterate w in reverse):**
```cpp
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    return dp[W];
}
```

---

### 3. Unbounded Knapsack
**Recognize:** items can be reused **infinite times**. Examples: Coin Change (min coins / count ways), Rod Cutting.

```cpp
// Coin Change - minimum coins to make amount
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++)
        for (int c : coins)
            if (c <= a)
                dp[a] = min(dp[a], 1 + dp[a - c]);
    return dp[amount] >= INT_MAX - 1 ? -1 : dp[amount];
}
```
Key difference from 0/1 knapsack: the inner loop over weight/amount does **not** go in reverse, because reuse of the same item is allowed.

---

### 4. Longest Common Subsequence (LCS) Family
**Recognize:** two strings/sequences compared, matching/skipping characters. Examples: LCS, Edit Distance, Longest Common Substring, Shortest Common Supersequence.

**State:** `dp[i][j]` = answer considering `s1[0..i-1]` and `s2[0..j-1]`.

```cpp
int lcs(string& s1, string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```

```cpp
// Edit Distance: min operations (insert/delete/replace) to convert s1 -> s2
int editDistance(string& s1, string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1],   // replace
                                     dp[i - 1][j],        // delete
                                     dp[i][j - 1]});       // insert
        }
    }
    return dp[n][m];
}
```

---

### 5. Longest Increasing Subsequence (LIS) Family
**Recognize:** find a subsequence satisfying an order condition (increasing/decreasing). Examples: LIS, Longest Bitonic Subsequence, Russian Doll Envelopes.

**State:** `dp[i]` = length of LIS ending at index `i`.

```cpp
// O(n^2) DP
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

```cpp
// O(n log n) using patience sorting / binary search
int lisOptimized(vector<int>& arr) {
    vector<int> tails; // tails[i] = smallest tail of an increasing subsequence of length i+1
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
```

---

### 6. Matrix Chain Multiplication (Partition DP)
**Recognize:** you must choose where to "split" or "partition" a sequence to minimize/maximize cost. Examples: MCM, Burst Balloons, Palindrome Partitioning, Boolean Parenthesization.

**State:** `dp[i][j]` = best cost to solve the problem over range `[i, j]`, trying every split point `k`.

```cpp
// Matrix Chain Multiplication: min scalar multiplications
int mcm(vector<int>& p) { // p = dimensions, matrix i has dims p[i-1] x p[i]
    int n = p.size() - 1; // number of matrices
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}
```
General template for this pattern:
```
dp[i][j] = best over all k in [i, j) of ( dp[i][k] + dp[k+1][j] + cost(i, k, j) )
```
Always solved by increasing `len` (range length), since larger ranges depend on smaller ones — recursion + memoization is often the cleaner way to write it before converting to this iterative range form.

---

### 7. DP on Grids
**Recognize:** movement across a 2D grid (usually right/down), computing min cost / max sum / counting paths. Examples: Unique Paths, Minimum Path Sum, Cherry Pickup.

**State:** `dp[i][j]` = answer to reach cell `(i, j)`.

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    return dp[n - 1][m - 1];
}
```

---

### 8. DP on Subsets / Bitmask DP
**Recognize:** small `n` (usually ≤ 20), and the problem needs to consider "which subset of elements has been used/visited". Examples: Travelling Salesman Problem, Assignment Problem, "count ways to assign tasks".

**State:** `dp[mask][i]` = best answer having visited the set of elements in `mask`, currently at `i`.

```cpp
// TSP - minimum cost to visit all cities starting from city 0
int tsp(vector<vector<int>>& cost, int n) {
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1][0] = 0; // only city 0 visited, currently at city 0
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue; // already visited
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }
    int ans = INT_MAX;
    for (int u = 1; u < n; u++)
        if (dp[(1 << n) - 1][u] != INT_MAX)
            ans = min(ans, dp[(1 << n) - 1][u] + cost[u][0]);
    return ans;
}
```

---

### 9. DP on Strings (Palindrome type)
**Recognize:** questions about palindromic substrings/subsequences, or building/checking one string from parts. Examples: Longest Palindromic Subsequence, Longest Palindromic Substring, Palindrome Partitioning II.

**State:** `dp[i][j]` = true/count/length of relevant property over substring `s[i..j]`.

```cpp
// Longest Palindromic Subsequence
int lps(string& s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
```
Tip: LCS(s, reverse(s)) also gives the Longest Palindromic Subsequence — a good pattern-bridging trick between Pattern 4 and Pattern 9.

---

### 10. DP on Trees
**Recognize:** the problem is defined on a tree and needs a value computed per subtree, often with two states — "including this node" vs "excluding this node". Examples: House Robber III, Diameter of Tree, Max Independent Set on Tree.

**State:** `dp[node] = {includeNode, excludeNode}`, computed via post-order (children before parent).

```cpp
struct Node { int val; vector<Node*> children; };

pair<int,int> solve(Node* node) { // {include, exclude}
    int include = node->val, exclude = 0;
    for (auto* child : node->children) {
        auto [inc, exc] = solve(child);
        include += exc;                 // if we take node, children must be excluded
        exclude += max(inc, exc);       // if we skip node, children can be either
    }
    return {include, exclude};
}

int houseRobberTree(Node* root) {
    auto [inc, exc] = solve(root);
    return max(inc, exc);
}
```

---

## Space Optimization

Once the tabulation solution works, check: does `dp[i]` only depend on `dp[i-1]` (or `dp[i-1]` and `dp[i-2]`)? If so, you don't need the full table — keep only the last 1–2 rows.

```cpp
// 2D -> 1D rolling array example (Knapsack-style)
vector<int> prev(W + 1, 0), curr(W + 1, 0);
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
        curr[w] = prev[w];
        if (wt[i - 1] <= w)
            curr[w] = max(curr[w], val[i - 1] + prev[w - wt[i - 1]]);
    }
    prev = curr;
}
```

This turns `O(n*W)` space into `O(W)` space — commonly asked as a follow-up in interviews.

---

## Practice Roadmap

A suggested order to build pattern recognition from scratch:

1. **1D DP:** Climbing Stairs → House Robber → Decode Ways
2. **0/1 Knapsack:** Subset Sum → Partition Equal Subset Sum → Target Sum
3. **Unbounded Knapsack:** Coin Change → Coin Change II → Rod Cutting
4. **LCS family:** LCS → Edit Distance → Longest Common Substring
5. **LIS family:** LIS (O(n²)) → LIS (O(n log n)) → Russian Doll Envelopes
6. **Grid DP:** Unique Paths → Minimum Path Sum → Cherry Pickup
7. **Partition DP:** MCM → Palindrome Partitioning II → Burst Balloons
8. **String DP:** Longest Palindromic Subsequence → Longest Palindromic Substring
9. **Bitmask DP:** TSP → Assignment Problem
10. **Tree DP:** House Robber III → Diameter of Binary Tree

**Golden rule for every problem:** identify state → write recursion → memoize → tabulate → optimize space. Don't skip straight to tabulation until the recurrence is second nature.
