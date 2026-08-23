#include <bits/stdc++.h>
using namespace std;

void build(int low, int high, int i,
           vector<int>& hotels, vector<int>& seg)
{
    if(low == high)
    {
        seg[i] = hotels[low];
        return;
    }

    int mid = low + (high - low) / 2;

    build(low, mid, 2*i+1, hotels, seg);
    build(mid+1, high, 2*i+2, hotels, seg);

    seg[i] = max(seg[2*i+1], seg[2*i+2]);
}

// Find the FIRST hotel having capacity >= x
int findFirst(int low, int high, int i,
              int x, vector<int>& seg)
{
    // This entire segment cannot satisfy the customer
    if(seg[i] < x)
        return -1;

    // We reached one hotel
    if(low == high)
        return low;

    int mid = low + (high - low) / 2;

    // Check left side first because we need the FIRST hotel
    int left = findFirst(low, mid, 2*i+1, x, seg);

    if(left != -1)
        return left;

    // No valid hotel on left, so check right
    return findFirst(mid+1, high, 2*i+2, x, seg);
}

// Update hotel k
void update(int low, int high, int k, int val,
            int i, vector<int>& seg)
{
    if(low == high)
    {
        seg[i] = val;
        return;
    }

    int mid = low + (high - low) / 2;

    if(k <= mid)
        update(low, mid, k, val, 2*i+1, seg);
    else
        update(mid+1, high, k, val, 2*i+2, seg);

    seg[i] = max(seg[2*i+1], seg[2*i+2]);
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> hotels(n);
    vector<int> seg(4*n);

    for(int i = 0; i < n; i++)
        cin >> hotels[i];

    build(0, n-1, 0, hotels, seg);

    while(q--)
    {
        int x;
        cin >> x;

        int index = findFirst(0, n-1, 0, x, seg);

        if(index == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << index + 1 << " ";

            // Customer takes x rooms
            hotels[index] -= x;

            // Update segment tree
            update(0, n-1, index, hotels[index], 0, seg);
        }
    }

    return 0;
}