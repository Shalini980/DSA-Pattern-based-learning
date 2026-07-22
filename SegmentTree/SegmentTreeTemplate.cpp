#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class STree
{
public:
    vector<int> seg;

    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(vector<int> &arr, int low, int high, int index)
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(arr, low, mid, 2 * index + 1);
        build(arr, mid + 1, high, 2 * index + 2);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int low, int high, int index, int l, int r)
    {
        // No overlap
        if (high < l || low > r)
            return INT_MAX;

        // Complete overlap
        if (low >= l && high <= r)
            return seg[index];

        // Partial overlap
        int mid = low + (high - low) / 2;

        int left = query(low, mid, 2 * index + 1, l, r);
        int right = query(mid + 1, high, 2 * index + 2, l, r);

        return min(left, right);
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            seg[node] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (idx <= mid)
            update(2 * node + 1, low, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, high, idx, val);

        seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    STree s1(n);
    s1.build(arr, 0, n - 1, 0);

    int n1;
    cin >> n1;

    vector<int> arr1(n1);

    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    STree s2(n1);
    s2.build(arr1, 0, n1 - 1, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r, l1, r1;
            cin >> l >> r >> l1 >> r1;

            int x = s1.query(0, n - 1, 0, l, r);
            int y = s2.query(0, n1 - 1, 0, l1, r1);

            cout << min(x, y) << endl;
        }
        else
        {
            int arrno, val, idx;
            cin >> arrno >> val >> idx;

            if (arrno == 1)
            {
                arr[idx] = val;
                s1.update(0, 0, n - 1, idx, val);
            }
            else
            {
                arr1[idx] = val;
                s2.update(0, 0, n1 - 1, idx, val);
            }
        }
    }

    return 0;
}