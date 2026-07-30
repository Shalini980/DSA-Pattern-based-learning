#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class Solution {
public:
    int solve(Node* root, bool &ans) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return root->data;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        if (root->data != left + right)
            ans = false;

        return root->data + left + right;
    }

    bool isSumTree(Node* root) {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};