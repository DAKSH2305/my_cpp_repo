// solved by me - beats 100% 
// leetcode link - https://leetcode.com/problems/sort-colors/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            while(nums[i]==0 and i<j){
                i++;
            }
            while((nums[j]==1||nums[j]==2)&&i<j){
                j--;
            }
            if (i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        int k=0;
        int a=0;
        int l=nums.size()-1;
        while (a < nums.size() && nums[a] == 0){

            a++;
            k=k+1;

        }
         while(k<l){
            while(nums[k]==1 and k<l){
                k++;
            }
            while((nums[l]==2)&&k<l){
                l--;
            }
            if (k<l){
                swap(nums[k],nums[l]);
                k++;
                l--;
            }
        }
        
    }
};
