#include<stdio.h>
using namespace std;
#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int A[100005];
int X, Y;

int solve(int l, int r) {
    if (l > r) return 0; // empty stretch, nothing to do

    // find minimum value and its position in [l, r]
    int m = INT_MAX, p = -1;
    for (int i = l; i <= r; i++) {
        if (A[i] < m) {
            m = A[i];
            p = i;
        }
    }

    // Option 1: shave whole range by m, then solve left and right leftovers
    long long option1 = (long long)m * X + solve(l, p - 1) + solve(p + 1, r);

    // Option 2: smash every element individually
    long long option2 = (long long)(r - l + 1) * Y;

    return min(option1, option2);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> X >> Y;

    cout << solve(0, N - 1) << endl;

    return 0;
}