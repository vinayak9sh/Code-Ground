// Day_08
// Problem 01 : Move Zeroes(leetcode 283)
// https://leetcode.com/problems/move-zeroes/submissions/1568246195/
// Code:-

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[nonZero]);
                nonZero++;
            }
        }
    }
};

// TC = O(N)
// SC = O(1)

// Approach : Moved non-zero elements in front of array..
