
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int ans = -1;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size() < k){
                j++;
            }else if(mp.size() == k){
                ans = max(ans, j-i+1);
                j++;
            }else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};