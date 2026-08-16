#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int maxarea=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            area=min(height[i],height[j])*(j-i);
            maxarea=max(area,maxarea);
            if(height[i]<height[j])i++;
            else j--;
        }
        return maxarea;
    }
};