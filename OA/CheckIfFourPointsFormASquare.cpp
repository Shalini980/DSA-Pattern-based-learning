#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int distance(vector<int>& a, vector<int>& b) {
      int dx = a[0] - b[0];
      int dy = a[1] - b[1];

      return dx * dx + dy * dy;
  }
    bool isSquare(vector<vector<int>>& points) {
        // code here
        vector<int> d;

        // Find all 6 pairwise distances
        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                d.push_back(distance(points[i], points[j]));
            }
        }

        sort(d.begin(), d.end());

        // 4 equal sides + 2 equal diagonals
        return d[0] > 0 &&
               d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&
               d[4] == d[5] &&
               d[4] == 2 * d[0];
        
    }
};