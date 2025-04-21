// question link - https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75
// not optimized 
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/



class Solution {

public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k==1){
            int temp=INT_MIN;

            for(int i=0;i<nums.size();i++){
                if (nums[i]>temp){
                    temp=nums[i];
                }
            }
            return temp;
        }
        double sum=0;
        
        int n=nums.size();
        int a=0;
        int b=k-1;
        
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
        }
        double ans=sum;       
    
        while(b<n-1){      
        
            sum=sum-nums[a]+nums[b+1];            
            ans=max(ans,sum);
            a++;
            b++;

        }
        return ans/k;
    }
};  
