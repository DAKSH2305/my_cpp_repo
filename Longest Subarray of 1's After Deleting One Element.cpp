// leetcode 1493. Longest Subarray of 1's After Deleting One Element
/*
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75
tc - o(N)
SC - O(1)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, zeros = 0, maxLen = 0;
    
        while (right < nums.size()) {
            // If current element is 0, increment zero count
            if (nums[right] == 0) zeros++;

            // If we have more than k zeros, shrink window from the left
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // Update max length of the window
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen-1;
        
    }
        
    
};

/*
EXPLANATION - 
hum sliding window ka concpet use kar rhe hai . humne left and right pointer zero se initialize kiya tha . sath me number of zeros( zeros =0) bhi initialize kiya.
Then hum right side se window ko expand karenge , agar next element 1 hai to to aage badh jao , if  zero hai to zeros ++ kardo. next check karo ki zeros >k ( here k ==1) , agar yes 
then check karo nums[left] ==0 , if yes then window shrink kardo by left++ and zeros--. 
ab jab ek bar ye sab ho jay to max leght nikal lo  , curent lenght = right - left +1 .

ab yha last me return max len -1 likha hai kyuki is particular question me hume after deleting pucha hai rather than replacing.
*/
