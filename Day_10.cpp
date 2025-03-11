// Day_10

// Problem 01 : Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
// Code:-

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> reARRay(nums.size(), 0);
        int i = 0, j = 0, k = 1;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                reARRay[j] = nums[i];
                j += 2;
            }
            else{
                reARRay[k] = nums[i];
                k += 2;
            }
        }
        return reARRay;
    }
};

// TC = O(N)
// SC = O(N)
// Appproach : Through pointers to positive and negative integers tracing nums, positive and negative integers are stored in an additional array in same repeated order.. and additional array was returned.

// Problem 02 : Next Permutation 
// https://leetcode.com/problems/next-permutation/description/
// Code:-

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;

        while(i > 0 && nums[i] <= nums[i - 1]){i--;}
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (nums[j] <= nums[i - 1]) {
            j--;
        }
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};

// TC = O(N)
// SC = O(1)
// Approach: started from end found the first decreasing element then found smallest element from right greater than the first decreasing element then swapped them and reversed from there to the end.. 
//           if no such element found entire array is reversed..
