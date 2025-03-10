// Day_09

// Problem 01 - Two sum(leetcode 1)
// https://leetcode.com/problems/two-sum/
// Code:-

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> num;
        for(int i=0; i<nums.size(); i++) {
            if(num.find((target - nums[i])) != num.end()) {
                return {num[target - nums[i]], i};
            }
            num[nums[i]] = i;
        }
        return {};
    }
};

// TC = O(N)
// SC = O(N)
// Approach : hash map, found element which sums up to ith element to give the target found its index and if its a two sum returned it and stored it in hash map.. else returned the empty vector..

// Problem 03 - Maximum Score for Subarray Minimums
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0
// Code:-

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        if(arr.size() < 2){return 0;}
        int maxScore = 0;
        
        for(int i = 0; i < arr.size()-1; i++){
            int curr = arr[i] + arr[i+1];
            maxScore = max(maxScore, curr);
        }
        
        return maxScore;
    }
};

// TC = O(N)
// SC = O(1)
// Approach:- array is iterated.. finding sum of adjacent elements and upadating maxScore each time and returned the maximum score at last..
