// House Robber

//https://leetcode.com/problems/house-robber/description/

class Solution {
    int tabusolve(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        if(n==1) return dp[0];
         dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int inc=dp[i-2]+nums[i];
            int exc=dp[i-1]+0;

            dp[i]=max(inc,exc);
        }
        return dp[n-1];

    }
public:
    int rob(vector<int>& nums) {
        return tabusolve(nums);
    }
};
