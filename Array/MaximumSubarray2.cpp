#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int sum=0;
        int start=0;
        int ansend=-1;
        int anstart=-1;
        int maxs=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=0){
            sum+=arr[i];
            if(sum>maxs)
            {
                maxs=sum;
                anstart=start;
                ansend=i;
                
            }
          else if (sum == maxs) {
              int currentLength = i - start + 1;
              int answerLength = ansend - anstart + 1;

              if (currentLength > answerLength) {
                  anstart = start;
                  ansend = i;
              }
          }
            }
            
            else 
            {sum=0;
            start=i+1;
            }
        }
        if (anstart == -1)
        return {-1};
        vector<int>ans(ansend-anstart+1,0);
        for(int i=anstart;i<=ansend;i++)
        {
            ans[i-anstart]=arr[i];
        }
        return ans;
    }
};