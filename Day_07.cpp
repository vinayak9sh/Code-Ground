// Problem 01 --> Can Place Flowers(leetcode 605)
// https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=greedy
// Code:-

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i, countPlace = 0;
        if(n == 0){return true;}
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1){return true;}
        if(flowerbed.size() == 1 && flowerbed[0] == 1 && n == 1){return false;}
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            countPlace++;
        }
        for(i = 1; i < flowerbed.size() - 1; i++){
            if(flowerbed[i] == 0){
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    countPlace++;
                }
            }
        }
        if(flowerbed[flowerbed.size()-2]==0 && flowerbed[flowerbed.size()-1]==0){
            flowerbed[flowerbed.size()-1] = 1;
            countPlace++;
        }
        if(countPlace >= n){return true;}
        else{return false;}
    }
};

// Time Complexity = O(N)
// Space Complexity = O(1)

// approach : first I've started a loop which watch out for the spaces where flower can be placed. If such a place is found then, I've placed a flower there and examined increased the count variable
//            which holds the count for suitable places after flower is placed and the process is continued in same way. Furthermore, I've put some border conditions and some extra control statements
//            to handle some testcases.

// Problem 02 --> Minimum Positive Sum Subarray
// https://leetcode.com/problems/minimum-positive-sum-subarray/description/?envType=problem-list-v2&envId=prefix-sum
// Code:-

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        for(int len = l; len <= r; len++){
            int currentSum = 0;
            for(int i = 0; i < len; i++){
                currentSum += nums[i];
            }
            if(currentSum > 0){
                minSum = min(minSum, currentSum);
            }
            for(int i = len; i < nums.size(); i++){
                currentSum += nums[i] - nums[i-len];
                if(currentSum > 0){
                    minSum = min(minSum, currentSum);
                }
            }
        }
        if(minSum != INT_MAX){return minSum;}
        else{return -1;}
    }
};

// Time Complexity = O(N^2)(worst case)
// Space Complexity = O(1)

// Approach: First I was trying to do the problem my methods of vector of arrays I knew.. but it was able to make upto 8 testcases only. Then, I looked into topics mentioned about sliding window 
//           technique and then I learned the same by youTube.. then I applied the same.. here(in the code) outer for loop is changing the window size.. then firstly the sum of window is calculated 
//           in initial position then it is slided forward keeping track of current sum(to be > 0, as per question) and comparing it with minimum sum(minSum) each time and assigning the minSum to 
//           Minimum value of currentSum and minSum... following the testcases.. I got the solution.
